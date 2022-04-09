//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STUDENT_H
#define POO_8_4_2022_STUDENT_H

/// 4) VA EXISTA SI O CLASA STUDENT, CU UN CONSTRUCTOR CE IA UN STRING SI UN INT,
///    NUMELE SI NOTA
class Student {
private:

    /// numele studentului
    char const * pName;

    /// nota
    int          grade;

public:
    /// 4.1) ( not found in main )
    /// Pentru a putea crea un vector de studenti in Catalog ( refer to Catalog.h ), avem
    /// nevoie de constructorul implicit. ( Array-ul foloseste implicit constructor )
    ///
    /// ACESTA NU ARE NEVOIE DE IMPLEMENTARE

    /// Also, acesta ESTE necesar intrucat avem un constructor definit de noi
    /// => nu se mai creeaza automat constructor implicit
    /// => de testat -> putem comenta acest constructor, eroare generata ulterior va fi de forma
    ///     "Catalog.h" -> error: constructor for 'Catalog' must explicitly initialize the member
    ///         'students' which does not have a default constructor
    Student () = default;

    /// 4) Constructorul mentionat
    Student ( char const * pName, int grade );
    /// 16) PRINT VA AFISA NUMELE SI NOTA STUDENTULUI, IN FORMAT
    //     Student: <nume> => Grade: <nota>
    //     ADICA
    //     printf ( "Student: %s => Grade: %d\n", nume, nota );
    void Print ();

    /// creez si getteri pentru nota si nume, e nevoie de ei in Catalog
    char const * getName ();
    int          getGrade ();

    ///5.2) AICI ALEG ACEASTA METODA, Student :: is ( char const * ) este
    ///         functia ce implementeaza asta
    bool is ( char const * );
};


#endif //POO_8_4_2022_STUDENT_H
