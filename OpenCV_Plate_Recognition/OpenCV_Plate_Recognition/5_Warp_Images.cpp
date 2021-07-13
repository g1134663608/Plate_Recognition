#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// 图像变形 ///
/// </summary>

float w = 250, h = 350;
Mat matrix, imgWrap;

void main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	//获取要变形图像四个角的坐标
	Point2f src[4] = { {65,323},{338,279},{91,634},{401,573} };

	//新的图像的四个坐标
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	//将图像的四个角标转化到新的图像
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWrap, matrix, Point(w, h));

	//打印
	imshow("Image", img);
	imshow("Image Wrap", imgWrap);
	waitKey(0);
}