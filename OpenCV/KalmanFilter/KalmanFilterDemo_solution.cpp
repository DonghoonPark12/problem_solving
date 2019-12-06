// KalmanFilterDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2"
#include "highgui.h"


int _tmain(int argc, _TCHAR* argv[])
{

	// Initialize Kalman filter object, window, number generator, etc
	cvNamedWindow( "Kalman", 1 );
	CvRandState rng;
	cvRandInit( &rng, 0, 1, -1, CV_RAND_UNI );

	IplImage* img = cvCreateImage( cvSize(500,500), 8, 3 );
	CvKalman* kalman = cvCreateKalman( 2, 1, 0 );

	// State is phi, delta_phi - angle and angular velocity
	// Initialize with random guess
	CvMat* x_k = cvCreateMat( 2, 1, CV_32FC1 );
	cvRandSetRange( &rng, 0, 0.1, 0 );
	rng.disttype = CV_RAND_NORMAL;
	cvRand( &rng, x_k );

	// Process noise
	CvMat* w_k = cvCreateMat( 2, 1, CV_32FC1 );

	// Measurements, only one parameter for angle
	CvMat* z_k = cvCreateMat( 1, 1, CV_32FC1 );
	cvZero( z_k );

	// Transition matrix F describes model parameters at k and k+1
	const float F[] = { 1, 1, 0, 1 };
	memcpy( kalman->transition_matrix->data.fl, F, sizeof(F));

	// Initialize other Kalman parameters
	cvSetIdentity( kalman->measurement_matrix, cvRealScalar(1) );
	cvSetIdentity( kalman->process_noise_cov, cvRealScalar(1e-5) );
	cvSetIdentity( kalman->measurement_noise_cov, cvRealScalar(1e-2) );
	cvSetIdentity( kalman->error_cov_post, cvRealScalar(1) );

	// Choose random initial state
	cvRand( &rng, kalman->state_post );

	// Make colors
	CvScalar yellow = CV_RGB(255,255,0);
	CvScalar white = CV_RGB(255,255,255);
	CvScalar red = CV_RGB(255,0,0);

	while( 1 ){
		// Predict point position
		const CvMat* y_k = cvKalmanPredict( kalman, 0 );

		// Generate Measurement (z_k)
		cvRandSetRange( &rng, 0, sqrt( kalman->measurement_noise_cov->data.fl[0] ), 0 );			
		cvRand( &rng, z_k );
		cvMatMulAdd( kalman->measurement_matrix, x_k, z_k, z_k );

		// Plot Points
		cvZero( img );
		// Yellow is observed state
		cvCircle( img, 
			cvPoint( cvRound(img->width/2 + img->width/3*cos(z_k->data.fl[0])),
			cvRound( img->height/2 - img->width/3*sin(z_k->data.fl[0])) ), 
			4, yellow );
		// White is the predicted state via the filter
		cvCircle( img, 
			cvPoint( cvRound(img->width/2 + img->width/3*cos(y_k->data.fl[0])),
			cvRound( img->height/2 - img->width/3*sin(y_k->data.fl[0])) ), 
			4, white, 2 );
		// Red is the real state
		cvCircle( img, 
			cvPoint( cvRound(img->width/2 + img->width/3*cos(x_k->data.fl[0])),
			cvRound( img->height/2 - img->width/3*sin(x_k->data.fl[0])) ),
			4, red );
		cvShowImage( "Kalman", img );

		// Adjust Kalman filter state
		cvKalmanCorrect( kalman, z_k );

		// Apply the transition matrix F and apply "process noise" w_k
		cvRandSetRange( &rng, 0, sqrt( kalman->process_noise_cov->data.fl[0] ), 0 );
		cvRand( &rng, w_k );
		cvMatMulAdd( kalman->transition_matrix, x_k, w_k, x_k );

		// Exit on esc key
		if( cvWaitKey( 300 ) == 27 ) 
			break;
	}
	
	return 0;
}
