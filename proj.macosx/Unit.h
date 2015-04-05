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
#include "HP.h"
using namespace oxygine;

class Unit
{

    
private:
    
    
    double _jump;
    
public:
    HP *hp;
    Vector2 speed;
    spSprite icon;
    bool isgravity;
    double jumppoint;
    Unit();
    Unit(double x, double y, std::string path, bool grav, double _jump, double ax = 0, double ay  = 0);
    
    Unit (double x, double y, std::string path, double jump, int sizex, int sizey, int team, int hp );
    
    ~Unit();
    
    void gomove(double x);
    void stopmove(double x);
    
    void jump();
    void move();
    void gravity(std::vector<Unit*> &units);
  

    void stop();
    void forward();

    
};