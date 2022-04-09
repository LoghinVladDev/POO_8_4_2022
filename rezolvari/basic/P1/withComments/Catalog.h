//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_CATALOG_H
#define POO_8_4_2022_CATALOG_H

#include "Student.h"

/// Exista numerotari in relatie cu comentariile in CAPS din main
/// unde am tras observatii, aici vin concluziile

/// intrucat in Catalog vom avea mai multi studenti, e mai simplu
/// sa ne definim o constanta pentru numarul max. de studenti
#define STUDENT_MAX_COUNT 256

/**
 * 1) VA EXISTA O CLASA "CATALOG"
 * Clasa Catalog
 */
class Catalog {
private:
    /// 2) CATALOGUL TREBUIE SA AIBA UN NUME
    /// Titlul catalogului
    char const * pTitle;

    /// 4) VA EXISTA SI O CLASA STUDENT, CU UN CONSTRUCTOR CE IA UN STRING SI UN INT,
    ///     NUMELE SI NOTA
    /// 7) CATALOGUL VA CONTINE OBIECTE DE TIP "STUDENT"
    /// Pentru a tine minte studentii, declaram un vector de studenti, cu o marime data
    Student      students [ STUDENT_MAX_COUNT ];

    /// mai mult, trebuie sa tinem minte si cati studenti avem
    int          studentCount;

public:

    /// 3) CATALOGUL TREBUIE SA AIBA UN CONSTRUCTOR CE PRIMESTE UN STRING
    Catalog ( char const * pTitle );

    /// 5) FUNCTIA += TREBUIE SA ADAUGE UN STUDENT, CU NOTA LUI, SI SA VERIFICE
    ///     DACA DEJA EXISTA STUDENTUL. DACA ACESTA EXISTA, NU IL VA ADAUGA.
    /// 6) FUNCTIA += VA AVEA RETURN TYPE "CATALOG &", pentru a intoarce, nu o copie,
    ///           ci catalogul proaspat modificat
    Catalog & operator += ( Student student );

    /// => 15) EXISTA UN OPERATOR -= CE IA UN STRING CA SI PARAMETRU SI SCOATE STUDENTUL
    ///      CU NUMELE DAT CA SI PARAM.
    ///
    /// 15.1) SE APLICA OBS. 6 SI AICI.
    Catalog & operator -= ( char const * pStudentName );

    /// 8) VA EXISTA O FUNCTIE DE CASTARE LA CHAR CONST * PENTRU CATALOG, ce va returna titlul acestuia
    operator char const * ();

    /// 9) VA EXISTA O FUNCTIE DE CASTARE LA INT PENTRU CATALOG, ce va returna numarul de studenti din acesta
    operator int ();

    /// 10) VA EXISTA O FUNCTIE DE CASTARE LA FLOAT PENTRU CATALOG, ce va returna media notelor studentilor din catalog
    operator float ();

    /// => 14) CATALOG ARE O FUNCTIE ==, ce primeste un string ( char const * ) ca si parametru
    ///      14.1) ACEASTA VERIFICA DACA EXISTA UN STUDENT CU NUMELE DAT CA SI PARAMETRU
    bool operator == ( char const * pStudentName );

    /// 11) CLASA CATALOG VA AVEA UN OBIECT ITERATOR
    /// 13) ITERATORUL ARE NEVOIE DE
    ///      -> ++ it         => 13.1) OPERATOR ++ ()
    ///      -> it != c.end() => 13.2) OPERATOR != (Iterator)
    ///      -> * it          => 13.3) OPERATOR * ()

    /// 13.4) ( not found in main )
    /// Intrucat Catalog tine obiectele de tip Student
    /// intr-un array, am sa precizez ca
    ///     -> Iteratorul are nevoie de
    ///         a) Access la catalog pentru a obtine studentul curent -> Pointer la Catalog
    ///         b) Indexul studentului curent
    class Iterator {
    private:
        Catalog * pCatalog;         /// 13.4.a
        int       indexInCatalog;   /// 13.4.b

    public:

        /// 13.5) ( not found in main )
        /// Intrucat trebuie sa putem construi iteratorii de begin, avem ctor
        /// caruia i se dau Catalogul pe care sa itereze, si indexul la care
        /// sa se afle iteratorul ( refer to 12.1 si 12.2 )
        Iterator ( Catalog * pCatalog, int index );


        /// 13.1
        Iterator operator ++ ();

        /// 13.3
        Student  operator * ();

        /// 13.2
        bool     operator != ( Iterator it );
    };

    /// 12.1) BEGIN VA RETURNA ITERATOR CU INDEX 0
    Iterator begin ();
    /// 12.2) END VA RETURNA ITERATOR CU INDEX N, unde N este numarul de elemente
    Iterator end ();
};


#endif //POO_8_4_2022_CATALOG_H
