add_executable(test1 test.cpp)

# target_link_libraries(test lib)

add_test(Name test COMMAND "$<TARGET_FILE:test>")
