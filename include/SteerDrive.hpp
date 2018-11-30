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
 *  @file    SteerDrive.hpp
 *  @author  Harsh Kakashaniya and Rohitkrishna Nambiar
 *  @date    10/13/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 6, Midterm Project
 *
 *  @section DESCRIPTION
 *
 *  Implementation to SteerDrive detection system when a video is provided
 *  it gives output of Drive heading and SteerDrive on video.
 *
 */

  #ifndef INCLUDE_STEERDRIVE_HPP_
  #define INCLUDE_STEERDRIVE_HPP_

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <opencv2/opencv.hpp>

class SteerDrive {
 public:
  /**
   *  @brief Default constructor for SteerDrive
   *
   */

  SteerDrive();

  /**
   *  @brief Default destructor for SteerDrive class
   */
  virtual ~SteerDrive();

  /*
   *  @brief To get output of Car Model name
   *
   *  @return string of Car Model
   */
  std::string getCarModel();

  /*
   *  @brief Sets car Model Name
   *
   *  @param string of car model name
   *
   */
  void setCarModel(std::string Car);

  /*
   *  @brief Gets differential gear ratio
   */
  float getDifferentialRatio();

  /*
   *  @brief Sets the DifferentialRatio of SteerDrive
   *
   *  @param float of DifferentialRatio
   */
  void setDifferentialRatio(float Differential);

  /*
   *  @brief Gets MechAdvantage of SteerDrive
   *
   *  @return MechAdvantage of the SteerDrive
   */
  float getMechAdvantage();

  /*
   *  @brief Sets the MechAdvantage of SteerDrive
   *
   *  @param value is the MechAdvantage of SteerDrive
   */
  void setMechAdvantage(float Mech);

  /*
   *  @brief Gets the status of SteerDrive working
   *
   *  @param value is the setting Steer Drive status
   */
  void setStatus(bool flag);

  /*
   *  @brief Gets the polyOrder of SteerDrive
   *
   *  @return value is the polyorder of SteerDrive
   */
  virtual bool getStatus();
   /*
    *  @brief Gets the Resultant Gear Box ratio of SteerDrive
    *
    *  @return value is the Resultant Gear Box ratio of SteerDrive
    */
  virtual float ResultantGearBox(float MechAdvantage ,
                                  float DifferentialRatio);

 private:
  float MechAdvantage;  // MechAdvantage in the transmission system.
  std::string CarModel;  // Car Model
  float DifferentialRatio;  // gear ration of differential.
  bool Status;
};
#endif  // INCLUDE_STEERDRIVE_HPP_
