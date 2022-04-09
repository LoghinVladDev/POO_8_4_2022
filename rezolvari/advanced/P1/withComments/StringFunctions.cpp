//
// Created by loghin on 4/9/22.
//

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

void stringCopy ( char * pDest, char const * pRight ) {

    /// might look weird, bear with me
    /// cat timp la adresa curenta nu am caracter terminal in sursa

    while ( * pRight != '\0' ) {

        /// copiez la adresa destinatie caracterul curent
        * pDest = * pRight;

        /// avansez in ambele adrese pentru a copia urm. caracter
        ++ pDest;
        ++ pRight;
    }

    /// adresele NU se modifica in apel, intrucat parametrii sunt COPII ale param. originali
    /// nu au & => sunt SIGUR copii, chiar si daca sunt pointeri, nu uitam, defapt ele sunt doar
    /// numere cu un alt tip de date
}