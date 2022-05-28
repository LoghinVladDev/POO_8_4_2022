//
// Created by vladl on 5/28/2022.
//

#include "Roman.h"

Roman :: Roman ( string nume, string autor ) :
        nume(nume),
        autor(autor) {

}

string Roman :: GetInfo () {

    return "Roman " + this->nume +
        " de " + this->autor;
}
