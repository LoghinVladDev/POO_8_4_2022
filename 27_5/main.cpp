//
// Created by uic70278 on 5/27/2022.
//

#include <iostream>
/// a < b

bool less ( int a, int b ) {
    return a < b;
}

class LessType {
public:
    bool operator () (int a, int b) {
        return a < b;
    }
};

template < typename T >
T sum (T a, T b) {
    return a + b;
}

/// sum(3, 4) -> sum <int>
/// sum(3.5, 2.5) -> sum <double>

class IntArray {
public:
    template < typename SortFunc >
    void sort ( SortFunc func ) {
        std::cout << "Sort called\n";
    }
};

int main () {
    LessType lt;
    bool (* ltLambda) (int, int) = [](int a, int b) { return a < b; };

    std :: cout << lt(3, 5) << " " << less (3, 5);
    std :: cout << ltLambda(3, 5) << '\n';



    IntArray arr;
    arr.sort ( & less );
    arr.sort ( lt );
    arr.sort ( [](int a, int b){ return a < b; } );


//    bool (* lessPtr ) (int, int) = less;
    bool (* lessPtr ) (int, int) = & less;

//    typedef bool (* LessFuncType) (int, int);
    using LessFuncType = bool (*) (int, int);
    LessFuncType lessPtr2 = & less;

    std :: cout << "Less-uri\n";
    std :: cout << lessPtr ( 3, 5 ) << '\n';
    std :: cout << lessPtr2 ( 3, 5 ) << '\n';

    class A {
    public:
        bool less (int a, int b) {
            return a < b;
        }
    };



//
//    bool (A :: * pfn) (int, int) = & A :: less;
//
//    A a;
//    (a.*pfn)(3, 5);



    return 0;
}