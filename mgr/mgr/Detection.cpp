#include "Detection.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

// overloaded constructor
Detection::Detection(){
}
void Detection::DeltaDetection(const Mat& src, Mat& dst){
	int cols = src.cols;
	int rows = src.rows;
	int licznik = 0;
	std::vector<int> listaX;
	std::vector<int> listaY;
	dst = src.clone();
	cvtColor(dst, dst, COLOR_GRAY2RGB);


	for (int i = 10; i < rows - 10; i++)
	{
		for (int j = 55; j < cols - 20; ++j)
		{

			if (src.at<uchar>(i, j) == 255)
			{
				if (src.at<uchar>(i - 1, j - 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i - 1, j) == 255){
					licznik++;
				}
				if (src.at<uchar>(i - 1, j + 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i, j - 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i, j + 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i + 1, j - 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i + 1, j) == 255){
					licznik++;
				}
				if (src.at<uchar>(i + 1, j + 1) == 255){
					licznik++;
				}

			}
			if (licznik == 3){
				
				int pomoc=0;
				listaX.push_back(j);
				listaY.push_back(i);
				for (int i = 0; i < listaX.size()-1; i++){
					if ((listaX[listaX.size() - 1]>listaX[i] - 10) && (listaX[listaX.size() - 1]<listaX[i] + 10) && (listaY[listaY.size() - 1]>listaY[i] - 10) && (listaY[listaY.size() - 1] < listaY[i] + 10))
					{	
						pomoc = 1;
						std::cout << "kurwa" << std::endl;
					}
					else
					{
						
					}
				}
				if (pomoc==0)
				{
					circle(dst, Point(j, i), 5, Scalar(0, 0, 255), 1, 8, 0);
					std::cout << "wykryto delte: pkt: " << i << " ," << j << std::endl;
				}
			}
			licznik = 0;
		}
	}
}

void Detection::EndingDetection(const Mat& src, Mat& dst){
	int cols = src.cols;
	int rows = src.rows;
	int licznik = 0;
	dst = src.clone();
	cvtColor(dst, dst, COLOR_GRAY2RGB);


	for (int i = 10; i < rows - 10; i++)
	{
		for (int j = 55; j < cols - 20; ++j)
		{

			if (src.at<uchar>(i, j) == 255)
			{
				if (src.at<uchar>(i - 1, j - 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i - 1, j) == 255){
					licznik++;
				}
				if (src.at<uchar>(i - 1, j + 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i, j - 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i, j + 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i + 1, j - 1) == 255){
					licznik++;
				}
				if (src.at<uchar>(i + 1, j) == 255){
					licznik++;
				}
				if (src.at<uchar>(i + 1, j + 1) == 255){
					licznik++;
				}

			}
			if (licznik == 1){
				circle(dst, Point(j, i), 5, Scalar(255, 0, 255), 1, 8, 0);
				std::cout << "wykryto zakonczenie: pkt: " << i << " ," << j << std::endl;
			}
			licznik = 0;
		}
	}
}

Detection::~Detection(){
}