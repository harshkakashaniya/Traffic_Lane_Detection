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

#ifndef TRAFFIC_LANE_H_
#define TRAFFIC_LANE_H_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/opencv.hpp>

class Lane {
 public:
/**
 *   @brief Default constructor for Lane
 *          with ployorder,colour,polyCoeff,startCoordinate,status
 *          random values
 *
 *   @param nothing
 *   @return nothing
 */
	Lane();
/**
 *   @brief Default destructor for Lane
 *   @param nothing
 *   @return nothing
 */
	~Lane();
	int polyOrder;	// declare integer for order of line.
	std::string colour;  //set RGB values for colour.
	std::vector <double> polyCoeff;  // Coefficients for equation
	cv::Point startCoordinates;  //Reference coordinates for line.
	bool status;  //for status for program.




};

#endif /* TRAFFIC_LANE_H_ */
