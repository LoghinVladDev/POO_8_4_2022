//
// Created by loghin on 4/9/22.
//

#include "Student.h"
#include <cstdio>

/// contstructorul doar initializeaza valorile
/// Also, cu toate ca noi nu folosim string-uri dedicate,
/// ( adica nu avem nume [ marime ] in Student.h, putem salva )
/// adresele string-urilor primite, intrucat ele vor exista pana la finalul programului
/// ( fiind date din main )
Student :: Student ( char const * pName, int grade ) :
        pName ( pName ),
        grade ( grade ) {

}

/// refer to format in Student.h
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

/// doua functii necesare din cerinta.
/// Nu avem voie sa folosim din cstring - strlen, strcmp
int stringLength ( char const * pString ) {

    /// ne amintim, orice string se termina cu un null character ( \0 ) - caracterul cu valoarea 0

    /// => parcurgem string-ul caracter cu caracter pana dam de \0. Pozitia acestuia reprezinta si lungimea
    /// intrucat daca acesta se afla la pozitia N, inaintea lui avem de la 0 ... N-1 => N caractere
    int length = 0;

    /// pana dam de el
    while ( pString[length] != '\0' ) {

        /// marim index ( length )
        length ++;
    }

    return length;
}

/// comparatia de string-uri -> strcmp, doar pe cazul egal
/// true -> egale, false otherwise
bool stringEquals ( char const * pLeft, char const * pRight ) {

    /// intai aflam lungimile, daca difera, string-urile nu sunt egale
    int leftLenght  = stringLength ( pLeft );
    int rightLenght = stringLength ( pRight );

    if ( leftLenght != rightLenght ) {
        return false;
    }

    /// apoi caracter cu caracter, cand dam de unul diferit, string-urile nu sunt egale
    /// ( aici suntem pe cazul in care lungimime SUNT egale, daca nu erau,
    /// se iesea din functie )
    ///
    for ( int i = 0; i < leftLenght; ++ i ) {
        if ( pLeft [i] != pRight[i] ) {
            return false;
        }
    }

    /// daca toate caracterele sunt la fel, si lungimile sunt egale => sirurile sunt egale
    return true;
}

bool Student :: is ( char const * pName ) {

    /// un student este numit -> pName ( parametrul ce contine numele ) daca string-urile
    /// numelui lui si cel primit sunt egale
    return stringEquals ( this->pName, pName );
}
