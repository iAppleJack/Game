//
//  HP.cpp
//  Game_macosx
//
//  Created by iAppleJack on 04/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "HP.h"

#include "res.h"
#include "oxygine-framework.h"
using namespace oxygine;
HP::HP (double x, double y, int _maxhp, int _width, int _height)
{
    this->hp = _height;
    this->maxhp = _maxhp;
    this->unitheight = _height;
    this->unitwidth = _width;
    this->icon = new Sprite();
    
   // this->icon->setScaleX(0.5f);
   // this->icon->setScaleY(0.5f);
    this->icon->setAnchorX(0.5f);
    this->icon->setAnchorY(0.5f);
    this->icon->setPosition(x + 50*icon->getAnchorX(),y + 50*icon->getAnchorY());
    ResAnim *animation = res::ui.getResAnim("button");
    
    TweenAnim tw = TweenAnim(animation);
    this->icon->addTween(tw, 700, -1);
    this->icon->setScaleX(_width/this->icon->getWidth());
    this->icon->setScaleY(5/this->icon->getHeight());
    this->icon->setY(y - this->unitheight);
    

    
}

void HP::move (double x, double y)
{
    this->icon->setX(x);
    this->icon->setY(y - this->unitheight);
}

