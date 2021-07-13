#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// �ı�ͼ��ߴ粢����ͼ�� ///
/// </summary>

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	//cout << img.size() << endl;
	resize(img, imgResize, Size(),0.5,0.5); //�ı�ͼ���С

	Rect roi(210, 10, 300, 390); //���ü���ͼ��λ��
	imgCrop = img(roi);

	//��ӡ�ı���ͼ��ͼ��õ�ͼ��
	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}