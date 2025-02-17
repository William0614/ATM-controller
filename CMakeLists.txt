cmake_minimum_required(VERSION 3.10)
project(ATM)

set(CMAKE_CXX_STANDARD 14)

# Main ATM executable
add_executable(ATM
    src/main.cpp
    src/atm.cpp
    src/bankAPI.cpp
    src/account.cpp
    src/card.cpp
)

# GoogleTest
add_subdirectory(external/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Test executable (add ATM source files to ensure linking)
add_executable(run_tests
    test/atm_test.cpp
    src/atm.cpp
    src/bankAPI.cpp
    src/account.cpp
    src/card.cpp
)

# Link test executable with GoogleTest and pthread (for some platforms)
target_link_libraries(run_tests gtest gtest_main pthread)
