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
    Array() noexcept; // Lista nu e alocata, Capacity si Size = 0
    ~Array() noexcept; // destructor  ^
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    /// daca preferati, implementati cu prealocare de elemente, nu doar alocare array
    /// asa se foloseste normal

    Array(const Array<T> &otherArray); // constructor de copiere
    /// operator =

    T& operator[] (int index) noexcept (false); // ^ arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T &newElem) noexcept; // ^ adauga un element de tipul T la sfarsitul listei si returneaza this

//// this->capacity - this->size + needed ( 1'st insert - 1, 2'nd insert - otherArray.size ) ( daca nu incape in this->capacity )
    const Array<T>& insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

//// se poate si fara buffer nou, doar stergeti, mutati, setati ultimul pe nullptr
    const Array<T>& remove(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator == ( Array<T> const & otherArray ) const noexcept;
    Array < T > & operator = ( Array<T> const & otherArray ) noexcept;

/// T * aux = array[i];
/// array[i] = array[j];
/// array[j] = aux;
    void sort(); // sorteaza folosind comparatia intre elementele din T

    /// compare is a (pointer to) function of type    int ( T const &, T const & )
    template < typename CompareFunction >
    void sort ( CompareFunction function );

//    void sort( int ( * compare ) ( T const &, T const & ) ); // sorteaza folosind o functie de comparatie
    void sort(Compare *comparator); // sorteaza folosind un obiect de comparatie



    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int binarySearch(const T& elem); // cauta un element folosind binary search in Array
    int binarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int binarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator


    /// cauta cu * this->array [ i ] == elem
    int find(const T& elem); // cauta un element in Array

    /// cauta cu compare ( * this->array[i], elem ) == 0
    int find(T const & elem, int(*compare)( T const&, T const&));//  cauta un element folosind o functie de comparatie

    /// cauta cu comparator->CompareElements ( this->array[i], & elem ) == 0
    int find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator

    int getSize() const noexcept;
    int getCapacity() const noexcept;

    ArrayIterator<T> getBeginIterator();
    ArrayIterator<T> getEndIterator();
};


template < typename T >
Array < T > :: Array () noexcept :
        array ( nullptr ),
        capacity ( 0 ),
        size ( 0 ) {

}

template < typename T >
Array < T > :: ~Array () noexcept {

    for ( int i = 0; i < this->size; ++ i ) {
        delete this->array[i];
    }

    delete [] this->array;
}

template < typename T >
Array < T > const &   Array < T > :: operator += (
        T const & newElement
) noexcept {

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
T &     Array < T > :: operator [] ( int index ) noexcept (false) {

    /// when is index out of range???
    /// ! ( i >= 0 && i < size )

    if ( ! ( index >= 0 && index < this->size ) ) {
        throw IndexOutOfBounds ( index, this->size );
    }

    return * this->array [ index ];
}

template < typename T >
int Array < T > :: getSize () const noexcept {
    return this->size;
}

template < typename T >
int Array < T > :: getCapacity () const noexcept {
    return this->capacity;
}

template < typename T >
bool Array < T > :: operator == ( Array < T > const & otherArray ) const noexcept {

    if ( this == & otherArray ) {
        return true;
    }

    if ( this->size != otherArray.size ) {
        return false;
    }

    for ( int i = 0; i < this->size; ++ i ) {
        if ( * this->array[i] != * otherArray.array[i] ) {
            return false;
        }
    }

    return true;
}

template < typename T >
Array < T > &   Array < T > :: operator = ( Array < T > const & otherArray ) noexcept {
    if ( this == & otherArray ) {
        return * this;
    }

    for ( int i = 0; i < this->size; ++ i ) {
        delete this->array[i];
    }

    delete [] this->array;


    this->array = new T * [ otherArray.capacity ];
    for ( int i = 0; i < otherArray.capacity; ++ i ) {
        if ( i < this->size ) {
//            this->array [ i ] = new T ( otherArray [i] ); face verifcarea de index
            this->array [ i ] = new T ( * otherArray.array [i] );
        } else {
            this->array [ i ] = nullptr;
        }
    }

    this->size      = otherArray.size;
    this->capacity  = otherArray.capacity;

    return * this;
}

//template < typename T >
//void Array < T > :: sort (
//        int ( * compare ) ( T const &, T const & )
//) {

template < typename T >
template < typename CompareFunction >
void Array < T > :: sort ( CompareFunction compare ) {

    for ( int i = 0; i < this->size - 1; ++ i ) {
        for ( int j = i + 1; j < this->size; ++ j ) {
//            if ( v[i] > v[j] )
            if ( compare ( * this->array [i], * this->array[j] ) > 0 ) {
                T * aux = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = aux;
            }
        }
    }
}

class ElementNotFound : public std :: exception {
public:
    const char * what() const noexcept override {
        return "Element Not Found";
    }
};

template < typename T >
int Array < T > :: find (
        T const & element,
        int ( * compare ) ( T const &, T const & )
) {

    for ( int i = 0; i < this->size; ++ i ) {
        if ( compare ( * this->array[i], element ) == 0 ) {
            return i;
        }
    }

    throw ElementNotFound();
}

#endif //POO_8_4_2022_ARRAY_H
