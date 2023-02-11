/*------------------------------------------------------------------------------------------*\
This file contains material supporting chapter 1 of the book:
OpenCV3 Computer Vision Application Programming Cookbook
Third Edition
by Robert Laganiere, Packt Publishing, 2016.

This program is free software; permission is hereby granted to use, copy, modify,
and distribute this source code, or portions thereof, for any purpose, without fee,
subject to the restriction that the copyright notice may not be removed
or altered from any source or altered source distribution.
The software is released on an as-is basis and without any warranties of any kind.
In particular, the software is not guaranteed to be fault-tolerant or free from failure.
The author disclaims all warranties with regard to this software, any use,
and any consequent failure, is purely the responsibility of the user.

Copyright (C) 2016 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {
    // code1
	// 创建图像
    cv::Mat image1(200,300,CV_8U, 100);    // 四个参数为：矩阵行数，矩阵列数，数据类型，初始值
    cv::Mat image2(200,300,CV_8U, cv::Scalar(0));    // 对于灰度图像：可以直接给出初始值，也可以使用Scalar（）  
	cv::Mat image3(200,300,CV_8UC3,cv::Scalar(0,0,255)); //对于三通道图像，创建一个红色的图像，通道顺序为BGR
	// or:
	// cv::Mat image3(cv::Size(320,240),CV_8UC3);
	// image2= cv::Scalar(0,0,255);

	cv::imshow("Image1", image1); // 显示图像
    cv::imshow("Image2", image2); // 显示图像
    cv::imshow("Image3", image3); // 显示图像
	cv::waitKey(0); // 等待按键

    // code2
	// 读取图像

    cv::Mat image4 = cv::imread("Audi_S7.jpg");
    cv::Mat image5 = cv::imread("Audi_S7.jpg", cv::IMREAD_GRAYSCALE);
    cv::namedWindow("Image4",0);//创建窗口
    cv::namedWindow("Image5",0);//创建窗口
    cv::imshow("Image4", image4); 
    
    cv::imshow("Image5", image5); 
	cv::waitKey(0); 

    // code3
	// 转换图像
    cv::Mat image6;
	cv::flip(image4,image6,1); 
    cv::namedWindow("Image6",0);//创建窗口
    cv::imshow("Image6", image6); 
	cv::waitKey(0);

    // code4
    // 图像的复制
	// 所有图像指向同一个数据块，会影响原数据块
	cv::Mat image7(image4);
	image7= image4;
	// 复制图像的副本，不会影响原数据
	cv::Mat image8= image4.clone();
	image8.copyTo(image4);
	// 复制图像，两者的数据类型不一定相同，转换为浮点型图像[0,1]
    cv::Mat image9;
	image4.convertTo(image9,CV_32F,1/255.0,0.0);

	// code5
    // 数组和向量
	// 创建3x3双精度型矩阵
	cv::Matx33d matrix(3.0, 2.0, 1.0,
		               2.0, 1.0, 3.0,
		               1.0, 2.0, 3.0);
	// 创建3x1双精度型矩阵（向量）
	cv::Matx31d vector(5.0, 1.0, 3.0);
	// 相乘
	cv::Matx31d result = matrix*vector;
	std::cout << result;
	cv::waitKey(0); 
	return 0;
}




