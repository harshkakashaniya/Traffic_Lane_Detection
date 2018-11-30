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
 *  @file    SteerDrive.cpp
 *  @author  Harsh Kakashaniya and Rohitkrishna Nambiar
 *  @date    10/12/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, Week 5,Midterm Project.
 *
 *  @section DESCRIPTION
 *
 *  Class member functions for SteerDrive.cpp
 *
 */

#include "SteerDrive.hpp"
/**
 *   @brief Default constructor for SteerDrive
 *          with ployorder,colour,polyCoeff,startCoordinate,status
 *          random values
 *
 *   @param nothing
 *   @return nothing
 */
SteerDrive::SteerDrive()
:MechAdvantage(2.5),  // MechAdvantage in the transmission system.
CarModel("Audi R8"),  // Car Model
DifferentialRatio(3.0),  // gear ration of differential.
Status(false) {
}

/**
 *   @brief Default destructor for SteerDrive
 *
 *   @param nothing
 *   @return nothing
 */
SteerDrive::~SteerDrive() {
}

/*
 *  @brief To get output of Car Model name
 *
 *  @return string of Car Model
 */

std::string SteerDrive::getCarModel() {
  return CarModel;
}

/*
 *  @brief Sets car Model Name
 *
 *  @param string of car model name
 *
 */
void SteerDrive::setCarModel(std::string Car) {
  CarModel = Car;
}

/*
 *  @brief Gets differential gear ratio
 */
float SteerDrive::getDifferentialRatio() {
  return DifferentialRatio;
}

/*
 *  @brief Sets the DifferentialRatio of SteerDrive
 *
 *  @param float of DifferentialRatio
 */
void SteerDrive::setDifferentialRatio(float Differential) {
  DifferentialRatio = Differential;
}

/*
 *  @brief Gets MechAdvantage of SteerDrive
 *
 *  @return MechAdvantage of the SteerDrive
 */
float SteerDrive::getMechAdvantage() {
  return MechAdvantage;
}

/*
 *  @brief Sets the MechAdvantage of SteerDrive
 *
 *  @param value is the MechAdvantage of SteerDrive
 */
  void SteerDrive::setMechAdvantage(float Mech) {
    MechAdvantage = Mech;
}

/*
 *  @brief Gets the Resultant Gear Box ratio of SteerDrive
 *
 *  @return value is the Resultant Gear Box ratio of SteerDrive
 */
  float SteerDrive::ResultantGearBox(float MechAdvantage,
                                  float DifferentialRatio) {
  return MechAdvantage*DifferentialRatio;
}

/*
 *  @brief Gets the status of SteerDrive working
 *
 *  @param value is the setting Steer Drive status
 */
  void SteerDrive::setStatus(bool flag) {
  Status = flag;
}
/*
 *  @brief Gets the polyOrder of SteerDrive
 *
 *  @return value is the polyorder of SteerDrive
 */
  bool SteerDrive::getStatus() {
  return Status;
  }
