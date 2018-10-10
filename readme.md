# Smart Lane - A Traffic Lane Detection System
[![Build Status](https://travis-ci.org/harshkakashaniya/Traffic_Lane_Detection.svg?branch=master)](https://travis-ci.org/harshkakashaniya/Traffic_Lane_Detection) [![Coverage Status](https://coveralls.io/repos/github/harshkakashaniya/Traffic_Lane_Detection/badge.svg?branch=master)](https://coveralls.io/github/harshkakashaniya/Traffic_Lane_Detection?branch=master) [![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/harshkakashaniya/Traffic_Lane_Detection/blob/master/LICENSE)
---

## Overview

Lane detection is an important aspect of self-driving vehicles. With   Acme   robotics   entering   the   autonomous   delivery   business,  delivery   vehicles   should   be   smart   enough   and   able   to   navigate   roads  effortlessly. Smart Lane is a lane detection module that can be integrated with the other modules onboard a self driving car. This project has been developed as a part of the ENPM808X-Software Development course for midterm project. 

A quick overview of the algorithm is as follows:

- Filter   and   segment   the   input   image   to   get   a   rough   estimate   of   the  lanes.
- Perform region of interest (ROI) extraction for filtering out false positives.
- Perspective transformations for getting lane slopes and curves.
- Overlay lane lines and calculate heading direction to output.

## Development Process

We will use Solo Iterative Process (SIP) for all the design and development purpose. The planning and development of this module has been split into two sprints of a week each. The product backlog, work log and iteration log can be found in the link below. Test Driven Development approach is taken for implementation and unit testing. Work is splited into two sprints according to priority and dependency. This will enable us to complete the project in defined time.At the end we will have report of actual time and planned time difference. This will enable future ventures to plan correctly.He we can define SIP as an continous improvement process.

[Product Backlog](https://docs.google.com/spreadsheets/d/1fH342l1l3P8Fn3pwxwf_l3Y76kfqskcWcNobQ2caDIc/edit?usp=sharing).  

## License
```
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
```

## Dependencies
Simple starter C++ project with:

- OpenCV - (OpenCV uses a BSD license and hence can be used for production with modification to the code.)
- cmake
- googletest

A complete OpenCV installation guide in Ubuntu can be found [here](http://www.codebind.com/cpp-tutorial/install-opencv-ubuntu-cpp/). 

## Standard install via command-line
```
git clone --recursive https://github.com/harshkakashaniya/Traffic_Lane_Detection
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/harshkakashaniya/Traffic_Lane_Detection
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of Traffic_Lane_Detection

``
cd ~/workspace
mkdir -p Traffic_Lane_Detection
cd Traffic_Lane_Detection
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../Traffic_Lane_Detection/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "Traffic_Lane_Detection" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold Traffic_Lane_Detection project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the Traffic_Lane_Detection in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the Traffic_Lane_Detection in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml
