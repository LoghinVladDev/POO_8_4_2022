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
//
//template < class T >
//T sum ( T a, T b ) {
//    return a + b;
//}
//
///**
// *  int sum (int, int)
// *  float sum (float, float)
// */
//
//int main () {
//    cout << sum (4, 3) << '\n';
//    cout << sum (4.3f, 3.1f) << '\n';
//}
//
//#include "test_template.h"
//
//int main () {
//    cout << sum (4, 3) << '\n';
//    cout << sum (4.3f, 3.1f) << '\n';
//    cout << sum (4, 3.14f) << '\n';
//}
//
//#include "Array.h"
//
//int main () {
//
//    Array < int > arr;
//    Array < float > fArr;
//
//    arr += 3;
//    ( arr += 5 ) += 7;
//
//    /// arr = { 3, 5, 7 };
//
//    arr [1] = 5;
//    arr [0] = 8;
//
//    /// arr = { 8, 5, 7 };
//
//    cout << "Lungimea array-ului : " << arr.length() << '\n';
//
//    /// 3
//
//    cout << "Primul element din array : " << arr.front () << '\n';
//
//    /// 8
//
//    cout << "Utlimul element din array : " << arr.back () << '\n';
//
//    /// 7
//
//}

#include <iostream>
#include "SimpleList.h"

using namespace std;

int main() {
    /**
     * O:
        9 7 5 3 1
        8 6 4 2 9 7 5 3 1
        3 2 1 8 6 4 2 9 7 5 3 1
        3 0 0 8 6 4 0 9 7 5 3 0
        Valoare 0 se gaseste in lista de 4 ori
        Valoare 7 se gaseste in lista de 1 ori
        Lista are 12 elemente
        3 8 6 4 9 7 5 3
        8 6 9 7 5
     */

    SimpleList<int> l = { 1,3,5,7,9 };
    for (auto i : l) cout << i << " "; cout << endl;
    ((((l += 2) += 4) += 6) += 8);
    for (auto i : l) cout << i << " "; cout << endl;
    l += {1, 2, 3};
    for (auto i : l) cout << i << " "; cout << endl;
    for (auto & i : l) if (i < 3) i = 0;
    for (auto i : l) cout << i << " "; cout << endl;
    cout << "Valoare 0 se gaseste in lista de " << l[0] << " ori " << endl;
    cout << "Valoare 7 se gaseste in lista de " << l[7] << " ori " << endl;
    cout << "Lista are " << (int)l << " elemente" << endl;
//    l -= 0;
    for (auto i : l) cout << i << " "; cout << endl;
//    (l -= 3) -= 4;
    for (auto i : l) cout << i << " "; cout << endl;
//
//    for (
//            auto it = l.begin();
//            it != l.end();
//            ++ it
//    ) {
//        int element = * it;
//    }//

//    for (
//            auto it = l.begin();
//            it != l.end();
//            ++ it
//    ) {
//        int & element = * it;
//    }

    return 0;
}