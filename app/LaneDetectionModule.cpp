/************************************************************************
 MIT License

 Copyright (c) 2018 Harsh Kakashaniya,Rohitkrishna Nambiar

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 *************************************************************************/

/**
 *  @file    LaneDetectionModule.cpp
 *  @author  harshkakashaniya and Rohitkrishna Nambiar
 *  @date    10/12/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 5,Midterm Project.
 *
 *  @Description DESCRIPTION
 *
 *  Class member functions for LaneDetectionModule.cpp
 *
 */

#include "LaneDetectionModule.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "Lane.hpp"
/**
 *   @brief Default constructor for LaneDetectionModule
 *
 *
 *   @param nothing
 *   @return nothing
 */
LaneDetectionModule::LaneDetectionModule() {
  yellowMin = cv::Scalar(20, 100, 100);  // max possible RGB values of yellow
  yellowMax = cv::Scalar(30, 255, 255);  // min possible RGB values of yellow
  grayscaleMin = 200;  // min possible grayscale value for white in our video
  grayscaleMax = 255;  // max possible grayscale value for white in our video
  videoName = "xyz.mp4";  // specify video name
}

/**
 *   @brief Default destructor for LaneDetectionModule
 *
 *
 *   @param nothing
 *   @return nothing
 */
LaneDetectionModule::~LaneDetectionModule() {
}

/**
 *   @brief Method Undistortedimage for LaneDetectionModule
 *
 *
 *   @param src is a Matrix of source of image
 *   @param dst is a Matrix of destination of image
 *   @return nothing
 */
void LaneDetectionModule::undistortImage(const cv::Mat& src, cv::Mat& dst) {
  cv::Mat cameraMatrix =
      (cv::Mat_<double>(3, 3) << 1154.22732, 0.0,
 671.627794, 0.0, 1148.18221, 386.046312, 0.0, 0.0, 1.0);

  std::vector<double> distortionCoeff { -.242565104, -0.0477893070,
      -0.00131388084, -0.0000879107779, 0.0220573263 };

  cv::undistort(src, dst, cameraMatrix, distortionCoeff);
}

/**
 *   @brief Method thresholdImageY to set
 *   		  yellow threshold image for LaneDetectionModule
 *
 *
 *   @param src is a Matrix of source of image
 *   @param dst is a Matrix of destination of image
 *   @return nothing
 */
void LaneDetectionModule::thresholdImageY(const cv::Mat& src, cv::Mat& dst) {
  // Image to HLS type image for decreasing effect of light intensity.
  cv::cvtColor(src, dst, cv::COLOR_BGR2HLS);

  // use white thresholding values to detect only road lanes
  cv::inRange(dst, yellowMin, yellowMax, dst);
}

/**
 *   @brief Method thresholdImageW to set
 *   		white threshold image for LaneDetectionModule
 *
 *
 *   @param src is a Matrix of source of image
 *   @param dst is a Matrix of destination of image
 *   @return nothing
 */
void LaneDetectionModule::thresholdImageW(const cv::Mat& src, cv::Mat& dst) {
  // Convert to grayscale image
  cv::cvtColor(src, dst, cv::COLOR_RGB2GRAY);

  // use white thresholding values to detect only road lanes
  cv::inRange(dst, grayscaleMin, grayscaleMax, dst);
}

/**
 *   @brief Method extractROI to set
 *   		  region of interest for LaneDetectionModule
 *
 *
 *   @param src is a Matrix of source of image
 *   @param dst is a Matrix of destination of image
 *   @return nothing
 */
void LaneDetectionModule::extractROI(const cv::Mat& src, cv::Mat& dst) {
  int width = src.cols;  // width of recieved frame.
  int height = src.rows;  // height of recieved frame.

//  mask matrix initialized as zero Matrix of Height and Width of frame matrix.
  cv::Mat mask = cv::Mat::zeros(height, width, CV_8U);
  // Make corners points for the mask.
  cv::Point pts[4] = { cv::Point(0, height), cv::Point(width / 2 - 100,
                                                       height / 2 + 50),
      cv::Point(width / 2 + 100, height / 2 + 50), cv::Point(width, height) };

  // Create a polygon
  cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255));

  // And the source thresholded image and mask
  bitwise_and(src, mask, dst);
}

