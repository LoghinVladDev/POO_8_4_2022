cmake_minimum_required(VERSION 3.16)
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
        rezolvari/basic/Problema_1/withoutComments/main.cpp
        rezolvari/basic/Problema_1/withoutComments/Punct.h
        rezolvari/basic/Problema_1/withoutComments/Rectangle.cpp
        rezolvari/basic/Problema_1/withoutComments/Rectangle.h
)

add_executable(
        advanced_Probelma_1
        rezolvari/advanced/Problema_1/withoutComments/main.cpp
        rezolvari/advanced/Problema_1/withoutComments/Punct.h
        rezolvari/advanced/Problema_1/withoutComments/Punct.cpp
        rezolvari/advanced/Problema_1/withoutComments/Rectangle.cpp
        rezolvari/advanced/Problema_1/withoutComments/Rectangle.h
)

add_executable(
        basic_Probelma_4
        rezolvari/basic/Problema_4/withoutComments/main.cpp
        rezolvari/basic/Problema_4/withoutComments/Propozitie.cpp
        rezolvari/basic/Problema_4/withoutComments/Propozitie.h
)

add_executable(
        basic_Probelma_5
        rezolvari/basic/Problema_5/withoutComments/main.cpp
        rezolvari/basic/Problema_5/withoutComments/SimpleList.h
)

add_executable(
        10_4
        10_4/main.cpp
)

add_executable(
        11_4
        11_4/main.cpp 11_4/Catalog.cpp 11_4/Catalog.h 11_4/Student.cpp 11_4/Student.h
)

add_executable (
        9_5
        9_5/main.cpp
        9_5/Phrase.cpp
)

add_executable (
        22_5
        22_5/main.cpp
)

add_executable(
        27_5
        27_5/main.cpp
)

add_executable(
        28_5
        28_5/main.cpp
        28_5/Biblioteca.cpp
        28_5/Biblioteca.h
        28_5/Carte.cpp
        28_5/Carte.h
        28_5/Revista.cpp
        28_5/Revista.h
        28_5/Roman.cpp
        28_5/Roman.h
)
