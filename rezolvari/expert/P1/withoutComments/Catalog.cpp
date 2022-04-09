//
// Created by loghin on 4/9/22.
//

#include <utility>
#include "Catalog.h"

Catalog :: Catalog ( char const * pTitle ) noexcept :
        title ( pTitle ) {

}

Catalog :: ~Catalog () noexcept {
    delete [] this->pStudents;
}

Catalog & Catalog :: operator += ( Student const & student ) noexcept {

    if ( * this == student.getName() ) {
        return * this;
    }

    if ( this->studentCount >= this->studentCapacity ) {

        this->studentCapacity = this->studentCapacity * 2 + 1;
        auto pNewStudents = new Student [ this->studentCapacity ];

        for ( int i = 0; i < this->studentCount; ++ i ) {
            pNewStudents [i] = this->pStudents[i];
        }

        delete [] std :: exchange (
                this->pStudents,
                pNewStudents
        );
    }

    this->pStudents [ this->studentCount ++ ] = student;

    return * this;
}

Catalog & Catalog :: operator -= ( char const * pStudentName ) noexcept {

    int indexOfStudentToRemove = -1;

    for ( int i = 0; i < this->studentCount; ++ i ) {
        if ( this->pStudents[i].is ( pStudentName ) ) {
            indexOfStudentToRemove = i;
            break;
        }
    }

    if ( indexOfStudentToRemove == -1 ) {
        return * this;
    }

    for ( int i = indexOfStudentToRemove; i < this->studentCount - 1; ++ i ) {
        this->pStudents[i] = this->pStudents[i + 1];
    }

    this->studentCount --;
    return * this;
}

Catalog :: operator char const * () const noexcept {
    return this->title.c_str();
}

Catalog :: operator int () const noexcept {
    return this->studentCount;
}

Catalog :: operator float () const noexcept {
    float gradeSum = 0.0f;

    for ( auto const & student : * this ) {
        gradeSum += (float) student.getGrade();
    }

    return gradeSum / (float) this->studentCount;
}

bool Catalog :: operator == ( char const * pStudentName ) const noexcept {

    for ( auto const & student : * this ) {
        if ( student.is ( pStudentName ) ) {
            return true;
        }
    }

    return false;
}

Catalog :: Iterator Catalog :: begin () noexcept {
    return { this, 0 };
}

Catalog :: Iterator Catalog :: end () noexcept {
    return { this, this->studentCount };
}

Catalog :: Iterator :: Iterator ( Catalog * pCatalog, int index ) noexcept :
        pCatalog ( pCatalog ),
        indexInCatalog ( index ) {

}

Catalog :: Iterator & Catalog :: Iterator :: operator ++ () noexcept {
    this->indexInCatalog ++;
    return * this;
}

Catalog :: Iterator Catalog :: Iterator :: operator ++ (int) noexcept {
    auto copy = * this;
    this->indexInCatalog ++;
    return copy;
}

Student & Catalog :: Iterator :: operator * () const noexcept {
    return this->pCatalog->pStudents[this->indexInCatalog];
}

bool Catalog :: Iterator :: operator != ( Catalog :: Iterator const & it ) const noexcept {
    return this->indexInCatalog != it.indexInCatalog;
}

Catalog :: ConstIterator Catalog :: begin () const noexcept {
    return { this, 0 };
}

Catalog :: ConstIterator Catalog :: end () const noexcept {
    return { this, this->studentCount };
}

Catalog :: ConstIterator :: ConstIterator ( Catalog const * pCatalog, int index ) noexcept :
        pCatalog ( pCatalog ),
        indexInCatalog ( index ) {

}

Catalog :: ConstIterator & Catalog :: ConstIterator :: operator ++ () noexcept {
    this->indexInCatalog ++;
    return * this;
}

Catalog :: ConstIterator Catalog :: ConstIterator :: operator ++ (int) noexcept {
    auto copy = * this;
    this->indexInCatalog ++;
    return copy;
}

Student const & Catalog :: ConstIterator :: operator * () const noexcept {
    return this->pCatalog->pStudents[this->indexInCatalog];
}

bool Catalog :: ConstIterator :: operator != ( Catalog :: ConstIterator const & it ) const noexcept {
    return this->indexInCatalog != it.indexInCatalog;
}
