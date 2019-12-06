#ifndef INTERPOLATION
#define INTERPOLATION

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include <opencv\cv.h>
#include <opencv\cxcore.h>
#include <opencv2\ml\ml.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <omp.h>

using namespace cv;
using namespace std;

int relationship = 0; // the number of pixels we want to reference
int scale = 0.5;
int times = 10; // the number of interpolations
int method_ID = 6; // the name of the Interpolation Method,
				   //1:Bilinear interpolation
				   //2:Bi-cubic_4 interpolation
				   //3:Bi-cubic_6 interpolation
				   //4:Bi-cubic_8 interpolation
				   //5:Lagrange_4 interpolation
				   //6:B-spline interpolation

void interpolation_serial(Mat& org, int h, int w, Mat& weight, int x, int y, Mat& out);

void interpolation_OMP(Mat& org, int h, int w, Mat& weight, int x, int y, Mat& out_openmp);

float wcubic_4(float x);
float wcubic_6(float x);
float wcubic_8(float x);
float wlagra_4(float x);
float bspline_4(float x);

Mat calculateWeight(int scale, int method_ID)
{
	// select the number of pixels to inference according the method
	switch (method_ID)
	{
	case 1: // Bilinear interpolation
		relationship = 2;
		break;
	case 2: // Bi-cubic_4 interpolation
		relationship = 4;
		break;
	case 3: // Bi-cubic_6 interpolation
		relationship = 6;
		break;
	case 4: // Bi-cubic_8 interpolation
		relationship = 8;
		break;
	case 5: // Lagrange_4 interpolation
		relationship = 4;
		break;
	case 6: // B-spline interpolation
		relationship = 4;
	}

	Mat weight(scale, relationship, CV_32FC1, Scalar(0)); //  save weigth for interporation
	float n = 1.0;

	// generate weight matrix according to the method
	switch (method_ID)
	{
	case 1: // Bilinear interpolation, 쌍일차 보간법
		for (int i = 0; i < scale; i++)
		{
			weight.at<float>(i, 0) = n / (scale + 1);
			weight.at<float>(i, 1) = 1.0 - (n / (scale + 1));
			n++;
		}
		break;
	case 2: // Bi-cubic_4 interpolation, 쌍삼차 보간법 
		for (int i = 0; i < scale; i++)
		{
			for (int j = 0, k = 1; (j < relationship) && (k <= relationship); j++, k++)
			{
				float x = (relationship / 2 - k) + (n + i) / (scale + 1);
				float w = wcubic_4(x);
				weight.at<float>(i, j) = w;
			}
		}
		break;
	case 3: // Bi-cubic_6 interpolation
		for (int i = 0; i < scale; i++)
		{
			for (int j = 0, k = 1; (j < relationship) && (k <= relationship); j++, k++)
			{
				float x = (relationship / 2 - k) + (n + i) / (scale + 1);
				float w = wcubic_6(x);
				weight.at<float>(i, j) = w;
			}
		}
		break;
	case 4: // Bi-cubic_8 interpolation
		for (int i = 0; i < scale; i++)
		{
			for (int j = 0, k = 1; (j < relationship) && (k <= relationship); j++, k++)
			{
				float x = (relationship / 2 - k) + (n + i) / (scale + 1);
				float w = wcubic_8(x);
				weight.at<float>(i, j) = w;
			}
		}
		break;
	case 5: // Lagrange_4 interpolation
		for (int i = 0; i < scale; i++)
		{
			for (int j = 0, k = 1; (j < relationship) && (k <= relationship); j++, k++)
			{
				float x = (relationship / 2 - k) + (n + i) / (scale + 1);
				float w = wlagra_4(x);
				weight.at<float>(i, j) = w;
			}
		}
		break;
	case 6: // B-spline interpolation
		for (int i = 0; i < scale; i++)
		{
			for (int j = 0, k = 1; (j < relationship) && (k <= relationship); j++, k++)
			{
				float x = (relationship / 2 - k) + (n + i) / (scale + 1);
				float w = bspline_4(x);
				weight.at<float>(i, j) = w;
			}
		}
		break;
	}
	return weight;
}


float wcubic_4(float x) // equation of Wcubic_4
{
	float a = -0.5; // using in eautioni Wcubic_4
	float w;
	float x_abs = abs(x);

	if (x_abs >= 0 && x_abs < 1)
		w = (a + 2.0) * pow(x_abs, 3) - (a + 3.0) * pow(x_abs, 2) + 1;
	else if (x_abs >= 1 && x_abs < 2)
		w = a * pow(x_abs, 3) - 5.0 * a * pow(x_abs, 2) + 8.0 * a * x_abs - 4.0 * a;
	else
		w = 0;

	return w;
}

