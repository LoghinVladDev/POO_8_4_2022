#include <iostream>

using namespace std;

//
//void f ( int x ) { /// pass by value
//    x = 3;
//}
//
//void g ( int & x ) { /// pass by reference
//    x = 7;
//}
//
//int main () {
//
//    int x = 1;
//    f(x);
//    cout << x << '\n'; // 1
//    g(x);
//    cout << x << '\n';
//
//    return 0;
//}
//
//class X {
//private:
//    int unIntreg = 3;
//
//public:
//    int getIntreg () {          /// return by value
//        return this->unIntreg;
//    }
//};
//
//class Y {
//private:
//    int unIntreg = 5;
//
//public:
//    int & getIntreg () {        /// return by reference
//        return this->unIntreg;
//    }
//};
//
//int main () {
//    X x;
//    Y y;
//
//    std :: cout << x.getIntreg() << '\n';
//    std :: cout << y.getIntreg() << '\n';
//
//    y.getIntreg() = 7;
//
//
//class X {
//private:
//    int unIntreg = 0;
//public:
//
//    int getIntreg() {
//        return unIntreg;
//    }
//
//    X & maresteIntreg ( int valoare = 1 ) {
//        this->unIntreg += valoare;
//        return * this;
//    }
//
//    X & operator += ( int valoare ) {
//        this->unIntreg += valoare;
//        return * this;
//    }
//};
//
//int main () {
//    X unNumeDeVariabilaFoarteFoarteLung;
//
//    cout << unNumeDeVariabilaFoarteFoarteLung.getIntreg() << '\n';
//
//    unNumeDeVariabilaFoarteFoarteLung
//        .maresteIntreg(1)
//        .maresteIntreg(1)
//        .maresteIntreg(1);
//
//    cout << unNumeDeVariabilaFoarteFoarteLung
//        .maresteIntreg(2)
//        .maresteIntreg(7)
//        .getIntreg() << '\n';
//    /// 12
//    ( ( unNumeDeVariabilaFoarteFoarteLung += 2 ) += 3 ) += 4;
//
//    cout << unNumeDeVariabilaFoarteFoarteLung.getIntreg() << '\n';
//}

