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

    operator bool ();
    operator int();

    Rectangle operator & ( Rectangle );

    Punct GetTopLeftPoint ();
    Punct GetTopRightPoint ();
    Punct GetBottomLeftPoint ();
    Punct GetBottomRightPoint ();

    int Width ();
    int Height ();

    class Iterator {
    private:
        Rectangle * pRectangle;
        int         pointIndex;

    public:
        Iterator ( Rectangle * pRectangle, int index );
        Iterator operator ++ ();
        bool operator != ( Iterator it );
        Punct operator * ();
    };

    Iterator begin ();
    Iterator end ();
};


#endif //POO_8_4_2022_RECTANGLE_H