float wcubic_6(float x) // equation of Wcubic_6
{
	float w = 0;
	float x_abs = abs(x);

	if (x_abs >= 0 && x_abs < 1)
		w = (6.0 / 5.0) * pow(x_abs, 3) - (11.0 / 5.0) * pow(x_abs, 2) + 1.0;
	else if (x_abs >= 1 && x_abs < 2)
		w = -(3.0 / 5.0) * pow(x_abs, 3) + (16.0 / 5.0) * pow(x_abs, 2) - (27.0 / 5.0) * x_abs + (14.0 / 5.0);
	else if (x_abs >= 2 && x_abs < 3)
		w = (1.0 / 5.0) * pow(x_abs, 3) - (8.0 / 5.0) * pow(x_abs, 2) + (21.0 / 5.0) * x_abs - (18.0 / 5.0);
	else
		w = 0;

	return w;
}

float wcubic_8(float x) // equation of Wcubic_8
{
	float w = 0;
	float x_abs = abs(x);

	if (x_abs >= 0 && x_abs < 1)
		w = (67.0 / 56.0) * pow(x_abs, 3) - (123.0 / 56.0) * pow(x_abs, 2) + 1.0;
	else if (x_abs >= 1 && x_abs < 2)
		w = -(33.0 / 56.0) * pow(x_abs, 3) + (177.0 / 56.0) * pow(x_abs, 2) - (75.0 / 14.0) * x_abs + (39.0 / 14.0);
	else if (x_abs >= 2 && x_abs < 3)
		w = (9.0 / 56.0) * pow(x_abs, 3) - (75.0 / 56.0) * pow(x_abs, 2) + (51.0 / 14.0) * x_abs - (45.0 / 14.0);
	else if (x_abs >= 3 && x_abs < 4)
		w = -(3.0 / 56.0) * pow(x_abs, 3) + (33.0 / 56.0) * pow(x_abs, 2) - (15.0 / 7.0) * x_abs + (18.0 / 7.0);
	else
		w = 0;

	return w;
}

float wlagra_4(float x)
{
	float w = 0;
	float x_abs = abs(x);

	if (x_abs >= 0 && x_abs < 1)
		w = (1.0 / 2.0) * pow(x_abs, 3) - pow(x_abs, 2) - (1.0 / 2.0) * pow(x_abs, 1) + 1.0;
	else if (x_abs >= 1 && x_abs < 2)
		w = -(1.0 / 6.0) * pow(x_abs, 3) + pow(x_abs, 2) - (11.0 / 6.0) * pow(x_abs, 1) + 1.0;
	else
		w = 0;

	return w;
}

float bspline_4(float x)
{
	float w = 0;
	float x_abs = abs(x);

	if (x_abs >= 0 && x_abs < 1)
		w = (1.0 / 2.0) * pow(x_abs, 3) - pow(x_abs, 2) + 2.0 / 3.0;
	else if (x_abs >= 1 && x_abs < 2)
		w = -(1.0 / 6.0) * pow(x_abs, 3) + pow(x_abs, 2) - 2.0 * x_abs + 4.0 / 3.0;
	else
		w = 0;

	return w;
}


