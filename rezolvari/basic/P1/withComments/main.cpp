//
// Created by loghin on 4/9/22.
//

/**
 * I'll admit, problema asta o fost tricky. E prea ciudata pt un examen
 * Nevertheless, aia e. Comentarii unde e dubios rau
 *
 * Moreover,
 * in enunt, e specificat ca nu e voie cu
 * STL - dispare std :: string din ecuatie
 * cstring - dispar strcpy, strcmp, etc. ( ouch )
 *      trebuie sa ne implementam string function-uri unde e nevoie
 *
 * Nevertheless, nu e imposibil
 *
 * Unde e scris cu CAPS, informatia reprezinta o concluzie ( pentru a fi usor de gasit )
 */


#include <cstdio> /// necesar pt printf. Ecihvalent #include <stdio.h>
#include "Catalog.h"

/**
 * As mentioned, putem extrage FOARTE multe informatii doar din main
 * uneori este mai ciudat, indeed
 */

int main () {

    /**
     * Obiect nume = valoare;
     *
     * este echivalent cu
     *
     * Obiect nume ( valoare );
     *
     * Se aplica doar la constructori cu un singur parametru
     * La mai multi avem :
     *
     * Obiect nume ( val1, val2, val3, ... );
     *
     * este echivalent cu
     *
     * Obiect nume = { val1, val2, val3, ... };
     *
     *
     * In mare, se creeaza un catalog, ar carui
     * titlu ar trebui sa fie "math"
     * => 1) VA EXISTA O CLASA "CATALOG"
     * => 2) CATALOGUL TREBUIE SA AIBA UN NUME
     * => 3) CATALOGUL TREBUIE SA AIBA UN CONSTRUCTOR CE PRIMESTE UN STRING
     */
    Catalog c = "math";

    /**
     * Prima chestie ciudata.
     * Am sa o impart in statement-uri
     *
     * Luam de la cea mai adanc statement : c += { "Popescu", 10 }
     * Operator += este un operator => e o functie => are un rezultat
     * Sa zicem ca rez = ( c += { "Popescu", 10 } );
     *
     * dupa care ->
     *
     * rez += { "Ionescu", 9 };
     *
     * analog mai sus, savlvam tot intr-un rezultat si facem iar
     * rez += { "Popescu", 8 };
     *
     *
     * Okay, acum hai sa vedem ce ar trebui sa faca
     * "Noroc" ca avem o afisare mai jos
     *
     * Catalog: math (2 students ==> average: 9.50)
     *
     * Observam ca in urma instructiunii tampite, se adauga doi studenti,
     * ar caror medie este 9.50
     *
     * Asadar -> se observa ca defapt += adauga un student
     *
     * Prima adaugare, Popescu, nota 10
     * A doua, Ionescu, nota 9
     * A treia il are iar pe Popescu, dar cu nota 8
     *
     * Observam ca apare Popescu de doua ori, dar in final avem 2 studenti
     * si media 9.50. Matematic, nu se adauga iarasi Popescu, nota lui ramanand cea
     * initiala.
     *
     * Also, observam ca studentii sunt adaugati cu {} => denota un constructor
     * (
     *      echivalent cum am spune
     *      Student s1 = { "Popescu", 10 };
     *      Student s2 = { "Ionescu", 9 };
     *      Student s3 = { "Popescu", 8 };
     *
     *      ( ( c += s1 ) += s2 ) += s3;
     *      -> daca inlocuim s1 s2 si s3 cu valorile lor, obtinem frumoasa si minunata
     *          instructiune
     *  )
     *
     *  Asadar, avem nevoie si de un obiect Student
     *
     * => 4) VA EXISTA SI O CLASA STUDENT, CU UN CONSTRUCTOR CE IA UN STRING SI UN INT,
     * NUMELE SI NOTA
     *
     * => 5) FUNCTIA += TREBUIE SA ADAUGE UN STUDENT, CU NOTA LUI, SI SA VERIFICE
     * DACA DEJA EXISTA STUDENTUL. DACA ACESTA EXISTA, NU IL VA ADAUGA.
     *      => 5.1) AVEM NEVOIE DE O METODA DE A COMPARA STUDENTII,
     *          FIE COMPARAND NUMELE OBTINUT DE LA STUDENTI
     *              - in Catalog +=, obtinem numele studentilor cu
     *                  Student :: getName () si comparam
     *          FIE COMPARAND STUDENTII PE BAZA NUMELUI
     *              - in Student definim o metoda de comparatie cu un nume, pentru
     *                  a verifica daca studentii sunt identici
     *                  => 5.2) AICI ALEG ACEASTA METODA, Student :: is ( char const * ) este
     *                      functia ce implementeaza asta
     *
     *
     * O ultima observatie, dar importanta.
     * Observam ca rezultatul primului += este folosit in stanga urmatorului, facand
     * tot modificari pe c, fara a-l mai invoca direct.
     *
     * => !! CONCEPT !! -> Daca noi definim functia de += drept
     *      Catalog operator += ( Student )
     *
     *      Vom returna defapt o copie a catalogului curent
     *          - puteti incerca asta cu o functie ce returneaza un int,
     *              data o functie "int f()", nu putem face f() += 5;
     *              intrucat va returna o copie, nu o valoare modificabila
     *
     *      Asadar, ar trebui sa ne intoarcem exact catalogul folosit
     *      pentru a face asta folosim &
     *
     * => 6) FUNCTIA += VA AVEA RETURN TYPE "CATALOG &", pentru a intoarce, nu o copie,
     *      ci catalogul proaspat modificat
     *
     * => 7) CATALOGUL VA CONTINE OBIECTE DE TIP "STUDENT"
     */
    ( (c += { "Popescu", 10 }) += { "Ionescu", 9 } ) += { "Popescu", 8 };

    /**
     * "Pauza de tigara pentru cine a trecut prin tot textul de mai sus. Sorry."
     *
     * print-ul afiseaza
     *  Catalog: math (2 students ==> average: 9.50)
     *
     * Observam urmatoarele
     * Stiind ca in printf, primul parametru
     *      (char const *) c ia locul lui %s
     *      (int) c ia locul lui %d
     *      (float) ia locul lui %.2f - don't be afraid, e doar un format
     *
     *      ( concluzie scoasa din ordinea lor )
     *
     * Putem constata:
     *
     * => 8) VA EXISTA O FUNCTIE DE CASTARE LA CHAR CONST * PENTRU CATALOG, ce va returna titlul acestuia
     * => 9) VA EXISTA O FUNCTIE DE CASTARE LA INT PENTRU CATALOG, ce va returna numarul de studenti din acesta
     * => 10) VA EXISTA O FUNCTIE DE CASTARE LA FLOAT PENTRU CATALOG, ce va returna media notelor studentilor din catalog
     */
    printf (
            "Catalog : %s ( %d students ==> average : %.2f )\n",
            ( char const * ) c,
            ( int ) c,
            ( float ) c
    );

    /**
     * I'm sorry, iteratori.
     *
     * Ne amintim : forma de mai jos se expandeaza la :
     *
     * for ( auto it = c.begin(); it != c.end(); ++ it ) {
     *     ??? a = * it; /// am lasat ??? pentru ca nu stim ce este la acest moment
     *     a.Print ();
     * }
     *
     * Moreover, conceptul iteratiei inseamna parcurgerea obiectului
     * Daca parcurgem un catalog, putem concluziona ca fiecare element este un Student
     *
     * -> asadar, ??? de mai sus se inlocuiesc cu Student
     *      "Student a = * it;"
     *
     * => 11) CLASA CATALOG VA AVEA UN OBIECT ITERATOR
     * => 12) VOM AVEA O FUNCTIE BEGIN SI UNA DE END IN CATALOG, ce ne returneaza
     *          "capetele" catalogului. Intrucat este usor sa implementam cu un vector,
     *          vom considera iteratorul ca merge peste indecsii vectorului
     *          => 12.1) BEGIN VA RETURNA ITERATOR CU INDEX 0
     *          => 12.2) END VA RETURNA ITERATOR CU INDEX N, unde N este numarul de elemente
     *          ( 0..N, unde o parcurgere clasica ar fi
     *              for ( int i = 0; i != n; ++ i ) {
     *                  c.students[i].Print();
     *              }
     *          )
     * => 13) ITERATORUL ARE NEVOIE DE
     *      -> ++ it         => 13.1) OPERATOR ++ ()
     *      -> it != c.end() => 13.2) OPERATOR != (Iterator)
     *      -> * it          => 13.3) OPERATOR * ()
     *
     * "Pauza de 5 min de refresh. Iterators are hell"
     */
    for ( auto a : c ) {
        a.Print ();
    }

    /**
     * Din logica if-ului, putem concluziona ca
     *
     * => 14) CATALOG ARE O FUNCTIE ==, ce primeste un string ( char const * ) ca si parametru
     *      14.1) ACEASTA VERIFICA DACA EXISTA UN STUDENT CU NUMELE DAT CA SI PARAMETRU
     */
    if ( c == "Ionescu" ) {
        printf ("Ionescu exists in catalog !\n");
    } else {
        printf ("Ionescu DOES NOT exist in catalog !\n");
    }

    /**
     * Analog mai sus
     */
    if ( c == "Georgescu" ) {
        printf ("Georgescu exists in catalog !\n");
    } else {
        printf ("Georgescu DOES NOT exist in catalog !\n");
    }

    /**
     * Putea incepe cu asta. Nu cu nebunia de mai sus.
     * Aici se intele mai clar ca se adauga studenti.
     */
    c += { "Marin", 8 };
    c += { "Popovici", 7 };

    /**
     * Asemenea +=, exista si un -=, doar ca ia doar un string
     *
     * => 15) EXISTA UN OPERATOR -= CE IA UN STRING CA SI PARAMETRU SI SCOATE STUDENTUL
     *      CU NUMELE DAT CA SI PARAM.
     *
     * => 15.1) SE APLICA OBS. 6 SI AICI
     */
    c -= "Popescu";

    /**
     * Analog first printf
     */
    printf (
            "Catalog : %s ( %d students )\n",
            ( char const * ) c,
            ( int ) c
    );

    /**
     * Iarasi oribilitatea de mai sus
     *
     * Nu am mentionat mai sus, dar putem concluziona cate ceva si din Student :: Print ()
     *
     *      "Student: Marin => Grade: 8"
     *
     *      => 16) PRINT VA AFISA NUMELE SI NOTA STUDENTULUI, IN FORMAT
     *              Student: <nume> => Grade: <nota>
     *              ADICA
     *              printf ( "Student: %s => Grade: %d\n", nume, nota );
     */
    for ( auto a : c ) {
        a.Print ();
    }

    return 0;
}