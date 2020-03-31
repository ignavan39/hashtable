#include "gtest/gtest.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    //add_executable(Task2 tst/main.cpp src/RingBuffer.cpp src/RingBuffer.h)
}