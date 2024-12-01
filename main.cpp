#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <chrono>  

using namespace std;
using namespace cv;
using namespace chrono;  

void stores_imgpaths_in_vector(vector<string>& imgPaths) {
    string fileName = "images_path.txt";
    ifstream file(fileName);
    
    if (!file.is_open()) {
        cout << "Error: Could not open the file!" << endl;
        return;
    }
    string path;

    while (getline(file, path)) {
        imgPaths.push_back(path);
    }

    file.close();
}

class ProcessImage {
public:
    Mat resizeImage(int w, int h, string imagepath) {
        Mat image = imread(imagepath);
        Mat resizedImage;
        resize(image, resizedImage, Size(w, h));
        return resizedImage;
    }
};

void helper(vector<string>& imgPaths, int start, int end, int w, int h, ProcessImage& pI) {
    for (int i = start; i <= end; i++) {
        Mat outputImage = pI.resizeImage(w, h, imgPaths[i]);
        string outputPath = "./output/" + to_string(i) + ".jpg";
        imwrite(outputPath, outputImage);
    }
}

int main() {
    vector<string> imgPaths;
    int w = 600;  
    int h = 600;  
    int numThreads = 4;  
    vector<thread> threads;  


    stores_imgpaths_in_vector(imgPaths);
    
    int sub_section_size = imgPaths.size() / numThreads;
    int start = 0;
    ProcessImage pI;

    auto start_time = high_resolution_clock::now();

    for (int i = 0; i < numThreads; i++) {
        int end = (i == numThreads - 1) ? imgPaths.size() - 1 : start + sub_section_size - 1;
        threads.push_back(thread(helper, ref(imgPaths), start, end, w, h, ref(pI)));
        start = end + 1;
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end_time - start_time);
    cout << "Time taken to process all images (THREADING): " << duration.count() << " seconds." << endl;

    return 0;
}
