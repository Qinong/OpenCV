
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	cv::Mat image1;
	cv::Mat image2;
	image1= cv::imread("AUdi_A8.jpg");
	image2= cv::imread("huang.jpg");
	if (!image1.data)
		return 0; 
	if (!image2.data)
		return 0; 
	cv::namedWindow("Image1",0);
	cv::imshow("Image1",image1);
	cv::namedWindow("Image2",0);
	cv::imshow("Image2",image2);
    
    // 合并图像
	cv::Mat image3;
	cv::addWeighted(image1,0.7,image2,0.9,0.,image3 );
	cv::namedWindow("Image3",0);
	cv::imshow("Image3",image3);
    
	// 使用运算符重载
	image3= 0.7*image1+0.9*image2;
	cv::namedWindow("Image4",0);
	cv::imshow("Image4",image3);

    // 分割图像通道
	image2= cv::imread("huang.jpg",0);
	std::vector<cv::Mat> planes;
	cv::split(image1,planes);
	planes[0]+= image2;
	cv::merge(planes,image3);
	cv::namedWindow("Image5",0);
	cv::imshow("Image5",image3);
	cv::waitKey();
        
    cv::namedWindow("test",0);
    int alpha = 0;
    int beta = 0;
    int gamma = 0;
    cv::createTrackbar("alpha","test",&alpha,100);
    cv::createTrackbar("beta","test",&beta,100);
    cv::createTrackbar("gamma","test",&gamma,255);
    for(;;)
    {
        cv::Mat image3;
        cv::addWeighted(image1, alpha/100.0f, image2, beta/100.0f, gamma, image3);
        cv::namedWindow("test",0);
        cv::imshow("test",image3);
        if(cv::waitKey(10)==0)
            break;
    }

	return 0;
}
