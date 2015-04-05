//
//  Warrior.cpp
//  Game_macosx
//
//  Created by iAppleJack on 03/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Warrior.h"

#include "res.h"
#include "oxygine-framework.h"
using namespace oxygine;

Warrior::Warrior(double x , double y, double ax, double ay, std::string label, int hp):Unit( x, y, label, true, 15, ax, ay)
{
    arc = 0.0;
    
    this->maxhp = hp;
    this->hp = hp;
    this->icon->setScale(50/icon->getWidth() , 50/icon->getHeight());
    this->gomove(1.5);
    this->jumppoint = 0.3;
    
   

    //this->icon->setRotation(arc);
    
    
}


