#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "colordetector.h"

int main()
{
    // step1
    // 创建检测图像的对象
	ColorDetector cdetect;

    // step2
    // 读取原图像
	cv::Mat image= cv::imread("Ferrar_F8.png");
	if (image.empty())
		return 0; 
	cv::namedWindow("Image");
	cv::imshow("Image", image);

    // step3
    // 设置输入参数与输出图像处理效果
	cdetect.setTargetColor(230,190,130);
	cv::namedWindow("Image1");
	cv::Mat image1 = cdetect.process(image);
	cv::imshow("Image1",image1);
    

	// 使用cv::floodFill函数
    ColorDetector colordetector(230, 190, 130, 45, true);  // 第3个构造函数
	cv::floodFill(image,            // 输入/输出图像
		cv::Point(100, 50),         // 起始点
		cv::Scalar(255, 255, 255),  // 填充颜色
		(cv::Rect*)0,               // 填充颜色的边界距离
		cv::Scalar(35, 35, 35),     // 偏差的最小/最大阈值
		cv::Scalar(35, 35, 35),     // 正差阈值，两个阈值通常相等
		cv::FLOODFILL_FIXED_RANGE); // 与起始点像素比较
	cv::namedWindow("Image2");
	cv::Mat image2 = colordetector(image);
	cv::imshow("Image2", image2);
	cv::waitKey();

	return 0;
}

