//
// Created by uic70278 on 4/11/2022.
//

#include "Catalog.h"

Catalog & Catalog :: operator += ( Student const & student ) {
    this->studenti[this->nrStudenti] = student;
    this->nrStudenti ++;

    return * this;
}

int Catalog :: GetCount() const {
    return this->nrStudenti;
}

#include <cstring>
Student & Catalog :: operator [] ( char const * nume ) {
    for ( int i = 0; i < this->nrStudenti; ++ i ) {
        if ( strcmp ( nume, this->studenti[i].GetName() ) == 0 ) {
            return this->studenti[i];
        }
    }
}

Student & Catalog :: operator [] ( int index ) {
    return this->studenti[index];
}
