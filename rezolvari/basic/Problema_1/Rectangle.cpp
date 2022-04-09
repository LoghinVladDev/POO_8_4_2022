//
// Created by loghin on 4/9/22.
//

#include <algorithm>
#include "Rectangle.h"

Rectangle :: Rectangle ( int x1, int y1, int x2, int y2 ) {

    if ( x1 < x2 ) {
        this->upperLeft.x   = x1;
        this->lowerRight.x  = x2;
    } else {
        this->upperLeft.x   = x2;
        this->lowerRight.x  = x1;
    }

    if ( y1 < y2 ) {
        this->upperLeft.y   = y1;
        this->lowerRight.y  = y2;
    } else {
        this->upperLeft.y   = y2;
        this->lowerRight.y  = y1;
    }
}

Rectangle :: operator bool () {
    int width   = this->lowerRight.x - this->upperLeft.x;
    int height  = this->lowerRight.y - this->upperLeft.y;

    if ( width == height ) {
        return true;
    } else {
        return false;
    }
}

Rectangle :: operator int () {
    int width   = this->lowerRight.x - this->upperLeft.x;
    int height  = this->lowerRight.y - this->upperLeft.y;

    return width * height;
}

Rectangle Rectangle :: operator & ( Rectangle otherRectangle ) {
    Punct newRectUpperLeft;
    Punct newRectLowerRight;

    if ( this->upperLeft.x < otherRectangle.upperLeft.x ) {
        newRectUpperLeft.x = this->upperLeft.x;
    } else {
        newRectUpperLeft.x = otherRectangle.upperLeft.x;
    }

    if ( this->upperLeft.y < otherRectangle.upperLeft.y ) {
        newRectUpperLeft.y = this->upperLeft.y;
    } else {
        newRectUpperLeft.y = otherRectangle.upperLeft.y;
    }

    if ( this->lowerRight.x < otherRectangle.lowerRight.x ) {
        newRectLowerRight.x = otherRectangle.lowerRight.x;
    } else {
        newRectLowerRight.x = this->lowerRight.x;
    }

    if ( this->lowerRight.y < otherRectangle.lowerRight.y ) {
        newRectLowerRight.y = otherRectangle.lowerRight.y;
    } else {
        newRectLowerRight.y = this->lowerRight.y;
    }

    Rectangle newRectangle = {
            newRectUpperLeft.x,
            newRectUpperLeft.y,
            newRectLowerRight.x,
            newRectLowerRight.y
    };

    return newRectangle;
}

Punct Rectangle :: GetTopLeftPoint () {
    return this->upperLeft;
}

Punct Rectangle :: GetBottomRightPoint () {
    return this->lowerRight;
}

Punct Rectangle :: GetTopRightPoint () {
    Punct upperRight = this->upperLeft;
    upperRight.x += this->Width();

    return upperRight;
}

Punct Rectangle :: GetBottomLeftPoint () {
    Punct lowerLeft = this->lowerRight;
    lowerLeft.x -= this->Width();

    return lowerLeft;
}

int Rectangle :: Width() {
    int width = this->lowerRight.x - this->upperLeft.x;
    return width;
}

int Rectangle :: Height() {
    int height = this->lowerRight.y - this->upperLeft.y;
    return height;
}

Rectangle :: Iterator Rectangle :: begin () {
    return Iterator ( this, 0 );
}

Rectangle :: Iterator Rectangle :: end () {
    return Iterator ( this, 4 );
}

Rectangle :: Iterator :: Iterator ( Rectangle * pRectangle, int index ) :
        pRectangle ( pRectangle ),
        pointIndex ( index ) {

}

Rectangle :: Iterator Rectangle :: Iterator :: operator ++ () {
    this->pointIndex ++;
    return * this;
}

bool Rectangle :: Iterator :: operator != ( Iterator it ) {
    if ( this->pointIndex != it.pointIndex ) {
        return true;
    } else {
        return false;
    }
}

Punct Rectangle :: Iterator :: operator * () {
    switch ( this->pointIndex ) {
        case 0: return this->pRectangle->GetTopLeftPoint();
        case 1: return this->pRectangle->GetTopRightPoint();
        case 2: return this->pRectangle->GetBottomRightPoint();
        case 3: return this->pRectangle->GetBottomLeftPoint();
    }
}
