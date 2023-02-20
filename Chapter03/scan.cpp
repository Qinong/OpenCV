#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// 更改指定位置的像素值
void colorReduce1(cv::Mat image) {
      int nl= image.rows;    // 图像的行数
      int nc= image.cols * image.channels();    // 图像每行的元素数量
      for (int j=0; j<nl; j++) {
          uchar* data= image.ptr<uchar>(j);   // 取第j行的地址
          for (int i=0; i<nc/2; i++)     // 处理每个像素
          {
            data[i]= 255; 
          }
      }
}


// 使用cv::Mat_<cv::Vec3b>::iterator迭代器
void colorReduce2(cv::Mat image, int div=64) {
      cv::Mat_<cv::Vec3b>::iterator it= image.begin<cv::Vec3b>();
      cv::Mat_<cv::Vec3b>::iterator itend= image.end<cv::Vec3b>();
	  uchar div2 = div >> 1; // div2 = div/2

      for ( ; it!= itend; ++it) {
        (*it)[0]= (*it)[0]/div*div + div2;
        (*it)[1]= (*it)[1]/div*div + div2;
        (*it)[2]= (*it)[2]/div*div + div2;
      }
}


// 使用cv::MatIterator_<cv::Vec3b>迭代器
void colorReduce3(cv::Mat image, int div=64) {
      cv::MatIterator_<cv::Vec3b> it= image.begin<cv::Vec3b>();
      cv::MatIterator_<cv::Vec3b> itend= image.end<cv::Vec3b>();
      const cv::Vec3b offset(div/2,div/2,div/2);
      
      for ( ; it!= itend; ++it) {
        *it= *it/div*div+offset;
      }
}


int main()
{
	cv::Mat image = cv::imread("Ferrar_F8.png");
    cv::Mat image1 =  image.clone();
    cv::Mat image2 =  image.clone();
    cv::Mat image3 =  image.clone();
    
    cv::namedWindow("Image",0);
	cv::imshow("Image", image);
	cv::waitKey();
    
    // 调用函数并记录处理图像的时间
	colorReduce1(image1);
	cv::namedWindow("Image1",0);
	cv::imshow("Image1", image1);
	cv::waitKey();
    
    // 调用函数并记录处理图像的时间
	colorReduce2(image2);
	cv::namedWindow("Image2",0);
	cv::imshow("Image2", image2);
	cv::waitKey();
    
    // 调用函数并记录处理图像的时间
	colorReduce3(image3);
	cv::namedWindow("Image3",0);
	cv::imshow("Image3", image3);
	cv::waitKey();
	return 0;
}














