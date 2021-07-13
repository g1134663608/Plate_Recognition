#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// ͼ����� ///
/// </summary>

float w = 250, h = 350;
Mat matrix, imgWrap;

void main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	//��ȡҪ����ͼ���ĸ��ǵ�����
	Point2f src[4] = { {65,323},{338,279},{91,634},{401,573} };

	//�µ�ͼ����ĸ�����
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	//��ͼ����ĸ��Ǳ�ת�����µ�ͼ��
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWrap, matrix, Point(w, h));

	//��ӡ
	imshow("Image", img);
	imshow("Image Wrap", imgWrap);
	waitKey(0);
}