//
// Created by loghin on 4/9/22.
//

#include "Propozitie.h"
#include <vector>
#include <sstream>

using namespace std;

Propozitie :: Propozitie ( string sentence ) {
    this->sentence = sentence;
}

vector < string > split ( string text, string separators ) {
    vector < string > words;
    string            word;

    int startOfWord = 0;
    int endOfWord   = text.find_first_of ( separators );

    while ( endOfWord != -1 ) {
        word = text.substr ( startOfWord, endOfWord - startOfWord );
        words.push_back ( word );

        startOfWord = text.find_first_not_of ( separators, endOfWord );
        endOfWord   = text.find_first_of ( separators, startOfWord );
    }

    if ( startOfWord != -1 ) {
        word = text.substr ( startOfWord );
        words.push_back ( word );
    }

    return words;
}

int Propozitie :: operator [] ( string searchFor ) {

    if ( string ( searchFor ) == "count" ) {

        vector < string > words = split ( this->sentence, " ,." );
        return words.size();
    }

    if ( string ( searchFor ) == "vowals" ) {

        int vowelCount = 0;
        for ( int i = 0; i < this->sentence.length(); ++ i ) {
            if ( string ( "aeiouAEIOU" ).find ( this->sentence[i] ) != -1 ) {
                vowelCount ++;
            }
        }

        return vowelCount;
    }

    if ( string ( searchFor ) == "numbers" ) {

        vector < string > words         = split ( this->sentence, " ,." );
        int               numberCount   = 0;

        for ( int i = 0; i < words.size(); ++ i ) {
            if ( words[i].find_first_not_of ( "0123456789" ) == -1 ) {
                numberCount ++;
            }
        }

        return numberCount;
    }

    if ( string ( searchFor ) == "total_chars" ) {

        vector < string > words         = split ( this->sentence, " ,." );
        int               totalLength   = 0;

        for ( int i = 0; i < words.size(); ++ i ) {
            totalLength += words[i].length();
        }

        return totalLength;
    }

    return -1;
}

string Propozitie :: operator [] ( int wordIndex ) {

    vector < string > words = split ( this->sentence, " ,." );

    if ( wordIndex < 0 ) {
        wordIndex += words.size();
    }

    return words[wordIndex];
}

void Propozitie :: Set ( string sentence ) {
    this->sentence = sentence;
}

int Propozitie :: operator () ( int charCount ) {

    vector < string > words              = split ( this->sentence, " ,." );
    int               wordsOfGivenLength = 0;

    for ( int i = 0; i < words.size(); ++ i ) {
        if ( words[i].length() == charCount ) {
            wordsOfGivenLength ++;
        }
    }

    return wordsOfGivenLength;
}
