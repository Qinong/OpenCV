#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


void onMouse( int event, int x, int y, int flags, void* param)	{
	cv::Mat *im= reinterpret_cast<cv::Mat*>(param);
    switch (event) {    // 调度事件
		case cv::EVENT_LBUTTONDOWN: // 鼠标左键按下的事件
			// 显示鼠标点按下的像素值（x,y）
			std::cout << "at (" << x << "," << y << ") value is: " 
				      << static_cast<int>(im->at<uchar>(cv::Point(x,y))) << std::endl;
			break;
	}
}

int main() {
	// code1
    // 显示鼠标点击点的像素值
    cv::Mat image1 = cv::imread("Audi_RS7.jpg");
    if (image1.empty()) { 
		std::cout << "Error reading image..." << std::endl;
		return 0;
	}
    cv::namedWindow("Image1",0); 
	cv::imshow("Image1", image1); // show the image
	cv::waitKey(0); // 0 to indefinitely wait for a key pressed
	cv::setMouseCallback("Image1", onMouse, reinterpret_cast<void*>(&image1));
    
    // code2
    // 在图上画圆
    cv::Mat image2 = image1.clone();
 	cv::circle(image2,              // 目标图像
		       cv::Point(1500,2000), // 中心点坐标
			   500,                 // 半径
			   0,                  // 颜色
			   50);                 // 厚度
    cv::namedWindow("Image2",0);
	cv::imshow("Image2", image2); 
	cv::waitKey(0); 
	 
    // code3
    // 在图上写入文本
    cv::Mat image3 = image1.clone();
	cv::putText(image3,                   // destination image
		        "This is a Audi.",        // text
				cv::Point(1000,2500),       // text position
				cv::FONT_HERSHEY_PLAIN,  // font type
				20.0,                     // font scale
				255,                     // text color (here white)
				20);                      // text thickness
    cv::namedWindow("Image3",0);
	cv::imshow("Image3", image3); 
	cv::waitKey(0);   

    // code4
    // 方法1：图片插入logo
	cv::Mat image4 = image1.clone(); 
	cv::Mat logo=  cv::imread("Audi_logo.jpeg"); 
	// 在图像的右下角定义一个ROI
	cv::Mat imageROI(image4, 
		          cv::Rect(image4.cols-logo.cols, // ROI坐标
                           image4.rows-logo.rows,
		                   logo.cols,logo.rows));// ROI大小
	// 插入logo
	logo.copyTo(imageROI);
	cv::namedWindow("Image4",0); 
	cv::imshow("Image4", image4); 
	cv::waitKey(0);


    // code5
    // 方法2：图片插入logo
	cv::Mat image5 = image1.clone(); 
    cv::Mat logo1=  cv::imread("Audi_logo.jpeg",cv::IMREAD_GRAYSCALE); 
	// ROI用cv::Range描述
    imageROI= image5(cv::Range(image5.rows-logo.rows,image5.rows), 
                    cv::Range(image5.cols-logo.cols,image5.cols));

    // 用logo作为掩码（必须是灰度图像）
    cv::Mat mask(logo1);
	// 插入logo，只负责掩码不为0的位置
	logo.copyTo(imageROI,mask);
    cv::namedWindow("Image5",0);
	cv::imshow("Image5", image5); 
	cv::waitKey(0);
    
	return 0;
}



