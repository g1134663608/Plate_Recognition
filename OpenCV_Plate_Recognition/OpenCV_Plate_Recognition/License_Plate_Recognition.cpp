#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// 车牌识别 ///
/// </summary>

void main() {
	//调用摄像头
	VideoCapture cap(0);
	Mat img;

	//创建级联加载训练模型
	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	if (plateCascade.empty())
	{
		cout << "XML没有被加载" << endl;
	}

	//创建车牌容器
	vector<Rect> plates;

	while (true) {
		cap.read(img);
		//设置识别精度
		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			//剪裁所有识别到的车牌
			Mat imgCrop = img(plates[i]);
			//将剪裁后的车牌保存到本地
			imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
			//创建矩形来标记识别到的车牌
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 255, 255), 3);
		}

		imshow("Image", img);
		waitKey(1);
	}
}