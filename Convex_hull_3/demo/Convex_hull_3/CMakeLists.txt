# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Convex_hull_3_Demo )

cmake_minimum_required(VERSION 3.1)
if(NOT POLICY CMP0070 AND POLICY CMP0053)
  # Only set CMP0053 to OLD with CMake<3.10, otherwise there is a warning.
  cmake_policy(SET CMP0053 OLD)
endif()

set_property(DIRECTORY PROPERTY CGAL_NO_TESTING TRUE)

find_package(CGAL QUIET)

if ( CGAL_FOUND )

  create_single_source_cgal_program( "quickhull_3_demo.cpp" )

else()

    message(STATUS "This program requires the CGAL library, and will not be compiled.")

endif()

