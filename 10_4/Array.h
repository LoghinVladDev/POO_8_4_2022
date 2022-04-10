//
// Created by loghin on 4/10/22.
//

#ifndef POO_8_4_2022_ARRAY_H
#define POO_8_4_2022_ARRAY_H

template < typename T >
class Array {
private:
    T   elements [ 256 ];
    int count;

public:
    Array ();

    int length ();

    Array & operator += ( T element );
    T & operator [] ( int index );

    T & front ();
    T & back ();
};

template < typename T >
Array < T > :: Array () : count(0) {

}

template < typename T >
int Array < T > :: length () {
    return this->count;
}

template < typename T >
Array < T > & Array < T > :: operator += ( T element ) {
    this->elements[ this->count ] = element;
    this->count ++;
    return * this;
}

template < typename T >
T & Array < T > :: operator [] ( int index ) {
    return this->elements[index];
}

template < typename T >
T & Array < T > :: front() {
    return this->elements[0];
}

template < typename T >
T & Array < T > ::back() {
    return this->elements[this->count - 1];
}

#endif //POO_8_4_2022_ARRAY_H
