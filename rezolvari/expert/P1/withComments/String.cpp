//
// Created by loghin on 4/9/22.
//

#include <utility>
#include "String.h"

/// new word -> static
/// static, aplicat unei functii / variabile din SCOPE global
/// ( adica nu intr-un obiect )
/// inseamna PRIVAT pe sursa
/// i.e. folosibil doar in String.cpp, functia nu poate fi accesata dinafara
/// reason -> vrem sa refolosim astea, dar nu imi plac functiile la nivem global, asa ca le folosim
//// doar ca sa implementam obiectul String
//// ( nu e ca nu imi plac mie, e vorba de un standard + code smell )
//// (( code smell = calitatea codului overall + vulnerabilitati ))
static int stringLength ( char const * pString ) {
    int length = 0;

    while ( pString[length] != '\0' ) {
        length ++;
    }

    return length;
}

static bool stringEquals ( char const * pLeft, char const * pRight ) {

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

/// mica modificare aici
/// ca sa fac ceva similar operator =, returnez si adresa destinatie la final
//// reason, se poate face astfel
/// stringCopy ( a, stringCopy ( b, "xyz" ) );
/// si a si b vor fi "xyz"
static char * stringCopy ( char * pDest, char const * pSource ) {

    char * pOrigDest = pDest;

    while ( * pSource != '\0' ) {
        * pDest = * pSource;

        ++ pDest;
        ++ pSource;
    }

    * pDest = * pSource;

    return pOrigDest;
}

String :: String ( char const * pString ) noexcept {
    this->len = stringLength ( pString );

    /// folosite a lui stringCopy nou.
    /// alocam memorie, o dam la stringCopy, memoria cu string-ul copiat va veni in pString
    this->pString = stringCopy ( new char [ this->len + 1 ], pString );
}

String :: String ( String const & string ) noexcept {
    this->len = string.len;
    this->pString = stringCopy ( new char [ this->len + 1 ], string.c_str() );
}

String :: ~String () noexcept {
    /// daca am alocat memorie cu new ... [], dealocam cu delete [] !!!!!!!
    delete [] this->pString;
}

bool String :: operator == ( char const * pString ) const noexcept {
    return stringEquals ( this->c_str(), pString );
}

String & String :: operator = ( char const * pString ) noexcept {
    if ( this->c_str() == pString ) {
        return * this;
    }

    this->len = stringLength ( pString );

    /// this might look weird
    /// exchange (& a,b) =
    ///     aux = a;
    ///     a = b;
    ///     return aux;
    ///     transfera pe b in a si returneaza val. origniala
    ///     =>

    ///     aloca mem noua si o copiaza cu stringCopy -> b
    ///     o muta in pString -> a
    ///     returneaza val. veche a lui pString ( vechea memorie ) si o sterge cu delete []
    delete [] std :: exchange (
            this->pString,
            stringCopy ( new char [ this->len + 1 ], pString )
    );

    return * this;
}

String & String :: operator = ( String const & string ) noexcept {
    if ( this == & string ) {
        return * this;
    }

    this->len = string.len;

    /// same as above
    delete [] std :: exchange (
            this->pString,
            stringCopy ( new char [ this->len + 1 ], string.c_str() )
    );

    return * this;
}

char const * String :: c_str () const noexcept {
    return this->pString;
}
