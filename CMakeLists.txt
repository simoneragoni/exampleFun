# CMakeLists.txt for D0Lifetime module. It creates a library with dictionary and a main program
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

set(PACKAGE DictExample)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_PLATFORM_INDEPENDENT_CODE ON)

# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} $ENV{ROOTSYS}/etc/cmake)
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
#message(STATUS "CMAKE_PREFIX_PATH: " ${CMAKE_PREFIX_PATH})
message(STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS Graf3d Graf Gpad MathCore RIO Hist Tree Net Thread)

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

#--- Add dependency
#set( DEPENDENCIES Utilities)
#foreach( comp ${DEPENDENCIES} )
#	 include_directories(${CMAKE_SOURCE_DIR}/${comp}/include)
#	 add_subdirectory(${CMAKE_SOURCE_DIR}/build/${comp})
#endforeach( comp )

include_directories(include ${ROOT_INCLUDE_DIRS})
#--- Define the headers list
set(headers include/DictExample.h)
ROOT_GENERATE_DICTIONARY(G__${PACKAGE} ${headers} LINKDEF include/DictLinkDef.h)

#--- Define the source list
set(src_files DictExample.cpp)
foreach(src_file ${src_files})
   set(sources ${sources} src/${src_file})
endforeach()

#---Create a shared library with geneated dictionary
add_library(${PACKAGE} SHARED ${sources} G__${PACKAGE}.cxx)
target_link_libraries(${PACKAGE} ${ROOT_LIBRARIES})# ${DEPENDENCIES})


# - Add the Documentation subdirectory to the build
 #add_subdirectory(Documentation)



#---Create an executable
add_executable(CheckLoad ${CMAKE_SOURCE_DIR}/CheckLoad.C)
target_link_libraries(CheckLoad ${PACKAGE})
