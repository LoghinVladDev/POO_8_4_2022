//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_CATALOG_H
#define POO_8_4_2022_CATALOG_H

#include "Student.h"

#define STUDENT_MAX_COUNT 256

class Catalog {
private:
    char const * pTitle;

    Student      students [ STUDENT_MAX_COUNT ];
    int          studentCount;

public:
    Catalog ( char const * pTitle );
    Catalog & operator += ( Student student );
    Catalog & operator -= ( char const * pStudentName );

    operator char const * ();
    operator int ();
    operator float ();

    bool operator == ( char const * pStudentName );

    class Iterator {
    private:
        Catalog * pCatalog;
        int       indexInCatalog;

    public:
        Iterator ( Catalog * pCatalog, int index );
        Iterator operator ++ ();
        Student  operator * ();
        bool     operator != ( Iterator it );
    };

    Iterator begin ();
    Iterator end ();
};


#endif //POO_8_4_2022_CATALOG_H