void interpolation_serial(Mat& org, int h, int w, Mat& weight, int x, int y, Mat& out)
{
	vector<Mat> channels(3);
	split(org, channels); // split original 3 channels
	Mat org_ch1 = channels[0];
	Mat org_ch2 = channels[1];
	Mat org_ch3 = channels[2];
	Mat out_ch1(h*(scale + 1), w*(scale + 1), CV_32FC1, Scalar(0.0));
	Mat out_ch2(h*(scale + 1), w*(scale + 1), CV_32FC1, Scalar(0.0));
	Mat out_ch3(h*(scale + 1), w*(scale + 1), CV_32FC1, Scalar(0.0));

	// for B channel
	// first interpolate rows
	for (int i = 0; i < (scale + 1) * h; i = i + scale + 1)
	{
		for (int j = 0; j < (scale + 1) * w; j++)
		{
			if (i == 396 && j == 599)
				Mat aaa;

			if (i % (scale + 1) == 0 && (j % (scale + 1) == 0)) // the pixel in the original image
				out_ch1.at<float>(i, j) = org_ch1.at<float>(i / (scale + 1), j / (scale + 1));
			else if (i % (scale + 1) == 0 && j < (relationship / 2 - 1) * (scale + 1))
			{
				out_ch1.at<float>(i, j) = out_ch1.at<float>(i, j - j % (scale + 1));
			}
			else if (j < (scale + 1) * (w - relationship / 2)) // interpolationed pixles
			{
				for (int k = 0; k < relationship; k++)
				{
					out_ch1.at<float>(i, j) = out_ch1.at<float>(i, j) +
						org_ch1.at<float>(i / (scale + 1), j / (scale + 1) + (k - (relationship / 2 - 1)))
						* weight.at<float>((j - 1) % (scale + 1), k);
				}
			}
			else // pixels on the right boundary just copy the boundary pixel on the original image
				out_ch1.at<float>(i, j) = org_ch1.at<float>(i / (scale + 1), j / (scale + 1));
		}
	}

	// second interpolate columns
	for (int i = 0; i < (scale + 1) * h; i++)
	{
		for (int j = 0; j < (scale + 1) * w; j++)
		{
			if (i % (scale + 1) == 0)
				break;
			else if (i < (scale + 1) * (relationship / 2 - 1))
			{
				out_ch1.at<float>(i, j) = out_ch1.at<float>(i - i % (scale + 1), j);
			}
			else if (i < (scale + 1) * (h - relationship / 2))
			{
				for (int k = 0; k < relationship; k++)
				{
					out_ch1.at<float>(i, j) = out_ch1.at<float>(i, j) +
						out_ch1.at<float>(i - i % (scale + 1) - (relationship / 2 - 1 - k) * (scale + 1), j)
						* weight.at<float>((i - 1) % (scale + 1), k);
				}
			}
			else
				out_ch1.at<float>(i, j) = out_ch1.at<float>(i - i % (scale + 1), j);
		}
	}

	// for G channel
	// first interpolate rows
	for (int i = 0; i < (scale + 1) * h; i = i + scale + 1)
	{
		for (int j = 0; j < (scale + 1) * w; j++)
		{
			if (i == 396 && j == 599)
				Mat aaa;

			if (i % (scale + 1) == 0 && (j % (scale + 1) == 0)) // the pixel in the original image
				out_ch2.at<float>(i, j) = org_ch2.at<float>(i / (scale + 1), j / (scale + 1));
			else if (i % (scale + 1) == 0 && j < (relationship / 2 - 1) * (scale + 1))
			{
				out_ch2.at<float>(i, j) = out_ch2.at<float>(i, j - j % (scale + 1));
			}
			else if (j < (scale + 1) * (w - relationship / 2)) // interpolationed pixles
			{
				for (int k = 0; k < relationship; k++)
				{
					out_ch2.at<float>(i, j) = out_ch2.at<float>(i, j) +
						org_ch2.at<float>(i / (scale + 1), j / (scale + 1) + (k - (relationship / 2 - 1)))
						* weight.at<float>((j - 1) % (scale + 1), k);
				}
			}
			else // pixels on the right boundary just copy the boundary pixel on the original image
				out_ch2.at<float>(i, j) = org_ch2.at<float>(i / (scale + 1), j / (scale + 1));
		}
	}

	// second interpolate columns
	for (int i = 0; i < (scale + 1) * h; i++)
	{
		for (int j = 0; j < (scale + 1) * w; j++)
		{
			if (i % (scale + 1) == 0)
				break;
			else if (i < (scale + 1) * (relationship / 2 - 1))
			{
				out_ch2.at<float>(i, j) = out_ch2.at<float>(i - i % (scale + 1), j);
			}
			else if (i < (scale + 1) * (h - relationship / 2))
			{
				for (int k = 0; k < relationship; k++)
				{
					out_ch2.at<float>(i, j) = out_ch2.at<float>(i, j) +
						out_ch2.at<float>(i - i % (scale + 1) - (relationship / 2 - 1 - k) * (scale + 1), j)
						* weight.at<float>((i - 1) % (scale + 1), k);
				}
			}
			else
				out_ch2.at<float>(i, j) = out_ch2.at<float>(i - i % (scale + 1), j);
		}
	}

	// for R channel
	// first interpolate rows
	for (int i = 0; i < (scale + 1) * h; i = i + scale + 1)
	{
		for (int j = 0; j < (scale + 1) * w; j++)
		{
			if (i == 396 && j == 599)
				Mat aaa;

			if (i % (scale + 1) == 0 && (j % (scale + 1) == 0)) // the pixel in the original image
				out_ch3.at<float>(i, j) = org_ch3.at<float>(i / (scale + 1), j / (scale + 1));
			else if (i % (scale + 1) == 0 && j < (relationship / 2 - 1) * (scale + 1))
			{
				out_ch3.at<float>(i, j) = out_ch3.at<float>(i, j - j % (scale + 1));
			}
			else if (j < (scale + 1) * (w - relationship / 2)) // interpolationed pixles
			{
				for (int k = 0; k < relationship; k++)
				{
					out_ch3.at<float>(i, j) = out_ch3.at<float>(i, j) +
						org_ch3.at<float>(i / (scale + 1), j / (scale + 1) + (k - (relationship / 2 - 1)))
						* weight.at<float>((j - 1) % (scale + 1), k);
				}
			}
			else // pixels on the right boundary just copy the boundary pixel on the original image
				out_ch3.at<float>(i, j) = org_ch3.at<float>(i / (scale + 1), j / (scale + 1));
		}
	}

	// second interpolate columns
	for (int i = 0; i < (scale + 1) * h; i++)
	{
		for (int j = 0; j < (scale + 1) * w; j++)
		{
			if (i % (scale + 1) == 0)
				break;
			else if (i < (scale + 1) * (relationship / 2 - 1))
			{
				out_ch3.at<float>(i, j) = out_ch3.at<float>(i - i % (scale + 1), j);
			}
			else if (i < (scale + 1) * (h - relationship / 2))
			{
				for (int k = 0; k < relationship; k++)
				{
					out_ch3.at<float>(i, j) = out_ch3.at<float>(i, j) +
						out_ch3.at<float>(i - i % (scale + 1) - (relationship / 2 - 1 - k) * (scale + 1), j)
						* weight.at<float>((i - 1) % (scale + 1), k);
				}
			}
			else
				out_ch3.at<float>(i, j) = out_ch3.at<float>(i - i % (scale + 1), j);
		}
	}

	vector<Mat> out_channels;
	out_channels.push_back(out_ch1);
	out_channels.push_back(out_ch2);
	out_channels.push_back(out_ch3);
	merge(out_channels, out);

	Mat aaa = out;
}

