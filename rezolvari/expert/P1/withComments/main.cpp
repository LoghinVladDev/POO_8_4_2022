//
// Created by loghin on 4/9/22.
//

#include <cstdio>
#include "Catalog.h"

/**
 * Daca va uitati aici, poate mai vreti sa invatati cateva
 * unele poate nu o sa aiba sens, but you can also always ask
 *
 * Exista urmatoarele probleme in solutia advanced totusi
 *
 *  1) Daca avem un catalog const, acesta nu poate fi iterat!
 *      intrucat begin() si end() nu sunt functii const
 *  2) Nu-mi plac alocarile statice de array-uri. ce se intampla daca bag 257 studenti
 *      sau apare un student cu un nume mai mare de 1024 caractere, ceva print cu 28 de nume?
 *
 *  3) Nu-mi plac functiile globale ( StringFunctions ). Ar trebui o clasa
 *  4) Code is still complex. Se poate "simplifica"
 *  5) Avem ocazia sa mai aflam si de alte cuvinte din c++, vom vedea pt curiosi
 *
 *  This might be a bit too much, dar in caz ca exista pe viitor curiosi,
 *  sau care vor sa stie mai multe,
 *  resurse sa existe.
 *
 *  Nu va demoralizati daca nu intelegeti, e normal. Learning programming is not a short journey
 */

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