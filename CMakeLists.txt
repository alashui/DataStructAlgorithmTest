cmake_minimum_required( VERSION 2.8 ) 
 
#set(project_namecloud_viewer_PointXYZ)
project(myAlgotithm_test)

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3" )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
 
add_subdirectory( src ) 