void interpolation_OMP(Mat& org, int h, int w, Mat& weight, int x, int y, Mat& out_openmp)
{
	int part_h = floor(h / 8); //h를 8등분 함 
	int residue = h - 7 * part_h; //8번째 부분

	Mat data1(org, Rect(0,                                 0, w, part_h + (relationship / 2)));
	Mat data2(org, Rect(0, 1 * part_h - ((relationship / 2)), w, part_h + (relationship / 2)));
	Mat data3(org, Rect(0, 2 * part_h - (relationship / 2), w, part_h + (relationship / 2)));
	Mat data4(org, Rect(0, 3 * part_h - (relationship / 2), w, part_h + (relationship / 2)));
	Mat data5(org, Rect(0, 4 * part_h - (relationship / 2), w, part_h + (relationship / 2)));
	Mat data6(org, Rect(0, 5 * part_h - (relationship / 2), w, part_h + (relationship / 2)));
	Mat data7(org, Rect(0, 6 * part_h - (relationship / 2), w, part_h + (relationship / 2)));
	Mat data8(org, Rect(0, 7 * part_h - (relationship / 2), w, residue + (relationship / 2)));
	Mat out1, out2, out3, out4, out5, out6, out7, out8;

#pragma omp parallel
	{
#pragma omp sections //스레드의 갯수 만큼 나눔
		{
#pragma omp section
			interpolation_serial(data1, data1.rows, data2.cols, weight, x, y, out1);
#pragma omp section
			interpolation_serial(data2, data1.rows, data2.cols, weight, x, y, out2);
#pragma omp section
			interpolation_serial(data3, data1.rows, data2.cols, weight, x, y, out3);
#pragma omp section
			interpolation_serial(data4, data1.rows, data2.cols, weight, x, y, out4);
#pragma omp section
			interpolation_serial(data5, data1.rows, data2.cols, weight, x, y, out5);
#pragma omp section
			interpolation_serial(data6, data1.rows, data2.cols, weight, x, y, out6);
#pragma omp section
			interpolation_serial(data7, data1.rows, data2.cols, weight, x, y, out7);
#pragma omp section
			interpolation_serial(data8, data1.rows, data2.cols, weight, x, y, out8);
		}
	}

	Mat data1_roi(out1, Rect(0, 0, (scale + 1) * w, (scale + 1) * part_h));
	Mat data2_roi(out2, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * part_h));
	Mat data3_roi(out3, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * part_h));
	Mat data4_roi(out4, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * part_h));
	Mat data5_roi(out5, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * part_h));
	Mat data6_roi(out6, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * part_h));
	Mat data7_roi(out7, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * part_h));
	Mat data8_roi(out8, Rect(0, (relationship / 2) * (scale + 1), (scale + 1) * w, (scale + 1) * residue));
	Mat temporary;

	vconcat(data1_roi, data2_roi, temporary);
	vconcat(temporary, data3_roi, temporary);
	vconcat(temporary, data4_roi, temporary);
	vconcat(temporary, data5_roi, temporary);
	vconcat(temporary, data6_roi, temporary);
	vconcat(temporary, data7_roi, temporary);
	vconcat(temporary, data8_roi, temporary);

	temporary.copyTo(out_openmp);
}

#endif
