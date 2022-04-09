//
// Created by loghin on 4/9/22.
//

#include "Student.h"
#include "StringFunctions.h"
#include <cstdio>

Student :: Student ( char const * pName, int grade ) :
        grade ( grade ) {

    stringCopy ( this->name, pName );
}

void Student :: Print () const {
    printf (
            "Student: %s => Grade : %d\n",
            this->name,
            this->grade
    );
}

char const * Student :: getName () const {
    return this->name;
}

int Student :: getGrade () const {
    return this->grade;
}

bool Student :: is ( char const * pName ) const {
    return stringEquals ( this->name, pName );
}
