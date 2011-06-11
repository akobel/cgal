# Top level CMakeLists.txt for CGAL-branchbuild
cmake_minimum_required(VERSION 2.6.2)

# option for branch build

option( CGAL_BRANCH_BUILD "Create CGAL from branch" ON)

# search for some SCM

# TODO

if ( EXISTS ${CMAKE_SOURCE_DIR}/.svn )
  set ( CGAL_SCM_NAME "svn" )
else ()
  if ( NOT EXISTS ${CMAKE_SOURCE_DIR}/.git )
     message( ERROR "Neither 'svn' nor 'git' as SCM found" ) 
  endif() 
  set ( CGAL_SCM_NAME "git" )
endif()

if ( ${CGAL_SCM_NAME} STREQUAL "svn" )

  find_program(SVN_EXECUTABLE svn DOC "subversion command line client")

  function(Subversion_GET_URL dir variable)
    # use svnversion
    execute_process(COMMAND "${SVN_EXECUTABLE}" info --xml "${dir}"
      OUTPUT_VARIABLE ${variable}
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    string(REGEX REPLACE ".*<url>([^<]+)</url>.*" "\\1" ${variable} "${${variable}}")
    if(NOT variable)
      message("Warning: can not get the Subversion URL of directory ${dir}")
    endif()
    set(${variable} ${${variable}} PARENT_SCOPE)
  endfunction(Subversion_GET_URL)

  Subversion_GET_URL("${CGAL_INSTALLATION_PACKAGE_DIR}" CGAL_INSTALLATION_SVN_URL)
  string(REGEX REPLACE "(.*)/Installation" "\\1" CGAL_TMP_SVN_BRANCH_NAME "${CGAL_INSTALLATION_SVN_URL}")

  set ( CGAL_SCM_BRANCH_NAME "${CGAL_TMP_SVN_BRANCH_NAME}" )
endif()

if ( ${CGAL_SCM_NAME} STREQUAL "git" )

  find_program(GIT_EXECUTABLE git DOC "git command line client")

#  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} --git-dir=${CMAKE_SOURCE_DIR}/.git branch
#      OUTPUT_VARIABLE CGAL_GIT_BRANCH_OUT
#      OUTPUT_STRIP_TRAILING_WHITESPACE)
#  #foreach (line IN ${CGAL_GIT_BRANCH_OUT})
#  #  message (STATUS "Line: ${line}")
#    if ( STRING( REGEX MATCH "* " CGAL_GIT_BRANCH_LINE
#      ${CGAL_GIT_BRANCH_OUT} ) )
#       string ( REGEX REPLACE "# On branch " "" CGAL_GIT_BRANCH ${CGAL_GIT_BRANCH_LINE})
#    endif()
#  #endforeach()

  message( STATUS "Git branch ${CGAL_GIT_BRANCH}") 

  # TODO detect name
  set ( CGAL_SCM_BRANCH_NAME "n/a" )

endif()

# add option for duplicate file detection
option( CGAL_REPORT_DUPLICATE_FILES "Switch on to start (naive) detection of duplicate source- and headerfiles in packages" OFF)

# and finally start actual build
add_subdirectory( Installation )
