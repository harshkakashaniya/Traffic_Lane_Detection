/**
 *  Copyright 2018 Harsh Kakashaniya
 *  @file    LaneDetectionModule.cpp
 *  @author  rohith517 (Navigator) and harshkakashaniya (driver)
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

#include "LaneDetectionModule.h"
  /**
   *   @brief Default constructor for LaneDetectionModule
   *
   *
   *   @param nothing
   *   @return nothing
   */

  LaneDetectionModule::LaneDetectionModule() {
  // TODO(harshkakashniya): Auto-generated constructor stub
  yellowMin = (20, 30, 40);  // max possible RGB values of yellow
  yellowMax = (20, 30, 40);  // min possible RGB values of yellow
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
  // TODO(harshkakashniya): Auto-generated destructor stub
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
  // TODO(harshkakashniya): Given image to be undistorted so that we get
  // proper analysis.
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
  // TODO(harshkakashniya): find yellow lane in the image with setting
  // RGB values.
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
  // TODO(harshkakashniya): find white lane in the image with setting
  // grayscalevalue.
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
  // TODO(harshkakashniya): find area on interest where lanes cna be found
  // so that other errors can be minimized.
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
  // TODO(harshkakashniya): to get RGB max values for yellow.
  return 0;
}
  /**
   *   @brief Method getYellowMin is to use get min value of yellow
   *   for LaneDetectionModule
   *
   *   @param nothing
   *   @return Scalar of RGB set values.
   */
  cv::Scalar LaneDetectionModule::getYellowMin() {
  // TODO(harshkakashniya): to get RGB min values for yellow.
  return 0;
}
  /**
   *   @brief Method setYellowMax is to use set max value of yellow
   *   for LaneDetectionModule
   *
   *   @param  Scalar of RGB values
   *   @return nothing.
   */
  void LaneDetectionModule::setYellowMax(cv::Scalar) {
  // TODO(harshkakashniya): to set RGB max values for yellow.
}
  /**
   *   @brief Method setYellowMin is to use set min value of yellow
   *   for LaneDetectionModule
   *
   *   @param  Scalar of RGB values
   *   @return nothing.
   */
  void LaneDetectionModule::setYellowMin(cv::Scalar) {
  // TODO(harshkakashniya): to set RGB min values for yellow.
}
  /**
   *   @brief Method setGrayScaleMax is to use set max value of Gray scale
   *   value for LaneDetectionModule
   *
   *   @param  int of GrayScale values
   *   @return nothing.
   */
  void LaneDetectionModule::setGrayScaleMax(int value) {
  // TODO(harshkakashniya): to set grayscale max values for white.
}
  /**
   *   @brief Method setGrayScaleMin is to use set min value of Gray scale
   *   value for LaneDetectionModule
   *
   *   @param  int of GrayScale values
   *   @return nothing.
   */
  void LaneDetectionModule::setGrayScaleMin(int value) {
  // TODO(harshkakashniya): to set grayscale min values for white.
}
  /**
   *   @brief Method getGrayScaleMin is to use get min value of GrayScale
   *   for LaneDetectionModule
   *
   *   @param nothing
   *   @return int of GrayScale values
   */

  int LaneDetectionModule::getGrayScaleMin() {
  // TODO(harshkakashniya): to get grayscale max values for white.
  return 0;
}
  /**
   *   @brief Method getGrayScaleMax is to use get max value of GrayScale
   *   for LaneDetectionModule
   *
   *   @param nothing
   *   @return int of GrayScale values
   */
  int LaneDetectionModule::getGrayScaleMax() {
  // TODO(harshkakashniya): to get grayscale min values for white.
  return 0;
}
