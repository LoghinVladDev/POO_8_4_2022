//
// Created by loghin on 4/9/22.
//

#include <cstdio>
#include "Catalog.h"

/**
 * new stuff fata de basic
 *
 * Chiar daca e fain sa salvezi adresele string-urilor direct,
 *  ideal nu o facem.
 *
 * In solutia de advanced avem:
 *      1) Obiectele Catalog, Student au string-uri dedicate pentru nume & titlu
 *      2) Consecinta, implementare de strcpy si mutare a functiilor de string-uri in .h/.cpp-urile StringFunctions
 *      3) const.
 *          3.1) Aplicare const nr. 1
 *              Daca avem o functie ( i.e. bool Catalog :: operator == ( Student ) ), aceasta normal
 *              creeaza o copie pentru obiectul student primit ca si parametru, ce consuma timp & spatiu pe stiva
 *                  => putem mai degraba sa primim o 'referinta' la obiectul respectiv, e un pointer mascat
 *
 *                  => Student &
 *                  ideal nu am vrea sa fie modificabil in operator ==, asadar referinta va fi la Student constant
 *                          --- reminder, const se propaga la stanga, pe Student ---
 *                  => Student const &
 *          3.2) Aplicare const nr. 2
 *              Daca avem o functie precum int Student :: getGrade ()
 *                  Aceasta functie nu modifica obiectul => putem preciza ca functia getGrade
 *                  poate fi aplicata pe un obiect ne-modificabil = const
 *
 *                  => int Student :: getGrade () const
 *                                                  ^ dupa functie
 *
 *                  Asadar, daca ( precum in Catalog :: operator float (), unde Catalog e const =>
 *                          in consecinta si membrii sunt const => students e Student const [] )
 *
 *                          putem folosi pe Studentii din array-ul de Student const functia getGrade ()
 *
 *    4) Simplificari in logica.
 *    5) Omiterea numelui parametrilor in .h - este posibila, accelereaza putin scrisul
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