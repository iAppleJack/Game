//
//  Box.h
//  Game_macosx
//
//  Created by iAppleJack on 19/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__Box__
#define __Game_macosx__Box__

#include <iostream>

#endif /* defined(__Game_macosx__Box__) */


#include "oxygine-framework.h"
#include <list>
using namespace oxygine;

class Box
{
private:
public:
    Vector2 size;
    spSprite icon;
    
    Box(double width, double height, double x, double y);
    

};