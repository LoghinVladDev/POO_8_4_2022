//
// Created by loghin on 4/9/22.
//

#include <iostream>
#include "SimpleList.h"

using namespace std;

int main() {
    SimpleList<int> l = { 1,3,5,7,9 };
    for (auto i : l) cout << i << " "; cout << endl;
    ((((l += 2) += 4) += 6) += 8);
    for (auto i : l) cout << i << " "; cout << endl;
    l += {1, 2, 3};
    for (auto i : l) cout << i << " "; cout << endl;
    for (auto &i : l) if (i < 3) i = 0;
    for (auto i : l) cout << i << " "; cout << endl;
    cout << "Valoare 0 se gaseste in lista de " << l[0] << " ori " << endl;
    cout << "Valoare 7 se gaseste in lista de " << l[7] << " ori " << endl;
    cout << "Lista are " << (int)l << " elemente" << endl;
    l -= 0;
    for (auto i : l) cout << i << " "; cout << endl;
    (l -= 3) -= 4;
    for (auto i : l) cout << i << " "; cout << endl;
    return 0;
}