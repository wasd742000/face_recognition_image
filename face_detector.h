#pragma once
#include <string>
#include "opencv2/opencv.hpp"
//#include "opencv2/highgui/highgui.hpp"

/*
Face detection method: using HaarCascade
OpenCV contained pretrained HaarCascade model for face detection
*/

#define HAAR_CASCADE_FACE_PATH "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml"

class FaceDetector
{
private:
	std::string _imagePath;
	cv::Mat _image;
	cv::CascadeClassifier _faceModel;
	std::vector<cv::Rect> _faces; // face position is store as a rectangle (identify by 2 points)
	
	void resizeImage(int maxWidth, int maxHeight);
public:
	int loadImage(std::string imagePath);
	bool loadCascade();
	int detectFace();
};

