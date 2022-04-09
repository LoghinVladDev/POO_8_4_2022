//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_PROPOZITIE_H
#define POO_8_4_2022_PROPOZITIE_H

#define SENTENCE_MAX_LEN 1024
#include <string>

using namespace std;

class Propozitie {
private:
    string sentence;

public:
    Propozitie ( string sentence );

    int operator [] ( string searchFor );
    string operator [] ( int wordIndex );

    void Set ( string sentence );

    int operator () (int charCount);
};


#endif //POO_8_4_2022_PROPOZITIE_H
