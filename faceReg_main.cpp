#include <iostream>
#include <string>

#include "face_detector.h"

//#include "opencv2/opencv.hpp"
//#include "opencv2/highgui/highgui.hpp"


using namespace std;

int main(int argc, char*argv[])
{
	cout << "OpenCV version : " << CV_VERSION << endl;
	cout << "Major version : " << CV_MAJOR_VERSION << endl;
	cout << "Minor version : " << CV_MINOR_VERSION << endl;
	cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
	/*CommandLineParser parser(argc, argv,
		"{help h||}"
		"{face_cascade|data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
		"{eyes_cascade|data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
		"{camera|0|Camera device number.}");
	parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
		"You can use Haar or LBP features.\n\n");
	parser.printMessage();*/

	if (argc < 2) {
		std::cerr << "[ERROR]: Missing argument (./face_recognition <path_to_image>)";
		return 1;
	}
	
	// init detector
	FaceDetector myDetector;
	myDetector.loadImage(argv[1]);
	myDetector.loadCascade();

	myDetector.detectFace();
	myDetector.displayResult();

	//Mat image = imread("D:/bg/sad_pepe.png");
	//Size s = image.size();
	//// create and set the window name
	//namedWindow("ShowImage");
	//// show the image on window
	//imshow("ShowImage", image);
	//// close the window
	//waitKey(0);
	return 0;
}
