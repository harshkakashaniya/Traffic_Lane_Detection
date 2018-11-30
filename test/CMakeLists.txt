set(GTEST_SHUFFLE 1)

add_executable(
    smartLane-test
    main.cpp
    LaneDetectionModuleTest.cpp
    LaneTest.cpp
    LaneMock.cpp
    ../app/LaneDetectionModule.cpp
    ../app/Lane.cpp
)

target_include_directories(smartLane-test PUBLIC ../vendor/googletest/googletest/include  
						 ../vendor/googletest/googlemock/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(smartLane-test PUBLIC gmock gtest ${OpenCV_LIBS})
