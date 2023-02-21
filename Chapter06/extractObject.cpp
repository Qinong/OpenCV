#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
	cv::Mat image= cv::imread("Ferrar_F8.png");
	if (!image.data)
		return 0; 
	cv::namedWindow("Image");
	cv::imshow("Image",image);

	// 定义边框矩形
	cv::Rect rectangle(100,120,650,350);
	// 定义前景、背景和分割结果
	cv::Mat bgModel,fgModel,result; 

	// GrabCut分割
	cv::grabCut(image,
                result,
                rectangle,
                bgModel,
                fgModel, 
                5,        
                cv::GC_INIT_WITH_RECT); // use rectangle

	// 标记可能属于前景的区域
	cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
	// or:
    //	result= result&1;

	// 创建前景图像
	cv::Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
	image.copyTo(foreground,result); // 复制前景图像

	// 在原图像绘制矩形区域
	cv::rectangle(image, rectangle, cv::Scalar(200,0,200),4);
	cv::namedWindow("Rectangle");
	cv::imshow("Rectangle",image);
	cv::namedWindow("Foreground");
	cv::imshow("Foreground",foreground);

	cv::waitKey();
	return 0;
}
