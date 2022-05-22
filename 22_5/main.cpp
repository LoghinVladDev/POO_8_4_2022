//
// Created by vladl on 5/22/2022.
//

#include <iostream>
#include "Array.h"

using namespace std;

//class DivideByZeroException : public std :: exception {
//public:
//    char const * what() const noexcept {
//        return "Cannot divide by zero!";
//    }
//};
//
//class CustomException : public std :: exception {
//public:
//    char const * what() const noexcept override {
//        return "1";
//    }
//};
//
//void checkIfDivideByZero ( int b ) {
//    if ( b == 0 ) {
//        throw DivideByZeroException();
//    }
//
//    if ( b == 5 ) {
//        throw CustomException();
//    }
//}
//
//int impartire ( int a, int b ) {
//    checkIfDivideByZero(b);
//    return a / b;
//}

int main () {
//
//    try {
//
//        std :: cout << impartire ( 10, 2 ) << '\n';
//
//        try {
//            std :: cout << impartire ( 10, 0 ) << '\n';
//        } catch ( std :: exception & exception ) {
//            std :: cout << "Error caught, expected : " << exception.what() << '\n';
//        }
//
//        std :: cout << impartire ( 10, 5 ) << '\n';
//
//        /// Pear pear;
//        /// Apple apple;
//        /// Fruit & rPear = pear;
//        /// Fruit & rApple = apple;
//    } catch ( std :: exception & exception ) {
//        std :: cout << "Error caught : " << exception.what() << '\n';
//    }

//    catch ( DivideByZeroException & exception ) {
//        std :: cout << "Error caught, unexpected : " << exception.what() << '\n';
//    } catch ( CustomException & exception ) {
//        std :: cout << "Custom Exception caught : " << exception.what() << '\n';
//    }

    /// ctor implicit ( default )
    Array < int > vector;

    /// operator +=
    vector += 3;
    vector += 4;
    vector += 5;
    vector += 8;
    vector += 9;

    /// 3, 4 ,5 ,8, 9

    /// operator []
    std :: cout << vector [3] << '\n'; /// 8

    try {
        vector[-1];
    } catch ( std ::exception & e ) {
        std :: cout << e.what() << '\n';
    }

    try {
        vector[5];
    } catch ( std ::exception & e ) {
        std :: cout << e.what() << '\n';
    }


    /// ~Array () <- el este declarat in clasa
    /// va fi apelat aici!!!!
    return 0;
}
