#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	std::cout << "CV Version : " << CV_VERSION << std::endl;

	Mat img = ~imread("./lena.png");
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("Image");
	imshow("image", img);

	waitKey();

	return 0;
}
