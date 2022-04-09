//
// Created by loghin on 4/9/22.
//

#ifndef POO_8_4_2022_RECTANGLE_H
#define POO_8_4_2022_RECTANGLE_H

#include "Punct.h"

class Rectangle {
private:
    Punct upperLeft;
    Punct lowerRight;

public:
    Rectangle ( int x1, int y1, int x2, int y2 );

    operator bool () const;
    operator int() const;

    Rectangle operator & ( Rectangle const & ) const;

    Punct GetTopLeftPoint () const;
    Punct GetTopRightPoint () const;
    Punct GetBottomLeftPoint () const;
    Punct GetBottomRightPoint () const;

    int Width () const;
    int Height () const;

    class Iterator {
    private:
        Rectangle   const * pRectangle;
        int                 pointIndex;

    public:
        Iterator ( Rectangle const * pRectangle, int index );
        Iterator operator ++ ();
        bool operator != ( Iterator const & it ) const;
        Punct operator * () const;
    };

    Iterator begin () const;
    Iterator end () const;
};


#endif //POO_8_4_2022_RECTANGLE_H
