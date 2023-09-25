set(target_name app)

# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

add_subdirectory(ui)

add_executable(${target_name} main.cpp)
target_link_libraries(${target_name} ui)

install(TARGETS ${target_name} 
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

# install runtime dlls
# deploy qt using windeployqt
add_custom_command(TARGET ${target_name} POST_BUILD COMMAND  windeployqt $<TARGET_FILE:${target_name}> --no-compiler-runtime --no-opengl-sw --no-angle --no-system-d3d-compiler --no-webkit2 --no-quick-import --no-translations --no-patchqt)
if(WIN32) 
    set(target_file ${CMAKE_INSTALL_PREFIX}/bin/${target_name}.exe)
    install(CODE "execute_process(COMMAND windeployqt ${target_file} --no-compiler-runtime --no-opengl-sw --no-angle --no-system-d3d-compiler --no-webkit2 --no-quick-import --no-translations --no-patchqt)")
endif()
# install runtime dlls end