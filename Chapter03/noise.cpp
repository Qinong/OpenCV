#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <random>

// 对图像添加白噪声
void salt(cv::Mat image, int n) {

	// C++11随机数生成器
	std::default_random_engine generator;
	std::uniform_int_distribution<int> randomRow(0, image.rows - 1);
	std::uniform_int_distribution<int> randomCol(0, image.cols - 1);

	int i,j;
	for (int k=0; k<n; k++) {

		// 随机生成图形位置
		i= randomCol(generator);
		j= randomRow(generator);
 
		if (image.type() == CV_8UC1)    // 灰度图像
        { 
			image.at<uchar>(j,i)= 255; 

		} 
		else if (image.type() == CV_8UC3)    // 彩色图像
        { 
			image.at<cv::Vec3b>(j,i)[0]= 255; 
			image.at<cv::Vec3b>(j,i)[1]= 255; 
			image.at<cv::Vec3b>(j,i)[2]= 255; 
			// or
			// image.at<cv::Vec3b>(j, i) = cv::Vec3b(255, 255, 255);
		}
	}
}


int main()
{
	cv::Mat image1 = cv::imread("Ferrar_F8.png",1);
    cv::Mat image2 =  image1.clone();
    cv::namedWindow("Image1");
	cv::imshow("Image1",image1);
	
	salt(image2,6000);    // 调用噪声函数
	cv::namedWindow("Image2");
	cv::imshow("Image2",image2);
	cv::waitKey();
	return 0;
}


