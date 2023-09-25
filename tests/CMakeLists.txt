set(target_name tests)

find_package(GTest CONFIG REQUIRED)
add_executable(${target_name} example.cpp)
target_link_libraries(${target_name} PRIVATE GTest::gtest GTest::gtest_main)
install(TARGETS ${target_name} DESTINATION bin)
install(FILES $<TARGET_RUNTIME_DLLS:${target_name}> DESTINATION bin) 