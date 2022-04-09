//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STUDENT_H
#define POO_8_4_2022_STUDENT_H

#include "String.h"

class Student {
private:
    String       name;
    int          grade = 0;

public:
    Student () noexcept = default;
    Student ( char const * pName, int grade ) noexcept;
    void Print () const noexcept;

    [[nodiscard]] char const * getName () const noexcept;
    [[nodiscard]] int          getGrade () const noexcept;

    [[nodiscard]] bool is ( char const * ) const noexcept;
};


#endif //POO_8_4_2022_STUDENT_H
