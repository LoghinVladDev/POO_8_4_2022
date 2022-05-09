//
// Created by uic70278 on 5/9/2022.
//

#include "Phrase.h"
#include <cstring>

/**
 * "I   have   POO
     examination   today
    in C++ "
 */

Phrase :: Phrase (
        char const * phrase
)  {

    char phraseCopy [1024];
    strcpy ( phraseCopy, phrase );
    char * p = strtok ( phraseCopy, " ,.;" );

    while ( p != nullptr ) {

        strcpy ( this->words[ this->length ], p );
        this->length ++;

        p = strtok ( nullptr, " ,.;" );
    }
}

Phrase :: operator int() const {
    return this->length;
}

char const * Phrase :: operator [] ( int index ) const {
    return this->words[index];
}

int Phrase :: CountLetter ( int index, char letter ) const {

    int counter = 0;

    for ( int j = 0; j < strlen ( this->words[ index ] ); ++ j ) {
        if ( words [ index ] [ j ] == letter ) {
            ++ counter;
        }
    }

    return counter;
}

int Phrase :: CountLetter ( char letter ) const {

    int counter = 0;

    for ( int i = 0; i < this->length; ++ i ) {
        counter += this->CountLetter ( i, letter );
    }

    return counter;
}

char const * Phrase :: GetLongestWord() const {

    int lMax = 0;
    char const * pMaxWord = nullptr;

    for ( int i = 0; i < this->length; ++ i ) {
        int currentLength = strlen ( this->words[i] );

        if ( currentLength > lMax ) {
            lMax = currentLength;
            pMaxWord = this->words[i];
        }
    }

    return pMaxWord;
}

int Phrase :: CountVowels () const {

    int vowelCount = 0;

    for ( int i = 0; i < this->length; ++ i ) {
        for ( int j = 0; j < strlen ( this->words[i] ); ++ j ) {
            if ( strchr ( "AEIOUaeiou", this->words[i][j] ) != nullptr ) {
                ++ vowelCount;
            }
        }
    }

    return vowelCount;
}

Phrase :: Phrase () = default;

/// s = "Poo teachers are (generally) bad\0"
/// strcpy ( s, "Ana are mere" );
/// s = "Ana are mere\0are (generally) bad\0"

Phrase & Phrase :: operator = ( char const * phrase ) {

    this->length = 0;

    char phraseCopy [1024];
    strcpy ( phraseCopy, phrase );
    char * p = strtok ( phraseCopy, " ,.;" );

    while ( p != nullptr ) {

        strcpy ( this->words[ this->length ], p );
        this->length ++;

        p = strtok ( nullptr, " ,.;" );
    }

    return * this;
}

Phrase :: Iterator Phrase :: begin () {
    return Iterator ( 0, this );
}

Phrase :: Iterator Phrase :: end () {
    return Iterator ( this->length, this );
}

bool Phrase :: Iterator :: operator != (
        Phrase :: Iterator it
) const {

    return this->index != it.index;
}

Phrase :: Iterator &    Phrase :: Iterator :: operator ++ () {

    this->index ++;
    return * this;
}

char const *    Phrase :: Iterator :: operator * () {

    return ( * this->phrase ) [ this->index ];
//    return this->phrase->operator[](this->index);
}
