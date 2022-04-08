//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STUDENT_H
#define POO_8_4_2022_STUDENT_H


class Student {
private:
    char const * pName;
    int          grade;

public:
    Student () = default;
    Student ( char const * pName, int grade );
    void Print ();

    char const * getName ();
    int          getGrade ();

    bool is ( char const * );
};


#endif //POO_8_4_2022_STUDENT_H
