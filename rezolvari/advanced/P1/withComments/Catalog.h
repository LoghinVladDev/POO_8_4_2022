//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_CATALOG_H
#define POO_8_4_2022_CATALOG_H

#include "Student.h"
#include "StringFunctions.h"

#define STUDENT_MAX_COUNT 256

class Catalog {
private:

    /// titlul acum e string dedicat
    char         title [ STRING_MAX_LEN ];

    Student      students [ STUDENT_MAX_COUNT ];
    int          studentCount;

public:
    Catalog ( char const * );

    /// operator += va primi o referinta la un Student constant, nu un obiect nou
    Catalog & operator += ( Student const & );
    /// analog
    Catalog & operator -= ( char const * );

    /// obtinerea titlului nu modifca obiectul => functie const
    operator char const * () const;
    /// obtinerea nr. studenti nu modifica obiectul => functie const
    operator int () const;
    /// obtinerea mediei nu modifica obiectul => functie const
    operator float () const;

    /// verificarea existentei unui student nu modifica obiectul => functie const
    bool operator == ( char const * ) const;

    class Iterator {
    private:
        Catalog * pCatalog;
        int       indexInCatalog;

    public:
        Iterator ( Catalog *, int );

        /// definitia CORECTA a lui ++ it
        Iterator &      operator ++ ();
        /// am definit si it ++ ca sa vedem diferenta

        /// explicatie ++ it si it ++
        /// sa luam exemplul cu int

        /// daca avem int x = 5;
        /// int y = ++ x; -> intai se mareste x-ul, si in y se salveaza valoarea noua
        ///     => se apeleaza intai ++ pt x, se returneaza NOUA valoare
        ///     => deci daca am fi in OOP, si am dori sa facem, idk, (++x).doSomething(), am vrea sa
        ///         putem face .doSomething() pe obiectul modificat
        ///     => ++ it returneaza referinta la obiectul modificat, nu un obiect nou

        /// iar it ++
        /// int z = x ++; -> se salveaza 5 in z, se mareste x. Se poate trimite o copie
        ////                (x++).doSomething() -> am dori ca .doSomething() sa fie facut inainte de x++;
        ///                 chit ca ++ se evalueaza intai. asadar, x++ returneaza o copie, nu obiectul modificat

        Iterator        operator ++ (int);

        /// decat sa returnam o copie a elementului, returnam o referinta la student
        /// also, obitnerea valorii de la iterator nu modifica iteratorul
        Student &       operator * () const;

        //// nu e nevoie de o copie a parametrului => const &. Also nu modifica obiectul => functie const
        bool            operator != ( Iterator const & ) const;
    };

    /// cu toate ca begin si end nu modifica obiectul,
    /// acestea NU pot fi const
    /// rationale : in urma parcurgerii, prin iterator, se poate modifica un student
    /// intrucat Iterator :: operator * () returneaza Student & => prin iterator, se poate modifica obiectul
    //// => not const
    Iterator begin ();
    Iterator end ();
};


#endif //POO_8_4_2022_CATALOG_H
