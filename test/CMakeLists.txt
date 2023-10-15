add_executable(test1 test.cpp)

# target_link_libraries(test lib)

# add_test(Name test1 COMMAND "$<TARGET_FILE:test1>")
add_test(Name test1 COMMAND test1)
