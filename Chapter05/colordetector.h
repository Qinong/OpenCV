#if !defined COLORDETECT
#define COLORDETECT

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ColorDetector {

  private:
	  int maxDist;     // 允许的最小差距
	  cv::Vec3b target;    // 目标颜色
	  cv::Mat converted;   // 转换的图像
	  bool useLab;         // 是否使用Lab色彩空间
	  cv::Mat result;  // 存储二值映射结果的图像

  public:
	  // 不同的构造函数
	  // 在此初始化默认参数
	  ColorDetector() : maxDist(100), target(0,0,0), useLab(false) {}
	  ColorDetector(bool useLab) : maxDist(100), target(0,0,0), useLab(useLab) {}
	  ColorDetector(uchar blue, uchar green, uchar red, int mxDist=100, bool useLab=false): maxDist(mxDist), useLab(useLab) { 
		  // 设置需要检测的颜色
		  setTargetColor(blue, green, red);
	  }

	  // 计算与目标颜色的距离
	  int getDistanceToTargetColor(const cv::Vec3b& color) const {
		  return getColorDistance(color, target);
	  }

	  // 计算两个颜色之间的城区距离
	  int getColorDistance(const cv::Vec3b& color1, const cv::Vec3b& color2) const {

		  return abs(color1[0]-color2[0])+
					abs(color1[1]-color2[1])+
					abs(color1[2]-color2[2]);
	  }

	  cv::Mat process(const cv::Mat &image);
      
	  cv::Mat operator()(const cv::Mat &image) {
		  cv::Mat input;
		 
		  if (useLab) { 
			  cv::cvtColor(image, input, CV_BGR2Lab);    // 转换成Lab色彩空间
		  }
		  else {
			  input = image;
		  }

		  cv::Mat output;
		  cv::absdiff(input,cv::Scalar(target),output);   // 计算目标图像的绝对距离
	      std::vector<cv::Mat> images;
	      cv::split(output,images);    // 分割图像的通道
	      output= images[0]+images[1]+images[2];   // 合并3个通道
	      
		  // 设定阈值
          cv::threshold(output,  // 输入图像
                        output,  // 输出图像
                        maxDist, // 阈值
                        255,     // 最大值
                        cv::THRESH_BINARY_INV); // 阈值类型
	
	      return output;
	  }


	  //设置颜色距离的阈值
	  void setColorDistanceThreshold(int distance) {
		  if (distance<0)
			  distance=0;
		  maxDist= distance;
	  }

	  // 获取颜色距离的阈值
	  int getColorDistanceThreshold() const {
		  return maxDist;
	  }
	  
	  // 设置需要检测的颜色
	  void setTargetColor(uchar blue, uchar green, uchar red) {
		  // BGR的次序
		  target = cv::Vec3b(blue, green, red);

		  if (useLab) {
			  // 创建临时的单像素图像
			  cv::Mat tmp(1, 1, CV_8UC3);
			  tmp.at<cv::Vec3b>(0, 0) = cv::Vec3b(blue, green, red);

			  // 转换成Lab色彩空间
			  cv::cvtColor(tmp, tmp, CV_BGR2Lab);
			  target = tmp.at<cv::Vec3b>(0, 0);
		  }
	  }

	  // 设置需要检测的颜色
	  void setTargetColor(cv::Vec3b color) {
		  target= color;
	  }

	  // 获取需要检测的颜色
	  cv::Vec3b getTargetColor() const {
		  return target;
	  }
};


#endif
