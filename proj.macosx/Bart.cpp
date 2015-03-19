//
//  Bart.cpp
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Bart.h"
#include "res.h"
#include "oxygine-framework.h"

Bart::Bart ()
{

    
};

Bart::Bart(double x, double y)
{
    this->speed.x = 0;
    this->speed.y = 0;
    this->step = 0;
    this->icon = new Sprite();
    this->icon->setPosition(x,y);
    ResAnim *animation = res::ui.getResAnim("anim");
    this->icon->addTween(TweenAnim(animation), 500, -1);
}

Bart::~Bart()
{
    
}

void Bart::inic()
{
    
}


void Bart::moveto(double x, double y)
{
    
}