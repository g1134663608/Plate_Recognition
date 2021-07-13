#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// ʶ��ͼ������� ///
/// </summary>

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil,Mat img) {
	
	//���ô������������
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//Ѱ������
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < contours.size(); i++)
	{
		//���������״�����
		int area = contourArea(contours[i]);
		cout << area << endl;

		//ͨ��boundRect���������״������
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		String objectType;

		//����������й���
		if (area > 1000)
		{
			//���ö����Ϻ������������߻�
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			
			//������߻�����״���۵����
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			//���۵����ת��Ϊint��
			int objCor = (int)conPoly[i].size();

			//ͨ���۵�ĸ������жϴ���״�Ǿ��Σ������Σ������λ���Բ��
			if (objCor == 3) 
			{ 
				objectType = "Tri"; 
			}
			else if(objCor == 4) {

				//ͨ��bonudRect������ȡ��״�Ŀ�Ⱥ͸߶ȣ����бȽϻ�ñ�ֵ
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;

				//ͨ���жϱ�ֵ�ķ�Χ���жϴ˾����ǲ���������
				if (aspRatio>0.95 && aspRatio<1.05)
				{
					objectType = "Square";
				}
				else {
					objectType = "Rect";
				}
			}
			else if (objCor > 4) {
				objectType = "Circle";
			}

			//��������
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			
			//��ӡ�������ľ�����״
			putText(img, objectType, {boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
		}
	}
}

void main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	//ͼ��Ԥ����
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	Canny(imgGray, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	//���������״����
	getContours(imgDil,img);

	imshow("Image", img);
	waitKey(0);
}