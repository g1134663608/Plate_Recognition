#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// 绘制形状并添加文本 ///
/// </summary>

void main() {
	//创建空白图像
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	//创建圆形，矩形，线等图像
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	//创建文本
	putText(img, "hello world", Point(137, 262), FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 69, 255), 2);

	imshow("Image", img);
	
	waitKey(0);
}