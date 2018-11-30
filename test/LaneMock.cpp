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
 *  @file    LaneMock.cpp
 *  @author  Harsh Kakashaniya and Rohitkrishna Nambiar
 *  @date    11/25/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 5,Midterm Project Gmock test.
 *
 *  @section DESCRIPTION
 *
 *  Gmock for Lane class
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Lane.hpp"
#include "LaneDetectionModule.hpp"

// GMock
using ::testing::Return;

// Create a mock class for Lane. We mock the method getStatus() that
// is used in the getDriveHeading of LaneDetectionModule
class LaneMock : public Lane {
 public:
  // Default constructor
  LaneMock()
      : Lane() {
  }

  // Overloaded constructor
  LaneMock(int polyOrder, std::string color, int averagingCount)
      : Lane(polyOrder, color, averagingCount) {
  }
  // Mock the getStatus method
  MOCK_METHOD0(getStatus, bool());
  MOCK_METHOD0(getPolyCoeff, std::vector<float>());
};

/**
 *@brief Test drive heading function in LaneDetectionModule
 *       by mocking getStatus function
 *
 *@param driveHeadingTest   Name of test suite
 *@param mockGetStatus      Name of the unit test
 *
 *@return none
 */
TEST(driveHeadingTest, mockGetStatusTest) {
  // Create mock lane objects for left and right lane.
  // Status is set to false on initialization
  LaneMock left(2, "red", 10);
  LaneMock right(2, "green", 10);

  // LaneDetectionModule module object
  LaneDetectionModule laneModule;

  // Create variables to store direction and slope
  std::string direction;

  // We only check the right lane as if that is false, the other
  // getStatus for left lane is not evaluated.
  EXPECT_CALL(right, getStatus()).Times(1).WillOnce(Return(false));

  double slope = laneModule.getDriveHeading(right, left, direction);

  EXPECT_EQ(slope, 0);
}

/**
 *@brief Test drive heading function in LaneDetectionModule
 *       by mocking getPolyCoeff function
 *
 *@param driveHeadingTest       Name of test suite
 *@param mockGetPolyCoeffTest   Name of the unit test
 *
 *@return none
 */
TEST(driveHeadingTest, mockGetPolyCoeffTest) {
  // Create mock lane objects for left and right lane.
  // Status is set to false on initialization
  LaneMock left(2, "red", 10);
  LaneMock right(2, "green", 10);

  // Set the polynomial coefficients
  std::vector<float> testLaneCoeff;
  testLaneCoeff.push_back(175.535);
  testLaneCoeff.push_back(0.363008);
  testLaneCoeff.push_back(-0.000274466);

  // LaneDetectionModule module object
  LaneDetectionModule laneModule;

  // Create variables to store direction and slope
  std::string direction;

  // We only check the right lane as if that is false, the other
  // getStatus for left lane is not evaluated.
  EXPECT_CALL(right, getStatus()).Times(1).WillOnce(Return(true));
  EXPECT_CALL(left, getStatus()).Times(1).WillOnce(Return(true));
  EXPECT_CALL(right, getPolyCoeff()).Times(1).WillOnce(Return(testLaneCoeff));

  double slope = laneModule.getDriveHeading(right, left, direction);

  EXPECT_NEAR(slope, -9.39127, 1.0);
}
