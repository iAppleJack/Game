//
//  Runner.cpp
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Runner.h"
#include "res.h"
#include "oxygine-framework.h"
using namespace oxygine;

Runner::Runner(double x , double y, double ax, double ay, std::string label):Unit( x, y, label, true, 15, ax, ay)
{
    arc = 0.0;

    
    this->icon->setScale(50/icon->getWidth() , 50/icon->getHeight());
    this->gomove(1.5);
    this->jumppoint = 0.3;
   
    //this->icon->setRotation(arc);
    
    
}

void Runner::rotate()
{
    this->arc += 0.18;
    this->icon->setRotation(this->arc);
}