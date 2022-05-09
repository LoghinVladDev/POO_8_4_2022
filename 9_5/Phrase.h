//
// Created by uic70278 on 5/9/2022.
//

#ifndef POO_8_4_2022_PHRASE_H
#define POO_8_4_2022_PHRASE_H

class Phrase {
private:
    char words [128][128];
    int length=0;
public:
    Phrase ( char const * );
    operator int () const;
    char const * operator[]
            (int) const;

    ~Phrase() = default;

    int CountLetter (
            int,
            char
    ) const;

    int CountLetter (
            char
    ) const;

    char const *
    GetLongestWord () const;

    int CountVowels () const;

    Phrase ();

    Phrase & operator = (
            char const *
    );

public:
    class Iterator {
    private:
        int         index;
        Phrase    * phrase;
    public:
        Iterator (
                int index,
                Phrase * phrase
        ) {
            this->index = index;
            this->phrase = phrase;
        }

        bool operator != (
                Iterator
        ) const;

        Iterator &
        operator ++ ();

//        Iterator
//        operator ++ (int);

        char const *
        operator * ();
    };

    Iterator begin ();
    Iterator end ();
};


#endif //POO_8_4_2022_PHRASE_H
