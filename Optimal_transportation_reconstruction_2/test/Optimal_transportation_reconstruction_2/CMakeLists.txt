project( Optimal_transportation_reconstruction_2_Tests )

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

  include_directories (BEFORE "include")

  create_single_source_cgal_program( "test_basic.cpp" )
  create_single_source_cgal_program( "test_flip_procedure.cpp" )
  create_single_source_cgal_program( "test_output_modules.cpp" )
  create_single_source_cgal_program( "test_quality.cpp" )
  create_single_source_cgal_program( "test_reconstruction_until.cpp" )
  create_single_source_cgal_program( "test_vertex_edge.cpp" )
  create_single_source_cgal_program( "otr2_epeck.cpp" )

else()

    message(STATUS "This program requires the CGAL library, and will not be compiled.")

endif()

