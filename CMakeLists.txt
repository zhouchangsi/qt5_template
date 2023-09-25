cmake_minimum_required(VERSION 3.21)
project(cpp_tempalte CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

# enable windows shared library export
if (WIN32)
  set(WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_subdirectory(src)
add_subdirectory(tests)