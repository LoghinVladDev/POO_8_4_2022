//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_SIMPLELIST_H
#define POO_8_4_2022_SIMPLELIST_H

template < class T >
class SimpleList {
private:
    struct Node {
        T       object;
        Node  * pNext;
    };

    Node * pHead = nullptr;

public:
    SimpleList ( std :: initializer_list < T > list );

//    si asa e valid, pentru ca suntem inauntrul definitiei SimpleList, stie sa ia automat
//    ca e template, dar prefer mai explicit, are sens la function definitions
//    SimpleList & operator += ( std :: initializer_list < T > );
//    SimpleList & operator += ( T );

    SimpleList < T > & operator += ( std :: initializer_list < T > list );
    SimpleList < T > & operator += ( T object );

    SimpleList < T > & operator -= ( T object );

    ~SimpleList();

    operator int ();

    int operator [] ( T element );

    class Iterator {
    private:
        Node * pNode;

    public:
        Iterator ( Node * pNode );

        T & operator * ();
        Iterator operator ++ ();
        bool operator != ( Iterator it );
    };

    Iterator begin ();
    Iterator end ();
};

template < class T >
SimpleList < T > :: SimpleList ( std :: initializer_list < T > list ) {
    for ( auto element : list ) {
        Node * newNode = new Node;

        newNode->object = element;
        newNode->pNext  = this->pHead;

        this->pHead = newNode;
    }
}

template < class T >
SimpleList < T > & SimpleList < T > :: operator += ( std :: initializer_list < T > list ) {
    for ( auto element : list ) {
        Node * newNode = new Node;

        newNode->object = element;
        newNode->pNext  = pHead;

        this->pHead = newNode;
    }

    return * this;
}

template < class T >
SimpleList < T > & SimpleList < T > :: operator += ( T element ) {
    Node * newNode = new Node;

    newNode->object = element;
    newNode->pNext  = pHead;

    this->pHead = newNode;

    return * this;
}

template < class T >
SimpleList < T > & SimpleList < T > :: operator -= ( T element ) {
    if ( this->pHead == nullptr ) {
        return * this;
    }

    while ( this->pHead->object == element ) {
        auto copyOfHead = this->pHead;
        this->pHead = this->pHead->pNext;
        delete copyOfHead;
    }

    if ( this->pHead == nullptr ) {
        return * this;
    }

    auto copyOfHead = this->pHead;
    while ( copyOfHead != nullptr && copyOfHead->pNext != nullptr ) {
        while ( copyOfHead->pNext != nullptr && copyOfHead->pNext->object == element ) {
            auto copyOfCurrent = copyOfHead->pNext;
            copyOfHead->pNext = copyOfCurrent->pNext;
            delete copyOfCurrent;
        }

        copyOfHead = copyOfHead->pNext;
    }

    return * this;
}

template < class T >
SimpleList < T > :: operator int () {
    int elementCount = 0;
    auto copyOfHead = this->pHead;

    while ( copyOfHead != nullptr ) {
        elementCount ++;
        copyOfHead = copyOfHead->pNext;
    }

    return elementCount;
}

template < class T >
int SimpleList < T > :: operator [] ( T element ) {
    int elementCount = 0;
    auto copyOfHead = this->pHead;

    while ( copyOfHead != nullptr ) {

        if ( element == copyOfHead->object ) {
            elementCount ++;
        }

        copyOfHead = copyOfHead->pNext;
    }

    return elementCount;
}

template < class T >
SimpleList < T > :: Iterator :: Iterator ( Node * pNode ) : pNode ( pNode ) {

}

template < class T >
T & SimpleList < T > :: Iterator :: operator * () {
    return this->pNode->object;
}

//// chit ca e sursa fara comentarii
//// acest typename de jos e cu un motiv, bear with me
//// daca compilam fara el, ne da o eroare cu "...dependent typename..."
//// motivul : trebuie sa-i spunem practic compiler-ului ca "vezi, in caz ca nu ai generat SimpleList < T >, trebuie, pentru ca din el extrag Iterator"
template < class T >
typename SimpleList < T > :: Iterator SimpleList < T > :: Iterator :: operator ++ () {
    this->pNode = this->pNode->pNext;
    return * this;
}

/// aici nu mai e faza cu typename la parametru, pentru ca
/// practic e dupa apartenenta clasei ( inainte era la return type
/// , ce e inainte de apartenenta clasei )
/// aici e sigur ca exista acea clasa generata
template < class T >
bool SimpleList < T > :: Iterator :: operator != ( SimpleList < T > :: Iterator it ) {
    if ( this->pNode != it.pNode ) {
        return true;
    } else {
        return false;
    }
}

template < class T >
typename SimpleList < T > :: Iterator SimpleList < T > :: begin () {
    return Iterator ( this->pHead );
}

template < class T >
typename SimpleList < T > :: Iterator SimpleList < T > :: end () {
    return Iterator ( nullptr );
}

template < typename T >
SimpleList < T > :: ~SimpleList() {
    /// nu suntem in sursa cu comentarii, dar
    /// destructor e necesar! am alocat dinamic!!!!

    while ( this->pHead != nullptr ) {
        auto copyOfHead = this->pHead;
        this->pHead = this->pHead->pNext;
        delete copyOfHead;
    }
}


#endif //POO_8_4_2022_SIMPLELIST_H
