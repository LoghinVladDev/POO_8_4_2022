//
// Created by loghin on 4/10/22.
//

#ifndef POO_8_4_2022_SIMPLELIST_H
#define POO_8_4_2022_SIMPLELIST_H

#include <initializer_list>

using namespace std;

template < typename T >
class SimpleList {
private:
    struct Node {
        T       element;
        Node  * pNext;
    };

    Node * pHead = nullptr;

public:
    SimpleList ( initializer_list < T > list );
    ~SimpleList();

    operator int () const;

    int operator [] ( T element ) const;

    SimpleList & operator += ( T element );
    SimpleList & operator += ( initializer_list < T > list );

    class Iterator {
    private:
        Node * p;
    public:
        Iterator ( Node * p );
        bool operator != ( Iterator );
        Iterator operator ++ ();
        T & operator * ();
    };

    Iterator begin ();
    Iterator end ();
};

template < typename T >
T &   SimpleList < T > :: Iterator :: operator* () {
    return this->p->element;
}

template < typename T >
typename SimpleList < T > :: Iterator   SimpleList < T > :: Iterator ::operator++() {
    this->p = this->p->pNext;
    return * this;
}

template < typename T >
bool SimpleList < T > :: Iterator :: operator!= (Iterator it) {
    if ( this->p != it.p ) {
        return true;
    } else {
        return false;
    }
}

template < typename T >
SimpleList < T > :: Iterator :: Iterator ( Node * p ) : p (p) {

}

template < typename T >
typename SimpleList < T > :: Iterator    SimpleList < T > :: begin () {
    return Iterator ( this->pHead );
}

template < typename T >
typename SimpleList < T > :: Iterator    SimpleList < T > :: end () {
    return Iterator ( nullptr );
}

template < typename T >
int SimpleList < T > :: operator [] ( T element ) const {
    int nrAparitii = 0;
    Node * p = this->pHead;

    while ( p != nullptr ) {

        if ( element == p->element ) {
            nrAparitii ++;
        }

        p = p->pNext;
    }

    return nrAparitii;
}

template < typename T >
SimpleList < T > :: operator int() const {
    int count = 0;

    Node * p = this->pHead;
    while ( p != nullptr ) {

        count ++;
        p = p->pNext;
    }

    return count;
}

template < typename T >
SimpleList < T > :: SimpleList ( initializer_list < T > list ) {
    for ( auto e : list ) {
//
//        Node * newNode = new Node;
//        newNode->element = e;
//        newNode->pNext = this->pHead;
//        this->pHead = newNode;
        * this += e;
    }
}

template < typename T >
SimpleList < T > & SimpleList < T > ::
        operator+= ( T element ) {

    Node * newNode = new Node;
    newNode->element = element;
    newNode->pNext = this->pHead;
    this->pHead = newNode;

    return * this;
}

template < typename T >
SimpleList < T > & SimpleList < T > ::
        operator+= ( initializer_list < T > list ) {

    for ( auto item : list ) {
        * this += item;
    }

    return * this;
}

template < typename T >
SimpleList < T > :: ~SimpleList() {

    while ( this->pHead != nullptr ) {
        Node * p = this->pHead;
        this->pHead = this->pHead->pNext;
        delete p;
    }
}


#endif //POO_8_4_2022_SIMPLELIST_H
