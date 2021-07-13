#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// 输出图像和视频 ///
/// </summary>

//void main() {
//	string path = "Resources/test.png"; //获取图片路径
//	Mat img = imread(path); //创建img对象
//	imshow("Image", img); //打印img
//	waitKey(0); 
//}

/// <summary>
/// 输出视频 
/// </summary>

//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path); //创建获取视频对象
//	Mat img;
//	while (true) {
//		cap.read(img); //读取视频
//		imshow("Image", img); //输出视频
//		waitKey(20); //增加延迟，保证视频正常输出
//	}
	
//}

/// <summary>
/// 调用摄像头 
/// </summary>

void main() {

	VideoCapture cap(0); //获取第一个摄像头编号
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(20);
	}
	
}