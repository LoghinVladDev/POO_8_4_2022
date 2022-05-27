//
// Created by vladl on 5/22/2022.
//

#include <iostream>
#include "Array.h"

using namespace std;

class DivideByZeroException : public std :: exception {
public:
    char const * what() const noexcept {
        return "Cannot divide by zero!";
    }
};

class CustomException : public std :: exception {
public:
    char const * what() const noexcept override {
        return "1";
    }
};

void checkIfDivideByZero ( int b ) {
    if ( b == 0 ) {
        throw DivideByZeroException();
    }

    if ( b == 5 ) {
        throw CustomException();
    }
}

int impartire ( int a, int b ) {
    checkIfDivideByZero(b);
    return a / b;
}

int compareByGreater (int const &a, int const& b) {
    if ( a < b ) {
        return 1;
    }

    if ( a == b ) {
        return 0;
    }

    return -1;
}

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

    vector.sort(compareByGreater);

    auto indexOf5 = vector.find(5, compareByGreater);
    std :: cout << "Index of 5 : " << indexOf5 << '\n';

    try {
        vector.find(7, compareByGreater);
    } catch ( std :: exception & e ) {
        std :: cout << e.what() << '\n';
    }

    class {
    public:
        int operator () (int a, int b){

            if ( a < b ) {
                return 1;
            }

            return -1;
        }
    } sorter;

    vector.sort([](int a, int b){

        if ( a > b ) {
            return 1;
        }

        return -1;
    });

    vector.sort(sorter);

    for ( int i = 0; i < vector.getSize(); ++ i ) {
        std :: cout << vector[i] << '\n';
    }
//
//    /// 3, 4 ,5 ,8, 9
//
//    /// operator []
//    std :: cout << vector [3] << '\n'; /// 8
//
//    try {
//        vector[-1];
//    } catch ( std ::exception & e ) {
//        std :: cout << e.what() << '\n';
//    }
//
//    try {
//        vector[5];
//    } catch ( std ::exception & e ) {
//        std :: cout << e.what() << '\n';
//    }
//
//    /// ~Array () <- el este declarat in clasa
//    /// va fi apelat aici!!!!
//
//
//    /// addendum la sort-ul de la 89
//
////    int (* pfn) (int, int) = & impartire; varianta handicapati a.k.a cum se facea in C
//// c++
////    using ImpartireType = int (*) (int, int);
////    ImpartireType pfn = & impartire;
//
////    int x = pfn (3, 2);
//
//////  if ( compare ( * this->array[i], * this->array[j] ) > 0 ) ...
//
//    auto compareFunction = [](int const & a, int const & b) {
//        if ( a > b ) { return 1; }
//        else if ( a < b ) { return -1; }
//        return 0;
//    };
//
//    vector.sort ( compareFunction );
//
//    class IntComparator : public Compare {
//        int CompareElements ( void * e1, void * e2 ) override {
//            int * pE1 = (int *) e1;
//            int * pE2 = (int *) e2;
//
//            if ( * pE1 > * pE2 ) { return 1; }
//            else if ( * pE1 < * pE2 ) { return -1; }
//            return 0;
//        }
//    };
//
//    auto digitCompareFunction = [](int const & a, int const & b) {
//        auto digitSum = [] ( int a ) {
//            int sum = 0;
//            while ( a > 0 ) {
//                sum += a %10;
//                a/=10;
//            }
//
//            return sum;
//        };
//
//        int sumA = digitSum(a);
//        int sumB = digitSum(b);
//
//        if ( sumA > sumB ) { return 1; }
//        else if ( sumA < sumB ) { return -1; }
//        return 0;
//    };
//
//    IntComparator comparator;
//    vector.sort ( & comparator );
//
//    vector.sort ( digitCompareFunction );

    return 0;
}
