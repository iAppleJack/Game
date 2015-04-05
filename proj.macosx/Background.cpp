//
//  Background.cpp
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Background.h"
#include "res.h"
#include "oxygine-framework.h"

Background::Background(double x , double y,int width, int height,  double speedlevel, std::string path)
{
    this->height = height;
    this->width = width;
    this->icon1 = new Sprite();
    
    
    this->icon2 = new Sprite();
   

    
    ResAnim *animation = res::ui.getResAnim(path);
    this->icon1->addTween(TweenAnim(animation), 500, -1);
    this->icon2->addTween(TweenAnim(animation), 500, -1);
    this->icon1->setScaleX(this->width/this->icon1->getWidth() );
    this->icon1->setScaleY(this->height/this->icon1->getHeight() );
    this->icon2->setScaleX(this->width/this->icon2->getWidth());
    this->icon2->setScaleY(this->height/this->icon2->getHeight());
    this->icon1->setPosition(x,y);
    this->icon2->setPosition(x + width,y);
}

void Background::move(double speed)
{
    this->icon1->setX(this->icon1->getX() + speed*this->speedlevel);
}