//
//  HP.h
//  Game_macosx
//
//  Created by iAppleJack on 04/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__HP__
#define __Game_macosx__HP__

#include <iostream>
#include "oxygine-framework.h"
#include <list>
using namespace oxygine;
#endif /* defined(__Game_macosx__HP__) */


class HP
{
public:
    spSprite icon;
    int maxhp;
    int hp;
    int unitwidth;
    int unitheight;
    
    HP(double x, double y, int _maxhp, int width,  int height);
    void move(double x, double y);
    

    
};