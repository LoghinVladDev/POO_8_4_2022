//
// Created by loghin on 4/9/22.
//

#include "Student.h"
#include <cstdio>

Student :: Student ( char const * pName, int grade ) :
        pName ( pName ),
        grade ( grade ) {

}

void Student :: Print () {
    printf (
            "Student: %s => Grade : %d\n",
            this->pName,
            this->grade
    );
}

char const * Student :: getName () {
    return this->pName;
}

int Student :: getGrade () {
    return this->grade;
}

int stringLength ( char const * pString ) {
    int length = 0;

    while ( pString[length] != '\0' ) {
        length ++;
    }

    return length;
}

bool stringEquals ( char const * pLeft, char const * pRight ) {

    int leftLenght  = stringLength ( pLeft );
    int rightLenght = stringLength ( pRight );

    if ( leftLenght != rightLenght ) {
        return false;
    }

    for ( int i = 0; i < leftLenght; ++ i ) {
        if ( pLeft [i] != pRight[i] ) {
            return false;
        }
    }

    return true;
}

bool Student :: is ( char const * pName ) {
    return stringEquals ( this->pName, pName );
}
