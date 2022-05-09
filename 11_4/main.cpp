//
// Created by uic70278 on 4/11/2022.
//

#include <iostream>
#include "Student.h"
#include "Catalog.h"
Catalog c; /// se creeaza un obiect c Catalog

int main () {
    c+= {"Andrei"}; /// introducem un student cu numele Andrei -> Student ....
    (c+= {"Roxana"}) += {"Sorin"};
    c["Andrei"]["matematica"] = 8; /// atribuim nota la materie
    //// c.getStudent("Andrei").getGrade("matematica") = 8;
    //// catalogul are indexare ce obtine un student                -> c["Andrei"] -> Student &
    //// studentul are indexare ce obtine nota pentru o materie     -> s["matematica"] -> int &

    c["Andrei"]["romana"] = 7;
    c["Andrei"]["franceza"] = 6;
    c["Roxana"]["matematica"] = 9;
    c["Roxana"]["romana"] = 10;
    c["Sorin"]["sport"] = 5;
    c["Sorin"]["romana"] = 9;

    std :: cout << "Total studenti: " << c.GetCount () << std::endl;
    for ( int index = 0; index < c.GetCount (); ++ index ) {

        /// c[index] = Student &
        /// s.GetName ()
        std :: cout << "Nume : " << c[index].GetName () << std :: endl;
        /// operator cast float
        std :: cout << "Media : " << (float) c[index] << std :: endl;
        //// s.PrintNote ()
        c[index].PrintNote();
    }

    return 0;
}