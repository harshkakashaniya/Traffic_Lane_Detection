add_executable(shell-app main.cpp LaneDetectionModule.cpp Lane.cpp
              SteerDrive.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
TARGET_LINK_LIBRARIES(shell-app ${OpenCV_LIBS})
