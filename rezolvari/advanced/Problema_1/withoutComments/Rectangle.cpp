//
// Created by loghin on 4/9/22.
//

#include <algorithm>
#include "Rectangle.h"

using namespace std;

Rectangle :: Rectangle ( int x1, int y1, int x2, int y2 ) :
        upperLeft ( min ( x1, x2 ), min ( y1, y2 ) ),
        lowerRight ( max ( x1, x2 ), max ( y1, y2 ) ) {

}

Rectangle :: operator bool () const {
    return this->Width() == this->Height();
}

Rectangle :: operator int () const {
    return this->Width() * this->Height();
}

Rectangle Rectangle :: operator & ( Rectangle const & otherRectangle ) const {

    return {
        min ( this->upperLeft.x, otherRectangle.upperLeft.x ),
        min ( this->upperLeft.y, otherRectangle.upperLeft.y ),
        max ( this->lowerRight.x, otherRectangle.lowerRight.x ),
        max ( this->lowerRight.y, otherRectangle.lowerRight.y )
    };
}

Punct Rectangle :: GetTopLeftPoint () const {
    return this->upperLeft;
}

Punct Rectangle :: GetBottomRightPoint () const {
    return this->lowerRight;
}

Punct Rectangle :: GetTopRightPoint () const {
    return {
        this->upperLeft.x + this->Width(),
        this->upperLeft.y
    };
}

Punct Rectangle :: GetBottomLeftPoint () const {
    return {
        this->lowerRight.x - this->Width(),
        this->lowerRight.y
    };
}

int Rectangle :: Width() const {
    return this->lowerRight.x - this->upperLeft.x;
}

int Rectangle :: Height() const {
    return this->lowerRight.y - this->upperLeft.y;
}

Rectangle :: Iterator Rectangle :: begin () const {
    return { this, 0 };
}

Rectangle :: Iterator Rectangle :: end () const {
    return { this, 4 };
}

Rectangle :: Iterator :: Iterator ( Rectangle const * pRectangle, int index ) :
        pRectangle ( pRectangle ),
        pointIndex ( index ) {

}

Rectangle :: Iterator Rectangle :: Iterator :: operator ++ () {
    this->pointIndex ++;
    return * this;
}

bool Rectangle :: Iterator :: operator != ( Iterator const & it ) const {
    return this->pointIndex != it.pointIndex;
}

Punct Rectangle :: Iterator :: operator * () const {
    switch ( this->pointIndex ) {
        case 0: return this->pRectangle->GetTopLeftPoint();
        case 1: return this->pRectangle->GetTopRightPoint();
        case 2: return this->pRectangle->GetBottomRightPoint();
        case 3: return this->pRectangle->GetBottomLeftPoint();
    }

    return { 0, 0 };
}
