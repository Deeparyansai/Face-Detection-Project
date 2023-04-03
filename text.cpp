#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
#include<stdlib.h>

using namespace std;
using namespace cv;

///  images  ///  
/*
void main() {
	string path = "resources/triplets-4744400_1920.jpg";
	Mat	img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}
*/

///  videos   /// 
/*
void main() {
	string path = "resources/Christmas - 141964.mp4";
	VideoCapture video(path);
	Mat img;

	while (true) {
		video.read(img);
		imshow("Frame", img);
		waitKey(20);
	}
}
*/

///  webcam   /// 

void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	facedetect.load("haarcascade_frontalface_default.xml");
	Mat img;

	while (true) {
		video.read(img);

		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
			putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
		}

		imshow("Frame", img);
		waitKey(1);
	}
}

