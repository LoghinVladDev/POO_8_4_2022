//
// Created by vladl on 5/22/2022.
//

#ifndef POO_8_4_2022_ARRAY_H
#define POO_8_4_2022_ARRAY_H

class Compare {
public:
    virtual int CompareElements ( void * e1, void * e2 ) = 0;
};

template < class T >
class ArrayIterator {
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:
    ArrayIterator();
    ArrayIterator& operator ++ ();
    ArrayIterator& operator -- ();

    bool operator= (ArrayIterator<T> &);
    bool operator!=(ArrayIterator<T> &);

    T * GetElement();
};
/// int v [10];           v -> int *
/// Array < int > .... List -> int **        ????????????????????????

/// Array < BigObject >  -> BigObject [ 1000000 ] -> 40MB * 1000000 < neintrerupta
///                      -> BigObject * [ 1000000 ] -> 8B * 1000000 < neintrerupta ( + 40MB * 1000000 < nu conteaza )

/// trebuie sa creem array-ul de T *        new T * []
/// pentru fiecare obiect T, creem un T     new T

class IndexOutOfBounds : public std :: exception {
private:
    std :: string message;

public:
    IndexOutOfBounds ( int wrongIndex, int currentLength ) {
        this->message = "Index " + std :: to_string ( wrongIndex ) +
                        " out of bounds for length " +
                        std :: to_string ( currentLength );
    }

    char const * what() const noexcept override {
        return this->message.c_str();
    }
};

template < typename T >
class Array {
private:
    T ** array;     // array cu pointeri la obiecte de tipul T *
    int capacity;   // dimensiunea listei de pointeri
    int size;       // cate elemente sunt in lista

public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor  ^
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T> &otherArray); // constructor de copiere

    T& operator[] (int index); // ^ arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T &newElem); // ^ adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& remove(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie



    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};


template < typename T >
Array < T > :: Array () :
        array ( nullptr ),
        capacity ( 0 ),
        size ( 0 ) {

}

template < typename T >
Array < T > :: ~Array () {

    for ( int i = 0; i < this->size; ++ i ) {
        delete this->array[i];
    }

    delete [] this->array;
}

template < typename T >
Array < T > const &   Array < T > :: operator += (
        T const & newElement
) {

    /// alocarea initiala a vectorului de adrese
    if ( this->capacity == 0 ) {

        int const startingSize = 8;

        this->array     = new T * [ startingSize ];
        this->capacity  = startingSize;

        for (int i = 0; i < startingSize; ++i) {
            this->array[i] = nullptr;
        }
    }

    /// resize-ul vectorului de adrese
    if ( this->size == this->capacity ) {

        this->capacity = this->capacity * 2;
        T ** newArray = new T * [ this->capacity ];

        for ( int i = 0; i < this->capacity; ++ i ) {
            if ( i < this->size ) {
                newArray [ i ] = this->array [ i ];
            } else {
                newArray [ i ] = nullptr;
            }
        }

        delete [] this->array;
        this->array = newArray;
    }

    this->array [ this->size ] = new T ( newElement );
    /**
     * echivalentul fara a folosi copy ctor
     * this->array [ this->size ] = new T;
     * * this->array [ this->size ] = newElement;
     */

    this->size ++;
    return * this;
}

template < typename T >
T &     Array < T > :: operator [] ( int index ) {

    /// when is index out of range???
    /// ! ( i >= 0 && i < size )

    if ( ! ( index >= 0 && index < this->size ) ) {
        throw IndexOutOfBounds ( index, this->size );
    }

    return * this->array [ index ];
}

#endif //POO_8_4_2022_ARRAY_H
