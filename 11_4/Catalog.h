//
// Created by uic70278 on 4/11/2022.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"
#ifndef POO_8_4_2022_CATALOG_H
#define POO_8_4_2022_CATALOG_H

#include "Student.h"

#define STUDENT_MAX_COUNT 256

class Catalog {
private:
    Student studenti [ STUDENT_MAX_COUNT ];
    int     nrStudenti;

public:

    Catalog & operator += ( Student const & student );

    int GetCount () const;

    Student & operator [] ( char const * nume );
    Student & operator [] ( int index );

};


#endif //POO_8_4_2022_CATALOG_H

#pragma clang diagnostic pop