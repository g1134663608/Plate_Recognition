#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// OpenCV基本功能实现 ///
/// </summary>

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; //声明各个类型图像变量

	cvtColor(img, imgGray, COLOR_BGR2GRAY); //对图像灰度处理
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0); //高斯模糊处理
	Canny(imgGray, imgCanny, 25, 75); //对图像进行Canny边缘检测
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel); //对边缘进行扩张
	erode(imgDil, imgErode, kernel); //对边缘进行收缩

	//打印各个类型图像
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
}