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

void stringCopy ( char * pDest, char const * pSource ) {

    while ( * pSource != '\0' ) {
        * pDest = * pSource;

        ++ pDest;
        ++ pSource;
    }

    * pDest = * pSource;
}