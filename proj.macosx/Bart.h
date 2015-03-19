//
//  Bart.h
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//
#pragma once
#include "oxygine-framework.h"
#include <list>
using namespace oxygine;

class Bart
{
private:
    int status;
public:
    Vector2 speed;
    spSprite icon;
    double lenght;
    int step;
    Bart();
    Bart(double x, double y);
    ~Bart();
    
    void inic();
    void moveto(double x, double y);
};