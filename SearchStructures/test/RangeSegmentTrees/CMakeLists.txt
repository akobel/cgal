# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( RangeSegmentTrees_Tests )

cmake_minimum_required(VERSION 3.1)

find_package(CGAL QUIET)

if ( CGAL_FOUND )

  create_single_source_cgal_program( "test_segment_tree_set_2.cpp" )

else()

    message(STATUS "This program requires the CGAL library, and will not be compiled.")

endif()

