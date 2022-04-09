//
// Created by loghin on 4/9/22.
//

#include "Catalog.h"

Catalog :: Catalog ( char const * pTitle ) :
        studentCount ( 0 ) {

    stringCopy ( this->title, pTitle );
}

Catalog & Catalog :: operator += ( Student const & student ) {

    if ( * this == student.getName() ) {
        return * this;
    }

    this->students [ this->studentCount ++ ] = student;

    return * this;
}

Catalog & Catalog :: operator -= ( char const * pStudentName ) {

    int indexOfStudentToRemove = -1;

    for ( int i = 0; i < this->studentCount; ++ i ) {
        if ( this->students[i].is ( pStudentName ) ) {
            indexOfStudentToRemove = i;
            break;
        }
    }

    if ( indexOfStudentToRemove == -1 ) {
        return * this;
    }

    for ( int i = indexOfStudentToRemove; i < this->studentCount - 1; ++ i ) {
        this->students[i] = this->students[i + 1];
    }

    this->studentCount --;
    return * this;
}

Catalog :: operator char const * () const {
    return this->title;
}

Catalog :: operator int () const {
    return this->studentCount;
}

Catalog :: operator float () const {
    float gradeSum = 0.0f;

    for ( int i = 0; i < this->studentCount; ++ i ) {
        gradeSum += (float) this->students[i].getGrade ();
    }

    return gradeSum / (float) this->studentCount;
}

bool Catalog :: operator == ( char const * pStudentName ) const {

    for ( int i = 0; i < this->studentCount; ++ i ) {
        if ( this->students[i].is ( pStudentName ) ) {
            return true;
        }
    }

    return false;
}

Catalog :: Iterator Catalog :: begin () {
    return { this, 0 };
}

Catalog :: Iterator Catalog :: end () {
    return { this, this->studentCount };
}

Catalog :: Iterator :: Iterator ( Catalog * pCatalog, int index ) :
        pCatalog ( pCatalog ),
        indexInCatalog ( index ) {

}

Catalog :: Iterator & Catalog :: Iterator :: operator ++ () {
    this->indexInCatalog ++;
    return * this;
}

Catalog :: Iterator Catalog :: Iterator :: operator ++ (int) {
    auto copy = * this;
    this->indexInCatalog ++;
    return copy;
}

Student & Catalog :: Iterator :: operator * () const {
    return this->pCatalog->students[this->indexInCatalog];
}

bool Catalog :: Iterator :: operator != ( Catalog :: Iterator const & it ) const {
    return this->indexInCatalog != it.indexInCatalog;
}
