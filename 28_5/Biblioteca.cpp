//
// Created by vladl on 5/28/2022.
//

#include <stdexcept>
#include "Biblioteca.h"

Biblioteca & Biblioteca :: operator += ( Carte * c ) {

    if ( this->count >= 100 ) {
        /// daca nu vrem throw
        /// delete c;
        /// return * this;

        throw std :: runtime_error ( "Prea multe carti in biblioteca" );
    }

    this->carti [ this->count ] = c;
    this->count ++;

    return * this;
}

Biblioteca :: Biblioteca () {
    this->count = 0;
}

Biblioteca :: ~Biblioteca () {

    for (int i = 0; i < this->count; ++i) {
        delete this->carti [ i ];
    }
}

Biblioteca :: Iterator  Biblioteca :: begin () {
    return Iterator ( 0, this );
}

Biblioteca :: Iterator  Biblioteca :: end () {
    return Iterator ( this->count, this );
}

Biblioteca :: Iterator :: Iterator (
        int index,
        Biblioteca * pBiblioteca
) : index (index), pBibilioteca (pBiblioteca) {

}

bool Biblioteca :: Iterator :: operator != (
        Biblioteca :: Iterator const & otherIterator ) const {

    return this->index != otherIterator.index;
}

Carte * Biblioteca :: Iterator :: operator * () const {

    return this->pBibilioteca->carti [ this->index ];
}

Biblioteca :: Iterator &    Biblioteca :: Iterator :: operator ++ () {

    ++ this->index;
    return * this;
}

Biblioteca :: operator int() const {
    return this->count;
}
