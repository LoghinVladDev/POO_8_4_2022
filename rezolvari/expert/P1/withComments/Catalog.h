//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_CATALOG_H
#define POO_8_4_2022_CATALOG_H

#include "Student.h"
#include "String.h"

class Catalog {
private:
    String       title;

    /// ca sa putem pune cati studenti vrem, facem alocare dinamica pe studenti
    Student    * pStudents          = nullptr;
    int          studentCount       = 0;

    /// daca facem alloc dinamic, trebuie sa stim cati studenti incap in vector
    int          studentCapacity    = 0;

public:
    Catalog ( char const * pTitle ) noexcept;
    ~Catalog () noexcept;

    Catalog & operator += ( Student const & student ) noexcept;
    Catalog & operator -= ( char const * pStudentName ) noexcept;

    [[nodiscard]] explicit operator char const * () const noexcept;
    [[nodiscard]] explicit operator int () const noexcept;
    [[nodiscard]] explicit operator float () const noexcept;

    [[nodiscard]] bool operator == ( char const * pStudentName ) const noexcept;

    class Iterator {
    private:
        Catalog * pCatalog;
        int       indexInCatalog;

    public:
        Iterator ( Catalog * pCatalog, int index ) noexcept;

        Iterator &              operator ++ () noexcept;
        [[nodiscard]] Iterator  operator ++ (int) noexcept;
        Student &               operator * () const noexcept;
        [[nodiscard]] bool      operator != ( Iterator const & it ) const noexcept;
    };

    [[nodiscard]] Iterator begin () noexcept;
    [[nodiscard]] Iterator end () noexcept;

    class ConstIterator {
    private:
        Catalog const * pCatalog;
        int             indexInCatalog;

    public:
        ConstIterator ( Catalog const * pCatalog, int index ) noexcept;

        ConstIterator &             operator ++ () noexcept;
        [[nodiscard]] ConstIterator operator ++ (int) noexcept;
        Student const &             operator * () const noexcept;
        [[nodiscard]] bool          operator != ( ConstIterator const & it ) const noexcept;
    };

    [[nodiscard]] ConstIterator begin () const noexcept;
    [[nodiscard]] ConstIterator end () const noexcept;
};


#endif //POO_8_4_2022_CATALOG_H
