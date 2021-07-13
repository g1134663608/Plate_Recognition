#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// OpenCV��������ʵ�� ///
/// </summary>

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; //������������ͼ�����

	cvtColor(img, imgGray, COLOR_BGR2GRAY); //��ͼ��Ҷȴ���
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0); //��˹ģ������
	Canny(imgGray, imgCanny, 25, 75); //��ͼ�����Canny��Ե���
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel); //�Ա�Ե��������
	erode(imgDil, imgErode, kernel); //�Ա�Ե��������

	//��ӡ��������ͼ��
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
}