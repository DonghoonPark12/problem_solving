// Using cones to calculate distance
#include "DistanceEstimator.h"
using namespace std;
using namespace cv;

#define NUM_OF_CONES 11

void DistanceEstimator_Cones::init(DISTANCE_ESTIMATOR_PARAM param)
{
	_vanishing_point_y = param.vanishing_point_y;
}

float DistanceEstimator_Cones::computeDistance(cv::Rect object)
{
	// Calibration - Soul Mono Cam (2018.05.24)
	//int CONES_COOR_Y[NUM_OF_CONES] = { 720, 693 - 28,  527 - 28, 486 - 28, 465 - 28,  452 - 28,   446 - 28,   440 - 28,   437 - 28,   434 - 28,   432 - 28 };
	int CONES_COOR_Y_120[NUM_OF_CONES] = { 720, 693 - 28,  527 - 28, 486 - 28, 465 - 28,  452 - 28,   446 - 28,   440 - 28,   437 - 28,   434 - 28,   432 - 28 };
	int CONES_COOR_Y_190[NUM_OF_CONES] = { 720, 693 - 28,  527 - 28, 486 - 28, 465 - 28,  452 - 28,   446 - 28,   440 - 28,   437 - 28,   434 - 28,   432 - 28 };

	float CONES_LONGIT_POS[NUM_OF_CONES] = { 0, 5, 15,  25,  35,  45,  55,  65,  75,  85,  95 };

	int yCoorDiff[NUM_OF_CONES];
	float factor[NUM_OF_CONES];

	// Calculate y_coor difference compared to bonnet line
	int yCoorDiff_value = (object.y + object.height) - _vanishing_point_y;// 픽셀 거리  

	for (int i = 0; i < NUM_OF_CONES; i++) {
		yCoorDiff[i] = CONES_COOR_Y[i] - _vanishing_point_y; //내림 차순으로 배열 생성
	}

	// Calculate distance
	float distance_y = -1;
	for (int i = 0; i < NUM_OF_CONES - 1; i++) {

		if ((yCoorDiff_value <= yCoorDiff[i]) && (yCoorDiff_value >= yCoorDiff[i + 1])) {

			// linear interpolation
			float a = float(CONES_LONGIT_POS[i] - CONES_LONGIT_POS[i + 1]) / (yCoorDiff[i] - yCoorDiff[i + 1]);
			float b = CONES_LONGIT_POS[i] - a * yCoorDiff[i];

			distance_y = a*yCoorDiff_value + b;
		}

		else if (yCoorDiff_value <= yCoorDiff[NUM_OF_CONES - 1]) { //가장 마지막  배열 원소 즉, 95m보다 멀 경우
			distance_y = 100.0f; //거리는 100m로 본다. 
		}
	}

	return distance_y;
}

int main() {
	class cv::Rect obj;

}
