//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STUDENT_H
#define POO_8_4_2022_STUDENT_H

#include "StringFunctions.h"

class Student {
private:
    char         name [ STRING_MAX_LEN ];
    int          grade;

public:
    Student () = default;
    Student ( char const * pName, int grade );
    void Print () const;

    char const * getName () const;
    int          getGrade () const;

    bool is ( char const * ) const;
};


#endif //POO_8_4_2022_STUDENT_H
