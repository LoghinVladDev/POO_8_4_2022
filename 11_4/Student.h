//
// Created by uic70278 on 4/11/2022.
//

#ifndef POO_8_4_2022_STUDENT_H
#define POO_8_4_2022_STUDENT_H

#define NR_MAX_MATERII 128

class Student {
private:
    char nume [ 256 ];

    struct Materie {
        char         nume [ 256 ];
        int          medie;
    };

    Materie materii [ NR_MAX_MATERII ];
    int     nrMaterii;

public:

    Student ();
    Student ( char const * nume );

    char const * GetName () const;

    int & operator [] ( char const * materie );

    operator float () const;
    void PrintNote () const;
};


#endif //POO_8_4_2022_STUDENT_H
