# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Point_set_shape_detection_3_Examples )

cmake_minimum_required(VERSION 3.1)
if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6)
  if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
    cmake_policy(VERSION 2.8.4)
  else()
    cmake_policy(VERSION 2.6)
  endif()
endif()

find_package(CGAL QUIET)

if ( CGAL_FOUND )

  # Use Eigen
  find_package(Eigen3 3.1.0 QUIET) #(3.1.0 or greater)
  if (EIGEN3_FOUND)
    include( ${EIGEN3_USE_FILE} )
    create_single_source_cgal_program( "shape_detection_basic.cpp" )
    create_single_source_cgal_program( "shape_detection_with_callback.cpp" )
    create_single_source_cgal_program( "plane_regularization.cpp" )
  endif()

  create_single_source_cgal_program( "efficient_RANSAC_custom_shape.cpp" )
  create_single_source_cgal_program( "efficient_RANSAC_parameters.cpp" )
  create_single_source_cgal_program( "efficient_RANSAC_point_access.cpp" )

else()

    message(STATUS "This program requires the CGAL library, and will not be compiled.")

endif()

