ADD_EXECUTABLE(fvm-test fvm_test.c)
ADD_TEST(fvm-test fvm-test)
TARGET_LINK_LIBRARIES(fvm-test fvm)
