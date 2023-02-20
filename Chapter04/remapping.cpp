
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>

// 重映射图像，创建波浪效果
void wave(const cv::Mat &image, cv::Mat &result) {
    
    // 定义映射参数
	cv::Mat srcX(image.rows,image.cols,CV_32F); 
	cv::Mat srcY(image.rows,image.cols,CV_32F);

	// 创建映射参数
	for (int i=0; i<image.rows; i++) {
		for (int j=0; j<image.cols; j++) {
			srcX.at<float>(i,j)= j;
			srcY.at<float>(i,j)= i+8*sin(j/6.0);
			// horizontal flipping
			// srcX.at<float>(i,j)= image.cols-j-1;
			// srcY.at<float>(i,j)= i;
		}
	}

	cv::remap(image,  
		      result, 
			  srcX,   
			  srcY,   
			  cv::INTER_LINEAR);
}

int main()
{
	cv::Mat image= cv::imread("AUdi_A8.jpg");
	cv::namedWindow("Image",0);
	cv::imshow("Image",image);

	cv::Mat result;
	wave(image,result);
	cv::namedWindow("Image1",0);
	cv::imshow("Image1",result);
	cv::waitKey();
	return 0;
}


