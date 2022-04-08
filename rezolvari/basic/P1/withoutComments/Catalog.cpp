//
// Created by loghin on 4/9/22.
//

#include "Catalog.h"

Catalog :: Catalog ( char const * pTitle ) :
        pTitle ( pTitle ),
        studentCount ( 0 ) {

}

Catalog & Catalog :: operator += ( Student student ) {

    if ( * this == student.getName() ) {
        return * this;
    }

    this->students [ this->studentCount ] = student;
    this->studentCount ++;

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

Catalog :: operator char const * () {
    return this->pTitle;
}

Catalog :: operator int () {
    return this->studentCount;
}

Catalog :: operator float () {
    float gradeSum = 0.0f;

    for ( int i = 0; i < this->studentCount; ++ i ) {
        gradeSum += this->students[i].getGrade ();
    }

    return gradeSum / this->studentCount;
}

bool Catalog :: operator == ( char const * pStudentName ) {

    for ( int i = 0; i < this->studentCount; ++ i ) {
        if ( this->students[i].is ( pStudentName ) ) {
            return true;
        }
    }

    return false;
}

Catalog :: Iterator Catalog :: begin () {
    return Iterator ( this, 0 );
}

Catalog :: Iterator Catalog :: end () {
    return Iterator ( this, this->studentCount );
}

Catalog :: Iterator :: Iterator ( Catalog * pCatalog, int index ) :
        pCatalog ( pCatalog ),
        indexInCatalog ( index ) {

}

Catalog :: Iterator Catalog :: Iterator :: operator ++ () {
    this->indexInCatalog ++;
    return * this;
}

Student Catalog :: Iterator :: operator * () {
    return this->pCatalog->students[this->indexInCatalog];
}

bool Catalog :: Iterator :: operator != ( Catalog :: Iterator it ) {
    if ( this->indexInCatalog != it.indexInCatalog ) {
        return true;
    } else {
        return false;
    }
}
