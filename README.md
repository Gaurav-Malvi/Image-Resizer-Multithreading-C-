# Image Resizer Using Multithreading

- This mini project resizes images based on the given height and width using OpenCV.

- Processing each image serially takes a significant amount of time.

- To improve performance, I created 4 threads that run in parallel, dividing the work among them, which helps reduce latency.

- I tested this project by processing 3,000 images both with and without multithreading.


## RESULTS!

#### With Mutithreading
![with_threading](https://github.com/user-attachments/assets/26ba4b87-bf60-4453-8f50-174a93f9daf2)

#### Without Mutithreading
![no_threading](https://github.com/user-attachments/assets/0783ca17-fe23-40da-8d41-e70571a74aaf)


## TOOLS USED

##### MingW 8.1.0
##### OpenCV 3.4.13
##### CMake 3.31.0
