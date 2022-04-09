//
// Created by loghin on 4/9/22.
//

#include "Student.h"
#include "String.h"
#include <cstdio>

Student :: Student ( char const * pName, int grade ) noexcept :
        name ( pName ),
        grade ( grade ) {
}

void Student :: Print () const noexcept {
    printf (
            "Student: %s => Grade : %d\n",
            this->name.c_str(),
            this->grade
    );
}

char const * Student :: getName () const noexcept {
    return this->name.c_str();
}

int Student :: getGrade () const noexcept {
    return this->grade;
}

bool Student :: is ( char const * pName ) const noexcept {
    return this->name == pName;
}
