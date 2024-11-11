cmake_minimum_required(VERSION 3.29)
project(icpc)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        console
        Basics/Basics.cpp
)
add_executable(A_Alices_Adventures_in_Chess "Codeforces/Codeforces - Codeforces Round 986 Div 2/A_Alices_Adventures_in_Chess.cpp")
add_executable(B_Alices_Adventures_in_Permuting "Codeforces/Codeforces - Codeforces Round 986 Div 2/B_Alices_Adventures_in_Permuting.cpp")