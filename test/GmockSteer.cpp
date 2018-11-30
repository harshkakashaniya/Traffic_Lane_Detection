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
 *  @file    GmockSteer.cpp
 *  @author  Harsh Kakashaniya
 *  @date    11/29/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Extra Credit.
 *
 *  @section DESCRIPTION
 *
 *  Gmock file for Steer
 *
 */
#include "iostream"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "vector"
#include "SteerDrive.hpp"
#include "LaneDetectionModule.hpp"

class Mocker : public SteerDrive {
 public:
  Mocker()
  : SteerDrive() {
}
  MOCK_METHOD2(ResultantGearBox, float(float MechAdvantage ,
                                      float DifferentialRatio));
  MOCK_METHOD0(getStatus , bool());
};
/**
 *  @brief Test for steering status
 *
 *  @param SteerTest        Constructor test
 *  @param SteerStatusTest  Name of the unit test
 */
TEST(SteerTest , SteerStatusTest) {
  // Arrange
Mocker mST;
LaneDetectionModule laneDetect;
  // Setup for test
EXPECT_CALL(mST , getStatus())
.Times(1)
.WillOnce(::testing::Return(false));
  // ACT
float returnValue = laneDetect.computeGearRatio(mST);
EXPECT_EQ(returnValue , 0);
}
/**
 *  @brief Custom Lane Constructor Test.
 *
 *  @param SteerTest             Constructor test
 *  @param ResultantGearBoxTest  Name of the unit test
 */
TEST(SteerTest , ResultantGearBoxTest) {
  // Arrange
Mocker mST;
LaneDetectionModule laneDetect;
  // Setup for test
EXPECT_CALL(mST , getStatus())
.Times(1)
.WillOnce(::testing::Return(true));
  // Setup for test
EXPECT_CALL(mST , ResultantGearBox(2.5 , 3.0))
.Times(1)
.WillOnce(::testing::Return(7.5));
  // ACT
float returnValue = laneDetect.computeGearRatio(mST);
EXPECT_EQ(returnValue , 7.5);
}
