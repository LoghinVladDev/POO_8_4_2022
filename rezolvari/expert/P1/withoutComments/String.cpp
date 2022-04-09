//
// Created by loghin on 4/9/22.
//

#include <utility>
#include "String.h"

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
    this->pString = stringCopy ( new char [ this->len + 1 ], pString );
}

String :: String ( String const & string ) noexcept {
    this->len = string.len;
    this->pString = stringCopy ( new char [ this->len + 1 ], string.c_str() );
}

String :: ~String () noexcept {
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

    delete [] std :: exchange (
            this->pString,
            stringCopy ( new char [ this->len + 1 ], string.c_str() )
    );

    return * this;
}

char const * String :: c_str () const noexcept {
    return this->pString;
}
