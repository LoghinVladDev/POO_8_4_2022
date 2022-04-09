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
    Student    * pStudents          = nullptr;
    int          studentCount       = 0;
    int          studentCapacity    = 0;

public:
    Catalog ( char const * pTitle ) noexcept;
    ~Catalog () noexcept;

    Catalog & operator += ( Student const & student ) noexcept;
    Catalog & operator -= ( char const * pStudentName ) noexcept;

    //// explicit
    //// urat cuvant, dar are sens
    //// cum am mentionat, c++ face castari implicite
    //// exemplu

    //// int y = 3;   float z = y;
    ////                        ^
    ////                    se casteaza la int
    //// ca sa evitam castari accidentale ( se pot intampla )
    ////    ( de ex. sa pasam catalog la Student :: is ar genera o conversie implicita
    ////        intrucat Student :: is vrea char const *, iar Catalog ar avea char const *
    ////        conversion )
    ////    marcam conversiile ca fiind explicite, adica se intampla DOAR daca dam
    ////    (char const *) obj
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

    //// const iteratorul de care am mentionat in main
    //// diferente :
    //// begin(), end() pentru asta sunt const
    //// functia de obt. valoarea ( operator * ) returneaza Student const &, obiectul original, dar nemodificabil -> nu modifica Catalog
    //// consecinta, ctor-ul primeste un Catalog const *
    //// ( intrucat apelam begin () const, pasam this acolo
    /////   this acolo este Catalog *
    ////    => si ctor-ul ConstIterator trebuie sa primeasca Catalog const *
    ////    )
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
