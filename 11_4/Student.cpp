//
// Created by uic70278 on 4/11/2022.
//

#include "Student.h"


#include <cstring>
Student :: Student () = default;

Student :: Student ( char const * nume ) :
        nrMaterii ( 0 ) {

    strcpy ( this->nume, nume );
}

const char * Student :: GetName () const {
    return this->nume;
}

int & Student :: operator [] ( char const * materie ) {

    for ( int i = 0; i < this->nrMaterii; ++ i ) {
        if ( strcmp ( materie, this->materii[i].nume ) == 0 ) {
            return this->materii[i].medie;
        }
    }

//    this->materii[this->nrMaterii].nume = materie;
    this->nrMaterii ++;
    strcpy ( this->materii[this->nrMaterii - 1].nume, materie );
    return this->materii[this->nrMaterii - 1].medie;
}

Student :: operator float () const {
    float sum = 0;
    for ( int i = 0; i < this->nrMaterii; ++ i ) {
        sum += this->materii[i].medie;
    }

    return sum / this->nrMaterii;
}

#include <iostream>
void Student :: PrintNote() const {
    for ( int i = 0; i < this->nrMaterii; ++ i ) {
        std :: cout << "\t" << this->materii[i].nume <<
        " => " << this->materii[i].medie << '\n';
    }
}