/**
 *   @brief Method extractLanes to calculate
 *   		  parameters of lines and its characteristics
 *   		  for LaneDetectionModule.
 *
 *   @param src is a Matrix of source of image
 *   @param dst is a Matrix of destination of image
 *   @param lane1 object of class lane to store line characteristic.
 *   @param lane2 object of class lane to store line characteristic
 *   @param curveFlag to set degree of curve
 *   @return nothing
 */
void LaneDetectionModule::extractLanes(const cv::Mat& src, Lane& lane1,
 Lane& lane2, int curveFlag) {
  // TODO(harshkakashniya): find lanes slope point and curve.
}

/**
 *   @brief Method getDriveHeading to calculate
 *   		  drive heading to be given to actuator for further action
 *   		  in LaneDetectionModule.
 *
 *   @param lane1 object of class lane to store line characteristic.
 *   @param lane2 object of class lane to store line characteristic.
 *   @return double value of drive head.
 */
double LaneDetectionModule::getDriveHeading(Lane& lane1, Lane& lane2) {
  // TODO(harshkakashniya): calculate driveheading which can be given to
  // stearing wheel to control the car.
  return 0.0;
}

/**
 *   @brief Method displayOutput to calculate
 *   		  to display of the system
 *   		  for LaneDetectionModule.
 *
 *   @param src is a Matrix of source of image
 *   @param lane1 object of class lane to store line characteristic.
 *   @param lane2 object of class lane to store line characteristic
 *   @param heading to get Drive heading for output
 *   @return nothing
 */
void LaneDetectionModule::displayOutput(const cv::Mat& src, Lane& lane1,
 Lane& lane2, double heading) {
  // TODO(harshkakashniya): give reading of angular turning on display.
}

/**
 *   @brief Method detectLane check if program is successfully running
 *   		  gives bool output for LaneDetectionModule
 *
 *   @param videoName is video of source
 *   @return bool for code working.
 */
bool LaneDetectionModule::detectLane(std::string videoName) {
  // TODO(harshkakashniya): to check if we are able to detect video correctly.
  return 0;
}

/**
 *   @brief Method getYellowMax is to use get max value of yellow
 *   for LaneDetectionModule
 *
 *   @param nothing
 *   @return Scalar of RGB set values.
 */
cv::Scalar LaneDetectionModule::getYellowMax() {
  return yellowMax;
}

/**
 *   @brief Method getYellowMin is to use get min value of yellow
 *   for LaneDetectionModule
 *
 *   @param nothing
 *   @return Scalar of RGB set values.
 */
cv::Scalar LaneDetectionModule::getYellowMin() {
  return yellowMin;
}

/**
 *   @brief Method setYellowMax is to use set max value of yellow
 *   for LaneDetectionModule
 *
 *   @param  Scalar of RGB values
 *   @return nothing.
 */
void LaneDetectionModule::setYellowMax(cv::Scalar value) {
  yellowMax = value;
}

/**
 *   @brief Method setYellowMin is to use set min value of yellow
 *   for LaneDetectionModule
 *
 *   @param  Scalar of RGB values
 *   @return nothing.
 */
void LaneDetectionModule::setYellowMin(cv::Scalar value) {
  yellowMin = value;
}

/**
 *   @brief Method setGrayScaleMax is to use set max value of Gray scale
 *   value for LaneDetectionModule
 *
 *   @param  int of GrayScale values
 *   @return nothing.
 */
void LaneDetectionModule::setGrayScaleMax(int value) {
  grayscaleMax = value;
}

/**
 *   @brief Method setGrayScaleMin is to use set min value of Gray scale
 *   value for LaneDetectionModule
 *
 *   @param  int of GrayScale values
 *   @return nothing.
 */
void LaneDetectionModule::setGrayScaleMin(int value) {
  grayscaleMin = value;
}

/**
 *   @brief Method getGrayScaleMin is to use get min value of GrayScale
 *   for LaneDetectionModule
 *
 *   @param nothing
 *   @return int of GrayScale values
 */
int LaneDetectionModule::getGrayScaleMin() {
  return grayscaleMin;
}

/**
 *   @brief Method getGrayScaleMax is to use get max value of GrayScale
 *   for LaneDetectionModule
 *
 *   @param nothing
 *   @return int of GrayScale values
 */
int LaneDetectionModule::getGrayScaleMax() {
  return grayscaleMax;
}
