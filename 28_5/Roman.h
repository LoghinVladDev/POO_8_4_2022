//
// Created by vladl on 5/28/2022.
//

#ifndef POO_8_4_2022_ROMAN_H
#define POO_8_4_2022_ROMAN_H

#include <string>
#include "Carte.h"

using namespace std;

class Roman : public Carte {
private:
    string nume;
    string autor;

public:
    Roman ( string nume, string autor );
    string GetInfo () override;
};


#endif //POO_8_4_2022_ROMAN_H
