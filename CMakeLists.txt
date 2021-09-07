cmake_minimum_required(VERSION 3.11)

project(maroon_mapper 	VERSION 1.0
			LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include(FetchContent)
include(GNUInstallDirs)

find_package(bioparser 3.0.13 QUIET)
if (NOT bioparser_FOUND)
  FetchContent_Declare(
    bioparser
    GIT_REPOSITORY https://github.com/rvaser/bioparser
    GIT_TAG 3.0.13)

  FetchContent_GetProperties(bioparser)
  if (NOT bioparser_POPULATED)
    FetchContent_Populate(bioparser)
    add_subdirectory(
      ${bioparser_SOURCE_DIR}
      ${bioparser_BINARY_DIR}
      EXCLUDE_FROM_ALL)
  endif ()
endif ()


#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
#FetchContent_MakeAvailable(googletest)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#enable_testing()

add_executable(maroon_mapper
	src/main.cpp
)

target_link_libraries(maroon_mapper
	bioparser::bioparser
#	gtest_main
)

#include(GoogleTest)
#gtest_discover_tests(maroon_mapper)

target_compile_definitions(maroon_mapper PRIVATE VERSION="${PROJECT_VERSION}")

install(TARGETS maroon_mapper DESTINATION ${CMAKE_INSTALL_BINDIR})

# Testing
#enable_testing()
