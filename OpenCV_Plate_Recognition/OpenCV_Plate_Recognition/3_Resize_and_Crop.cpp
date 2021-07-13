#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// 改变图像尺寸并剪裁图像 ///
/// </summary>

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	//cout << img.size() << endl;
	resize(img, imgResize, Size(),0.5,0.5); //改变图像大小

	Rect roi(210, 10, 300, 390); //设置剪裁图像位置
	imgCrop = img(roi);

	//打印改变后的图像和剪裁的图像
	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}