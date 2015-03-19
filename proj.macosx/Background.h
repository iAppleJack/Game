//
//  Background.h
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

class Background
{
private:
    double height;
    double width;
    
public:
    spSprite icon1;
    spSprite icon2;
    
    spSprite icon3;
    spSprite icon4;
    Background(double width, double height);
    void moveTo(double x);
    
    
};