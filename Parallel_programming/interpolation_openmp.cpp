#include "interpolation.h"

int main()
{
	double ticks = cvGetTickFrequency()*10e6;
		
	Mat src = imread("Fig0441(a)(characters_test_pattern).png", 1); // read image
	src.convertTo(src, CV_32FC1);// 흑백으로 읽는다. 
	
	int hight = src.rows; //the hight of original image
	int width = src.cols; //the width of original iamge

	//왜 출력의 크기가 이렇게 되나?
	Mat out(hight * (scale + 1), width * (scale + 1), CV_32FC3, Scalar(0.0, 0.0, 0.0));// initialize the output image, according to scale and the hight and width of original image
																				       //Mat out_cubic_4(hight * (scale + 1), width * (scale + 1), CV_32FC3, Scalar(0.0, 0.0, 0.0));
	Mat out_openmp(hight * (scale + 1), width * (scale + 1), CV_32FC3, Scalar(0.0, 0.0, 0.0));
	Mat weight = calculateWeight(scale, method_ID); // W를 계산 

	int w_hight = weight.rows;
	int w_width = weight.cols;

	//Bilinear_2_interpolation(org, hight, o_width, weight, w_hight, w_width, out);
	
	// Serial code for interpolation
	int64 t0 = cvGetTickCount();// For check processing time
	for (int n = 0; n < times; n++)
	{
		interpolation_serial(src, hight, width, weight, w_hight, w_width, out);
	}
	t0 = cvGetTickCount() - t0;
	printf("Processing time of the serial code for interpolation: %.3f ms\n", 0.001*(double)t0 / ticks);
	
	
	// OpenMP code for interpolation
	int64 t1 = cvGetTickCount();;// For check processing time
	for (int n = 0; n < times; n++)
	{
		interpolation_OMP(src, hight, width, weight, w_hight, w_width, out_openmp);
	}
	t1 = cvGetTickCount() - t1;
	printf("Processing time of the OpenMP code for interpolation: %.3f ms\n", 0.001 * (double)t1 / ticks);
	
	// Find maxmum value in float matrix to normalize
	//double min_org, max_org;
	//minMaxLoc(org, &min_org, &max_org);
	//double min_interpolation, max_interpolation;
	//minMaxLoc(out, &min_interpolation, &max_interpolation);

	src.convertTo(src, CV_8UC3); //interger
	out.convertTo(out, CV_8UC3);
	out_openmp.convertTo(out_openmp, CV_8UC3);

	namedWindow("Original Image");
	imshow("Original Image", src);
	namedWindow("Interpolation using serial code", CV_WINDOW_NORMAL);
	imshow("Interpolation using serial code", out);
	namedWindow("Interpolation using OpenMP", CV_WINDOW_NORMAL);
	imshow("Interpolation using OpenMP", out_openmp);



	//// File Name
	string Sscale = to_string(scale);
	string Smethod_ID;
	switch (method_ID)
	{
	case 1:
		Smethod_ID = "Bilinear_r2_s";
		break;
	case 2:
		Smethod_ID = "Bi-cubic_r4_s";
		break;
	case 3:
		Smethod_ID = "Bi-cubic_r6_s";
		break;
	case 4:
		Smethod_ID = "Bi-cubic_r8_s";
		break;
	case 5:
		Smethod_ID = "Lagrange_r4_s";
		break;
	case 6:
		Smethod_ID = "B-spline_r4_s";
		break;
	}

	string Sfile_name = "../" + Smethod_ID + Sscale + ".png";
	// Parameters using in imwrite function
	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	// Write to memory for saving training data
	imwrite(Sfile_name, out, compression_params);

	waitKey(0);
	return 0;
}