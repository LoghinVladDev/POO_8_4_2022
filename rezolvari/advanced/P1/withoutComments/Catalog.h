//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_CATALOG_H
#define POO_8_4_2022_CATALOG_H

#include "Student.h"
#include "StringFunctions.h"

#define STUDENT_MAX_COUNT 256

class Catalog {
private:
    char         title [ STRING_MAX_LEN ];

    Student      students [ STUDENT_MAX_COUNT ];
    int          studentCount;

public:
    Catalog ( char const * pTitle );
    Catalog & operator += ( Student const & student );
    Catalog & operator -= ( char const * pStudentName );

    operator char const * () const;
    operator int () const;
    operator float () const;

    bool operator == ( char const * pStudentName ) const;

    class Iterator {
    private:
        Catalog * pCatalog;
        int       indexInCatalog;

    public:
        Iterator ( Catalog * pCatalog, int index );

        Iterator &      operator ++ ();
        Iterator        operator ++ (int);
        Student &       operator * () const;
        bool            operator != ( Iterator const & it ) const;
    };

    Iterator begin ();
    Iterator end ();
};


#endif //POO_8_4_2022_CATALOG_H
