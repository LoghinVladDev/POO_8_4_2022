//
// Created by vladl on 5/28/2022.
//

#ifndef POO_8_4_2022_BIBLIOTECA_H
#define POO_8_4_2022_BIBLIOTECA_H

#include "Carte.h"
#include <array>
#include <list>
#include <iostream>

/// std :: vector -> vector redimensionabil
/// std :: array -> vector marime fixa ( echivalent v[ 100 ] )
/// std :: array este iterabil.

using namespace std;

class Biblioteca {
private:
    int count;
    Carte * carti [100];
//    array < Carte *, 100 > carti;

public:

    class Iterator {
    private:
        int index;
        Biblioteca * pBibilioteca;

    public:
        Iterator ( int index, Biblioteca * pBiblioteca );

        bool operator != ( Iterator const & ) const;
        Carte * operator * () const;
        Iterator & operator ++ ();
    };

    Biblioteca();
    ~Biblioteca();

    Biblioteca & operator += ( Carte * c );

    Iterator begin ();
    Iterator end ();

    operator int () const;

    template < typename FilterFunc >
    void PrintFilter ( FilterFunc fn );

    /// pt varianta cu std :: array
    /**
     * array < Carte *, 100 > :: iterator begin () { return this->carti.begin(); }
     * array < Carte *, 100 > :: iterator end () { return this->carti.end(); }
     */
};

template < typename FilterFunc >
void Biblioteca :: PrintFilter (
        FilterFunc fn
) {

    for ( auto c : * this ) {

        if ( fn ( c ) ) {
            std :: cout << c->GetInfo () << '\n';
        }
    }
}


#endif //POO_8_4_2022_BIBLIOTECA_H
