#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// ����ʶ�� ///
/// </summary>

void main() {
	//��������ͷ
	VideoCapture cap(0);
	Mat img;

	//������������ѵ��ģ��
	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	if (plateCascade.empty())
	{
		cout << "XMLû�б�����" << endl;
	}

	//������������
	vector<Rect> plates;

	while (true) {
		cap.read(img);
		//����ʶ�𾫶�
		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			//��������ʶ�𵽵ĳ���
			Mat imgCrop = img(plates[i]);
			//�����ú�ĳ��Ʊ��浽����
			imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
			//�������������ʶ�𵽵ĳ���
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 255, 255), 3);
		}

		imshow("Image", img);
		waitKey(1);
	}
}