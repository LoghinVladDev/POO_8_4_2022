//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STUDENT_H
#define POO_8_4_2022_STUDENT_H

#include "StringFunctions.h"

class Student {
private:
    /// la fel, string dedicat
    char         name [ STRING_MAX_LEN ];
    int          grade;

public:
    Student () = default;
    Student ( char const * pName, int grade );

    /// afisarea nu modifica obiectul
    void Print () const;

    /// getter nu modifica obiectul
    char const * getName () const;
    /// getter nu modifica obiectul
    int          getGrade () const;

    /// verificarea de echivalenta nu modifica obiectul
    bool is ( char const * ) const;
};


#endif //POO_8_4_2022_STUDENT_H
