cmake_minimum_required(VERSION 3.10)
project(ATM_Controller)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(atm
    src/main.cpp 
    src/atm.cpp 
    src/account.cpp 
    src/card.cpp 
    src/bankAPI.cpp
)