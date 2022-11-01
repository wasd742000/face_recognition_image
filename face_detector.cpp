#include "face_detector.h"

int FaceDetector::loadImage(std::string imagePath) {
	/*
	1) check the file extension (currently support jpg, jpeg, png) 
	2) read image
	return 0: sucess
	return -1: invalid extension
	return -2: can not load image
	*/
	_imagePath = imagePath;
	
	std::string fileExtension;

	// get extension
	// if path contains ".", get extension behind "."
	if (imagePath.find_last_of(".") != std::string::npos) {
		fileExtension = imagePath.substr(imagePath.find_last_of(".") + 1);
	}

	// if the extension is valid 
	if (fileExtension == "jpg" || fileExtension == "jpeg" || fileExtension == "png")
	{
		_image = cv::imread(imagePath);
	}
	else {
		std::cerr << "[ERROR]: (only support png, jpg, jpeg file) Invalid file extension on " << imagePath << std::endl;
		return -1;
	}

	if (_image.empty()) {
		std::cerr << "[ERROR]: Failed to load image on " << imagePath << std::endl;
		return -2;
	}

	return 0;
}

bool FaceDetector::loadCascade() {
	/*
	Load Haar Cascade pretrained model for face detection
	return 0: if failed to load
	return 1: if success
	*/
	if (!_faceModel.load(HAAR_CASCADE_FACE_PATH)) {
		std::cerr << "[ERROR]: Failed to load Haar Cascade Face detector model from " << HAAR_CASCADE_FACE_PATH << std::endl;
		return 0;
	}
	return 1;
}

int FaceDetector::detectFace() {
	// convert image to gray scale
	cv::Mat imgGrayScale;
	cv::cvtColor(_image, imgGrayScale, cv::COLOR_BGR2GRAY);
	cv::equalizeHist(imgGrayScale, imgGrayScale); // equalize histogram for better detection

	// use loaded haar cascade model for face detection
	_faceModel.detectMultiScale(imgGrayScale, _faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(250, 250));

	return _faces.size(); // return number of faces detected
}

void FaceDetector::resizeImage(int maxWidth, int maxHeight) {

}
