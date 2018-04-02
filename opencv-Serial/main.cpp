#include<iostream>
#include"Serial.h"
#include <TCHAR.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;

CSerial serial;

void  serialInit() {
	serial.OpenSerialPort(_T("COM9:"), 9600, 8, 1);
}
void Send(char x) {
	serial.SendData(&x,1);
}



int main(int argc, char** argv) {
	//serialInit();
	//Mat src=imread("G:\\360Downloads\\Õº∆¨\\DIR75\\YX30ozsUXgAAYvIarTuuXQAA&amp;bo=ngL3AQAAAAABAE0!.jpg");
	VideoCapture cap("C:\\Users\\œÃ”„\\Desktop\\123.mp4");// open the default camera  
	
	Mat src;
	Mat grayImage;
	Mat binImage;
	Mat dilateImage;

	Mat element = getStructuringElement(MORPH_RECT, Size(2,2)); //≈Ú’Õ”√µΩ
	vector<vector<Point> > contours;//ÕºœÒ¬÷¿™
	cap >> src;
	while (!src.empty()) {
	
		cap >> src;
		src = imread("C:\\Users\\œÃ”„\\Pictures\\Camera Roll\\1.jpg");
	//	imwrite("D:\\123\\123.jpg", src);
		cvtColor(src, grayImage, CV_BGR2GRAY);
		threshold(grayImage, binImage, 50, 255, CV_THRESH_BINARY);

		dilate(binImage, dilateImage, element);

		findContours(dilateImage, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

		drawContours(src, contours, -1, Scalar(0, 0, 255),2);

	

		imshow("", src);
		src = NULL;
		 grayImage = NULL;
		 binImage = NULL;
		 dilateImage = NULL;

	//	Send('a');
	//	Send('b');
	//	Send('c');


		waitKey(1);
	}
	



	
	waitKey();




	char a;
	while (1) {
		cin >> a;
		Send(a);
	}
	return 0;
}