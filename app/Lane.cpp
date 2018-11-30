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
 *  @file    Lane.cpp
 *  @author  Harsh Kakashaniya and Rohitkrishna Nambiar
 *  @date    10/12/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 5,Midterm Project.
 *
 *  @section DESCRIPTION
 *
 *  Class member functions for Lane.cpp
 *
 */

#include "Lane.hpp"

Lane::Lane()
    : polyOrder(1),
      colour("red"),
      averagingCount(10),
      currentAveragingIndex(0),
      status(false) {
//  std::cout << "Default constructor called" << std::endl;
}


Lane::Lane(int polyOrder, std::string color, int averagingCount)
    : polyOrder(polyOrder),
      colour(color),
      averagingCount(averagingCount),
      currentAveragingIndex(0),
      status(false) {
//  std::cout << "Lane created with the following values: Polyorder: "
//            << polyOrder << " Color: " << color << " averaging count: "
//            << averagingCount << std::endl;
}


Lane::~Lane() {
}


int Lane::getStableCenter(int coordinate) {
  if (currentAveragingIndex < averagingCount) {
    averagingCenter.push_back(coordinate);
    currentAveragingIndex++;
  } else {
    averagingCenter.erase(averagingCenter.begin());
    averagingCenter.push_back(coordinate);
  }

  int average = std::accumulate(averagingCenter.begin(), averagingCenter.end(),
                                0) / averagingCenter.size();
  return average;
}


void Lane::setStartCoordinate(cv::Point point) {
  startCoordinates = point;
}


void Lane::setStatus(bool flag) {
  status = flag;
}


void Lane::setPolyCoeff(cv::Mat laneCoeff) {
  polyCoeff.clear();
  if (polyCoeff.empty()) {
    polyCoeff.push_back(laneCoeff.at<float>(0, 0));
    polyCoeff.push_back(laneCoeff.at<float>(1, 0));
    polyCoeff.push_back(laneCoeff.at<float>(2, 0));
  } else {
    std::cout << "Could not insert new elements!" << std::endl;
  }
}


cv::Point Lane::getStartCoordinate() {
  return startCoordinates;
}


bool Lane::getStatus() {
  return status;
}


std::vector<float> Lane::getPolyCoeff() {
  return polyCoeff;
}


void Lane::setPolyOrder(int value) {
  polyOrder = value;
}


int Lane::getPolyOrder() {
  return polyOrder;
}
