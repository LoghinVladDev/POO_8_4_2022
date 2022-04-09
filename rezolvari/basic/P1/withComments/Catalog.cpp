//
// Created by loghin on 4/9/22.
//

#include "Catalog.h"

/**
 * Asemenea student, nu creem / avem un string pt titlu, primit adresa acestuia, este destul
 *   ( acel string exista in main pana la finalul programului )
 *
 *   Moreover, numarul de studenti initial TREBUIE setat pe 0
 */
Catalog :: Catalog ( char const * pTitle ) :
        pTitle ( pTitle ),
        studentCount ( 0 ) {

}

/// atentie aici
Catalog & Catalog :: operator += ( Student student ) {

    /// ne smecherim putin, salvam timp
    /// daca Catalog :: operator == verifica daca un student exista in catalog
    /// SI noi nu vrem sa adaugam un student care deja exista

    /// DACA exista un student cu numele studentului de adaugat
    if ( * this == student.getName() ) {

        /// nu facem nimic
        return * this;

        //// mic aspect -> type ( this ) = Catalog *. Daca vrem un Catalog ( sau Catalog &, compatibil
        //// cu return-ul curent ), trebuie sa facem de-reference la adresa this
        //// echivalent ca si cum am avea int * p; .... * p = 5;
        //// adica obtinem valoarea de la adresa "this"
    }

    //// daca studentul de adaugat ( param. ) nu exista, suntem aici ( nu a iesit din functie )
    //// => in students, acum avem 0...N-1 studenti, unde N este this->studentCount
    //// => pe pozitia this->studentCount punem studentul nou
    this->students [ this->studentCount ] = student;

    /// marim nr. studenti
    this->studentCount ++;

    /// analog return-ul de mai sus
    return * this;
}

Catalog & Catalog :: operator -= ( char const * pStudentName ) {

    //// tricky stuff again, daca avem de scos un student, trebuie sa vedem daca acesta
    //// chiar exista
    //// daca studentul exista, trebuie mutati toti cei dinainte cu un pas inapoi

    //// vom salva indexul acestui student in aceasta valoare. Pornim cu ea de la
    //// -1 ( un index invalid ) pentru a verifica daca s-a gasit un student
    int indexOfStudentToRemove = -1;

    //// parcurgem toti studentii
    for ( int i = 0; i < this->studentCount; ++ i ) {

        //// folosim comparatia definita in Student.h pentru a identifica studentii cu acelasi nume
        if ( this->students[i].is ( pStudentName ) ) {

            //// salvam index-ul si spargem bucla
            indexOfStudentToRemove = i;
            break;
        }
    }

    //// daca studentul nu exista, index-ul acestuia ramane -1
    if ( indexOfStudentToRemove == -1 ) {

        /// analog operator +=
        return * this;
    }

    /// daca acesta exista, trebuie sa mutam toti studentii de dupa el cu un pas inapoi
    /// pentru a acoperi golul pe care acesta il va crea la scoatere

    for ( int i = indexOfStudentToRemove; i < this->studentCount - 1; ++ i ) {
        this->students[i] = this->students[i + 1];
    }

    /// se scade si nr. studenti
    this->studentCount --;

    /// analog
    return * this;
}

Catalog :: operator char const * () {

    /// din format-ul de printf cu obs. 8), 9), 10)
    return this->pTitle;
}

Catalog :: operator int () {

    /// din format-ul de printf cu obs. 8), 9), 10)
    return this->studentCount;
}

Catalog :: operator float () {

    /// din format-ul de printf cu obs. 8), 9), 10)
    /// trebuie sa calculam media =>
    /// media = suma notelor / nr elevi
    float gradeSum = 0.0f;

    /// calculam suma
    for ( int i = 0; i < this->studentCount; ++ i ) {
        gradeSum += this->students[i].getGrade ();
    }

    /// suma / nr elevi
    return gradeSum / this->studentCount;
}

bool Catalog :: operator == ( char const * pStudentName ) {

    /// pentru a afla daca un student exista in catalog, folosim functia definita in Student.h
    ///     Student :: is ( char const * ), ce ne spune daca studentul curent are numele dat
    for ( int i = 0; i < this->studentCount; ++ i ) {
        if ( this->students[i].is ( pStudentName ) ) {

            /// daca da, studentul cu numele dat exista
            return true;
        }
    }

    //// daca nu s-a gasit nici un student, nu exista
    return false;
}

Catalog :: Iterator Catalog :: begin () {
    /// 12.1) Begin va fi cu index 0
    return Iterator ( this, 0 );
}

Catalog :: Iterator Catalog :: end () {
    /// 12.2) End va fi cu index N, unde N este studentCount
    return Iterator ( this, this->studentCount );
}

/// OBS 12.3) ( not found in main ) -> pasam si this ( Catalog * ) la Iterator, ca sa aiba iteratorul
/// de unde sa obtina studentii

/// OBS 12.4) Observam ca nu putem
///     Iterator Catalog :: begin()
///     Iterator Catalog :: end()
///     Iterator :: Iterator ( Catalog *, int ) - ctor

////    CI

///     Catalog :: Iterator Catalog :: begin()
///     Catalog :: Iterator Catalog :: end()
///     Catalog :: Iterator :: Iterator ( Catalog *, int ) - ctor

/// intrucat Iterator se afla in SCOPE-UL obiectului Catalog (
/// Catalog :: Iterator = clasa Iterator din clasa Catalog
/// Catalog :: Iterator :: ... = functie din clasa Iterator, aflata in clasa Catalog

Catalog :: Iterator :: Iterator ( Catalog * pCatalog, int index ) :
        pCatalog ( pCatalog ),
        indexInCatalog ( index ) {

}


/// urm iterator = urm index
Catalog :: Iterator Catalog :: Iterator :: operator ++ () {
    this->indexInCatalog ++;
    return * this;
}

/// valoarea o obtinem din catalog, studentul de la indexul curent
Student Catalog :: Iterator :: operator * () {
    return this->pCatalog->students[this->indexInCatalog];
}

/// comparatia iteratorilor se face pe indexul elementului curent
///  i.e. daca indica la aceeasi pozitie
bool Catalog :: Iterator :: operator != ( Catalog :: Iterator it ) {
    if ( this->indexInCatalog != it.indexInCatalog ) {
        return true;
    } else {
        return false;
    }
}
