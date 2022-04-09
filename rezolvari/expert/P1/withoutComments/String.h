//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STRING_H
#define POO_8_4_2022_STRING_H

class String {
private:
    char * pString = nullptr;
    int    len     = 0;

public:
    String () noexcept = default;
    explicit String ( char const * ) noexcept;
    String ( String const & ) noexcept;
    ~String () noexcept;

    [[nodiscard]] bool operator == ( char const * ) const noexcept;
    String & operator = ( char const * ) noexcept;
    String & operator = ( String const & ) noexcept;

    [[nodiscard]] char const * c_str() const noexcept;
};

#endif //POO_8_4_2022_STRING_H
