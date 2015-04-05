//
//  Bart.cpp
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Unit.h"
#include "res.h"
#include "oxygine-framework.h"
using namespace oxygine;
Unit::Unit ()
{
    
    
};

Unit::Unit(double x, double y, std::string path, bool grav, double jump, double ax, double ay )
{
    this->jumppoint = 0.6;
    this->speed.x = 0;
    this->isgravity = grav;
    this->speed.y = 0;
    this->_jump = jump;
    this->icon = new Sprite();
    this->icon->setAnchorX(ax);
    this->icon->setAnchorY(ay);
    this->icon->setPosition(x + 50*icon->getAnchorX(),y + 50*icon->getAnchorY());
    ResAnim *animation = res::ui.getResAnim(path);
    TweenAnim tw = TweenAnim(animation);
    hp = new HP(x,y,10, 50,  50);
    
    
    //this->icon->setPosition(0, 50);
    if (grav)
    {
       
        tw= TweenAnim(animation,1);
        //tw.setColumns(1, 6);
        //tw.setRow(1);
        
        //tw.getRow();
        
    }
    
   // icon->setRow(2);
    this->icon->addTween(tw, 700, -1);
}

Unit::~Unit()
{
    
}

void Unit::gomove(double x)
{
    this->speed.x += x;
};


void Unit::stopmove(double x)
{
    this->speed.x -= x;
};

void Unit::jump()
{
    if ((int)this->speed.y == 0)
    {
            this->speed.y -= _jump;
    }
}

void Unit::move()
{
    this->icon->setX(this->icon->getX() + this->speed.x);
    this->icon->setY(this->icon->getY() + this->speed.y);
    this->hp->move(this->icon->getX(), this->icon->getY());
}

void Unit::gravity(std::vector<Unit*> &units)
{
   // units.push_back(new Unit(100 + rand()%200 ,200,"anim", false,5) );
    
    
   
}