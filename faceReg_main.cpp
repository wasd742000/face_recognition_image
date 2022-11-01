#include <iostream>
#include <string>

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace cv;

int main(int argc, char*argv[])
{
	/*CommandLineParser parser(argc, argv,
		"{help h||}"
		"{face_cascade|data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
		"{eyes_cascade|data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
		"{camera|0|Camera device number.}");
	parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
		"You can use Haar or LBP features.\n\n");
	parser.printMessage();*/

	/*std::cout << "argc = " <<	argc << std::endl;
	for (int i =0; i < argc; i++)
		std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
	

	if (argc < 2) {
		std::cerr << "[ERROR]: Missing argument (./face_recognition <path_to_image>)";
	}*/
	

	/*std::string path = "D:/bg/sad_pepe.png";
	std::cout << path.find_last_of("C") << std::endl;
	std::cout << (std::string::npos) << std::endl;
	std::string type = path.substr(path.find_last_of("/")+1, (path.find_last_of(".") - path.find_last_of("/") - 1));
	std::cout << type << std::endl;*/
	
	// read the input image from file
	//Mat image = imread(argv[1]);
	//// create and set the window name
	//namedWindow("ShowImage");
	//// show the image on window
	//imshow("ShowImage", image);
	//// close the window
	//waitKey(0);
	return 0;
}
