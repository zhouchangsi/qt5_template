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
# TODO: bug
# install(TARGETS ${target_name}
#     RUNTIME_DEPENDENCIES
#     # exclude whatever these are?
#     PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
#     # exclude 32 bit versions of dependencies maybe?
#     POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
# )
# install(FILES $<TARGET_RUNTIME_DLLS:${target_name}> DESTINATION bin) # install runtime dlls
# add_custom_command(
#     TARGET ${target_name} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     $<TARGET_RUNTIME_DLLS:${target_name}>
#     $<TARGET_FILE_DIR:${target_name}>
#     COMMAND_EXPAND_LISTS
# )

# deploy qt using windeployqt
add_custom_command(TARGET ${target_name} POST_BUILD COMMAND  windeployqt $<TARGET_FILE:${target_name}> --no-compiler-runtime --no-opengl-sw --no-angle --no-system-d3d-compiler --no-webkit2 --no-quick-import --no-translations --no-patchqt)
# install runtime dlls end