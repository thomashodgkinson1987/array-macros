add_executable(int-array-tests
    test_int_array.c
    int_array.c
)
target_link_libraries(int-array-tests PRIVATE array-macros)
add_test(NAME int-array-tests COMMAND int-array-tests)
