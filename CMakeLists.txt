cmake_minimum_required(VERSION 3.22)
project(POO_8_4_2022)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        basic_P1
        rezolvari/basic/P1/withoutComments/main.cpp
        rezolvari/basic/P1/withoutComments/Catalog.cpp
        rezolvari/basic/P1/withoutComments/Catalog.h
        rezolvari/basic/P1/withoutComments/Student.h
        rezolvari/basic/P1/withoutComments/Student.cpp
)

add_executable(
        advanced_P1
        rezolvari/advanced/P1/withoutComments/main.cpp
        rezolvari/advanced/P1/withoutComments/Catalog.cpp
        rezolvari/advanced/P1/withoutComments/Catalog.h
        rezolvari/advanced/P1/withoutComments/Student.h
        rezolvari/advanced/P1/withoutComments/Student.cpp
        rezolvari/advanced/P1/withoutComments/StringFunctions.h
        rezolvari/advanced/P1/withoutComments/StringFunctions.cpp
)

add_executable(
        expert_P1
        rezolvari/expert/P1/withoutComments/main.cpp
        rezolvari/expert/P1/withoutComments/Catalog.cpp
        rezolvari/expert/P1/withoutComments/Catalog.h
        rezolvari/expert/P1/withoutComments/Student.h
        rezolvari/expert/P1/withoutComments/Student.cpp
        rezolvari/expert/P1/withoutComments/String.cpp
        rezolvari/expert/P1/withoutComments/String.h
)

add_executable(
        basic_Probelma_1
        rezolvari/basic/Problema_1/main.cpp
        rezolvari/basic/Problema_1/Punct.h
        rezolvari/basic/Problema_1/Rectangle.cpp
        rezolvari/basic/Problema_1/Rectangle.h
)

add_executable(
        advanced_Probelma_1
        rezolvari/advanced/Problema_1/main.cpp
        rezolvari/advanced/Problema_1/Punct.h
        rezolvari/advanced/Problema_1/Punct.cpp
        rezolvari/advanced/Problema_1/Rectangle.cpp
        rezolvari/advanced/Problema_1/Rectangle.h
)