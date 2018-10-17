/************************************************************************
 MIT License

 Copyright (c) 2018 Harsh Kakashaniya, Rohitkrishna Nambiar

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
 *  @file    Lane.hpp
 *  @author  Harsh Kakashaniya and Rohitkrishna Nambiar
 *  @date    10/13/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 6, Midterm Project
 *
 *  @section DESCRIPTION
 *
 *  Implementation to lane detection system when a video is provided
 *  it gives output of Drive heading and lane on video.
 *
 */

#ifndef INCLUDE_LANE_HPP_
#define INCLUDE_LANE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <opencv2/opencv.hpp>

class Lane {
 public:
  /**
   *  @brief Default constructor for Lane
   *        with ployorder,colour,polyCoeff,startCoordinate,status
   *        random values
   */
  Lane();

  /**
   *  @brief Default constructor for Lane
   *          with ployorder,colour,polyCoeff,startCoordinate,status
   *          random values
   *
   *  @param polyOrder is order of fitting polynomial
   *  @param color is the color of lane
   *  @param averagingCount number of values to average
   */
  Lane(int polyOrder, std::string color, int averagingCount);

  /**
   *  @brief Default destructor for Lane class
   */
  ~Lane();

  /*
   *  @brief Calculates the center x-coordinate averageof the first sliding
   *        window
   *
   *  @param coordinate is current x-center co-ordinate
   *
   *  @return averaged x-coordinate
   */
  int getStableCenter(int coordinate);

  /*
   *  @brief Sets the center coordinate of the first sliding window
   *
   *  @param point is current center co-ordinate
   *
   */
  void setStartCoordinate(cv::Point point);

  /*
   *  @brief Gets the center coordinate of the first sliding window
   *
   *  @return Center coordinate of the first sliding window(lane)
   */
  cv::Point getStartCoordinate();

  /*
   *  @brief Sets the status of lane
   *
   *  @param flag is the status of the lane if polynomial found
   */
  void setStatus(bool flag);

  /*
   *  @brief Gets the status of lane
   *
   *  @return status of the lane
   */
  bool getStatus();

  /*
   *  @brief Sets the polyOrder of lane
   *
   *  @param value is the polyorder of lane
   */
  void setPolyOrder(int value);

  /*
   *  @brief Gets the polyOrder of lane
   *
   *  @return value is the polyorder of lane
   */
  int getPolyOrder();

  /*
   *  @brief Sets the polynomial coeff of lane
   *
   *  @param coeff is a Mat(1x3) object containing coefficients
   */
  void setPolyCoeff(cv::Mat coeff);

  /*
   *  @brief Gets the polynomial coeff of lane
   *
   *  @return vector containing coefficients
   */
  std::vector<float> getPolyCoeff();

 private:
  int polyOrder;  // declare integer for order of line.
  std::string colour;  // set RGB values for lane colour.
  std::vector<float> polyCoeff;  // Coefficients for equation
  cv::Point startCoordinates;  // Reference coordinates for line.

  // Average center to prevent jumps for entire run
  std::vector<int> averagingCenter;
  int averagingCount;
  int currentAveragingIndex;
  bool status;  // For status for program.
};

#endif  // INCLUDE_LANE_HPP_
