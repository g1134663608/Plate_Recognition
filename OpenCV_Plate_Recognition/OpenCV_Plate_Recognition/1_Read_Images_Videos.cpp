#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// ���ͼ�����Ƶ ///
/// </summary>

//void main() {
//	string path = "Resources/test.png"; //��ȡͼƬ·��
//	Mat img = imread(path); //����img����
//	imshow("Image", img); //��ӡimg
//	waitKey(0); 
//}

/// <summary>
/// �����Ƶ 
/// </summary>

//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path); //������ȡ��Ƶ����
//	Mat img;
//	while (true) {
//		cap.read(img); //��ȡ��Ƶ
//		imshow("Image", img); //�����Ƶ
//		waitKey(20); //�����ӳ٣���֤��Ƶ�������
//	}
	
//}

/// <summary>
/// ��������ͷ 
/// </summary>

void main() {

	VideoCapture cap(0); //��ȡ��һ������ͷ���
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(20);
	}
	
}