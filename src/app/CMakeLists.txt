if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_FIND_LIBRARY_CUSTOM_LIB_SUFFIX ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

set(TARGET_NAME test_for_cmake_with_qt)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
message(STATUS "Qt5_DIR: ${Qt5_DIR}")
message(STATUS "Qt5Core_DIR: ${Qt5Core_DIR}")

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

add_executable(${TARGET_NAME} ${PROJECT_SOURCES})
target_link_libraries(${TARGET_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

set_target_properties(${TARGET_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 将 Qt 库的 DLL 文件复制到生成目录中
get_target_property(QT_DLL_LOCATION_Core Qt5::Core IMPORTED_LOCATION_RELEASE)
get_target_property(QT_DLL_LOCATION_Gui Qt5::Gui IMPORTED_LOCATION_RELEASE)
get_target_property(QT_DLL_LOCATION_Widgets Qt5::Widgets IMPORTED_LOCATION_RELEASE)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${QT_DLL_LOCATION_Core}
    ${QT_DLL_LOCATION_Gui}
    ${QT_DLL_LOCATION_Widgets}
    $<TARGET_FILE_DIR:${TARGET_NAME}>
)