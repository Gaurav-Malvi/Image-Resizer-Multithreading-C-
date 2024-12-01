# Image Resizer Using Multithreading

- This mini project resizes images based on the given height and width using OpenCV.

- Processing each image serially takes a significant amount of time.

- To improve performance, I created 4 threads that run in parallel, dividing the work among them, which helps reduce latency.

- I tested this project by processing 3,000 images both with and without multithreading.


## RESULTS!

#### With Mutithreading
![wt](https://github.com/user-attachments/assets/6b0621b9-002f-4886-aa78-796360c624e0)


#### Without Mutithreading
![nt](https://github.com/user-attachments/assets/7dbde2c7-4082-454a-93c4-7d4282612612)


## TOOLS USED

##### MingW 8.1.0
##### OpenCV 3.4.13
##### CMake 3.31.0
