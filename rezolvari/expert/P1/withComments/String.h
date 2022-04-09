//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_STRING_H
#define POO_8_4_2022_STRING_H

/// am definit tipul String pentru a nu lucra cu functii / string-uri prestabilite in marime
class String {
private:

    /// un string e defapt un wrapper peste un char * si un length ( + capacity, dar nu se aplica,
    ///     nu il redimensionam )
    char * pString = nullptr;
    int    len     = 0;

public:
    /// serie de functii
    /// ctor default, ctor din char *, ctor din String ( copy ctor ) si dtor
    /// destructor OBLIGATORIU, alocam dinamic

    /// observam cuvant nou -> noexcept
    /// inseamna ca functia nu arunca exceptii ( nu are throw statement inauntru )
    /// e de optimizare
    String () noexcept = default;
    explicit String ( char const * ) noexcept;
    String ( String const & ) noexcept;
    ~String () noexcept;

    /// operator == cu char *
    /// observam atributul [[nodiscard]] -> return value-ul trebuie folosit
    /// indicam sa genereze un warning daca nu folosim return type-ul
    /// adica daca scriem in main
    /// s == "abc";  <- valoare nefolosita, nu facem nimic cu rezultatul => compiler warning
    [[nodiscard]] bool operator == ( char const * ) const noexcept;

    /// operatori copiere
    String & operator = ( char const * ) noexcept;
    String & operator = ( String const & ) noexcept;

    /// functie pentru a obtine char *-ul interior
    [[nodiscard]] char const * c_str() const noexcept;
};

#endif //POO_8_4_2022_STRING_H
