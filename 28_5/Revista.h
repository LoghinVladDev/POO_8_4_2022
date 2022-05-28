//
// Created by vladl on 5/28/2022.
//

#ifndef POO_8_4_2022_REVISTA_H
#define POO_8_4_2022_REVISTA_H

#include <string>
#include "Carte.h"

using namespace std;

class Revista : public Carte {
private:
    string titlu;
    int nrArticole;

public:
    Revista ( string titlu, int nrArticole );
    string GetInfo () override;
};


#endif //POO_8_4_2022_REVISTA_H
