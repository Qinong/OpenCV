#include "colordetector.h"
#include <vector>
	
cv::Mat ColorDetector::process(const cv::Mat &image) {

	  result.create(image.size(),CV_8U);

	  // 转换成Lab色彩空间
	  if (useLab)
		  cv::cvtColor(image, converted, CV_BGR2Lab);

	  // 获取迭代器
	  cv::Mat_<cv::Vec3b>::const_iterator it= image.begin<cv::Vec3b>();
	  cv::Mat_<cv::Vec3b>::const_iterator itend= image.end<cv::Vec3b>();
	  cv::Mat_<uchar>::iterator itout= result.begin<uchar>();

	  // 获取转换图像的迭代器
	  if (useLab) {
		  it = converted.begin<cv::Vec3b>();
		  itend = converted.end<cv::Vec3b>();
	  }

	  // 遍历每个像素
	  for ( ; it!= itend; ++it, ++itout) {
          // 通过像素与阈值比较 
		  if (getDistanceToTargetColor(*it)<maxDist) {
			  *itout= 255;
		  } 
		  else {
			  *itout= 0;
		  }
	  }

	  return result;
}

