//
// Created by loghin on 4/9/22.
//

#include <cstdio>
#include "Catalog.h"

int main () {

    Catalog c = "math";

    ( (c += { "Popescu", 10 }) += { "Ionescu", 9 } ) += { "Popescu", 8 };

    printf (
            "Catalog : %s ( %d students ==> average : %.2f )\n",
            ( char const * ) c,
            ( int ) c,
            ( float ) c
    );

    for ( auto a : c ) {
        a.Print ();
    }

    if ( c == "Ionescu" ) {
        printf ("Ionescu exists in catalog !\n");
    } else {
        printf ("Ionescu DOES NOT exist in catalog !\n");
    }

    if ( c == "Georgescu" ) {
        printf ("Georgescu exists in catalog !\n");
    } else {
        printf ("Georgescu DOES NOT exist in catalog !\n");
    }

    c += { "Marin", 8 };
    c += { "Popovici", 7 };

    c -= "Popescu";

    printf (
            "Catalog : %s ( %d students )\n",
            ( char const * ) c,
            ( int ) c
    );

    for ( auto a : c ) {
        a.Print ();
    }

    return 0;
}