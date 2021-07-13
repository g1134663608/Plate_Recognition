#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// 识别图像的轮廓 ///
/// </summary>

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil,Mat img) {
	
	//设置存放向量的容器
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//寻找向量
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < contours.size(); i++)
	{
		//获得所有形状的面积
		int area = contourArea(contours[i]);
		cout << area << endl;

		//通过boundRect函数获得形状的轮廓
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		String objectType;

		//根据面积进行过滤
		if (area > 1000)
		{
			//利用多边拟合函数把曲线折线化
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			
			//输出折线化后形状的折点个数
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			//把折点个数转化为int型
			int objCor = (int)conPoly[i].size();

			//通过折点的个数来判断此形状是矩形，正方形，三角形还是圆形
			if (objCor == 3) 
			{ 
				objectType = "Tri"; 
			}
			else if(objCor == 4) {

				//通过bonudRect函数获取形状的宽度和高度，进行比较获得比值
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;

				//通过判断比值的范围来判断此矩形是不是正方形
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

			//绘制折线
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			
			//打印此轮廓的具体形状
			putText(img, objectType, {boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
		}
	}
}

void main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	//图像预处理
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	Canny(imgGray, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	//获得轮廓形状函数
	getContours(imgDil,img);

	imshow("Image", img);
	waitKey(0);
}