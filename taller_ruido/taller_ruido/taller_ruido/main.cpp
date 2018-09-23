#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int MAX_KERNEL_LENGTH=31;

int main(){
	Mat img=imread("testB.png");
	namedWindow("taller_ruido", WINDOW_NORMAL);
	resizeWindow("taller_ruido", 250, 250);
	namedWindow("taller_ruido_blur", WINDOW_NORMAL);
	resizeWindow("taller_ruido_blur", 250, 250);
	namedWindow("taller_ruido_gaussian", WINDOW_NORMAL);
	resizeWindow("taller_ruido_gaussian", 250, 250);
	namedWindow("taller_ruido_bilateral", WINDOW_NORMAL);
	resizeWindow("taller_ruido_bilateral", 250, 250);
	namedWindow("taller_ruido_median", WINDOW_NORMAL);
	resizeWindow("taller_ruido_median", 250, 250);
	imshow("taller_ruido", img);
	Mat blurred, gaussian, bilateral, median;
	for(int i=1; i<MAX_KERNEL_LENGTH; i=i+2){
		//Blur
		blur(img, blurred, Size(i, i), Point(-1, -1));
		//Gaussian Blur
		GaussianBlur(img, gaussian, Size(i, i), 0, 0);
		//Bilateral Filter
		bilateralFilter(img, bilateral, i, i*2, i/2);
		//Median
		medianBlur(img, median, i);
	}
	imshow("taller_ruido_blur", blurred);
	imshow("taller_ruido_gaussian", gaussian);
	imshow("taller_ruido_bilateral", bilateral);
	imshow("taller_ruido_median", median);
	waitKey(0);
	return 0;
}