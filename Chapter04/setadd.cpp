
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
