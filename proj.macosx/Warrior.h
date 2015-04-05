//
//  Warrior.h
//  Game_macosx
//
//  Created by iAppleJack on 03/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__Warrior__
#define __Game_macosx__Warrior__

#include <iostream>

#include "Unit.h"
#include "res.h"
#include "oxygine-framework.h"

#endif /* defined(__Game_macosx__Box__) */

class Warrior: public Unit
{
public:
    int team;
    double arc;

    std::string path;
    Warrior(double x , double y, double ax, double ay, std::string label, int hp);
        
};