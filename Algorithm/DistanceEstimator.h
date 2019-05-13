#pragma once

using namespace cv;

namespace cv {
	class Rect {
	public:
		int height; //
		int y; //
	};
}

class DISTANCE_ESTIMATOR_PARAM {
public:
	int vanishing_point_y;
};

class DistanceEstimator_Cones {
private:
	int _vanishing_point_y;
	int distance_y;
public:
	void init(DISTANCE_ESTIMATOR_PARAM param);
	float computeDistance(cv::Rect obj);
};
