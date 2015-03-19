//
//  Background.cpp
//  Game_macosx
//
//  Created by iAppleJack on 19/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Background.h"
#include "res.h"
#include "oxygine-framework.h"
Background::Background (double width, double height)
{
    this->width = width;
    this->height = height;
    this->icon1 = new Sprite();
    this->icon2 = new Sprite();
    
    this->icon3 = new Sprite();
    this->icon4 = new Sprite();

    this->icon2->setPosition(width, 0);
    ResAnim *animation1 = res::ui.getResAnim("background1");
    this->icon1->addTween(TweenAnim(animation1), 500, -1);
    ResAnim *animation2 = res::ui.getResAnim("background1");
    this->icon2->addTween(TweenAnim(animation2), 500, -1);
    this->icon1->setScale(this->width/icon1->getWidth(), this->height/icon1->getHeight());
    this->icon2->setScale(width/icon2->getWidth(), height/icon2->getHeight());
    
    
    this->icon4->setPosition(width, 0);
    ResAnim *animation3 = res::ui.getResAnim("background2");
    this->icon3->addTween(TweenAnim(animation3), 500, -1);
    
    this->icon4->addTween(TweenAnim(animation3), 500, -1);
    this->icon3->setScale(this->width/icon3->getWidth(), this->height/icon3->getHeight());
    this->icon4->setScale(width/icon4->getWidth(), height/icon4->getHeight());
}

void Background::moveTo(double x)
{
    this->icon1->setX(this->icon1->getX() + x);
    this->icon2->setX(this->icon2->getX() + x);
    if (this->icon2->getX() <= 0)
    {
        this->icon1->setX(this->icon1->getX() + this->width);
        this->icon2->setX(this->icon2->getX() + this->width);
    }
    if (this->icon1->getX() > 0)
    {
        this->icon1->setX(this->icon1->getX() - this->width);
        this->icon2->setX(this->icon2->getX() - this->width);
    }
    
    this->icon3->setX(this->icon3->getX() + (x/3));
    this->icon4->setX(this->icon4->getX() + (x/3));
    if (this->icon4->getX() <= 0)
    {
        this->icon3->setX(this->icon3->getX() + this->width);
        this->icon4->setX(this->icon4->getX() + this->width);
    }
    if (this->icon3->getX() > 0)
    {
        this->icon3->setX(this->icon3->getX() - this->width);
        this->icon4->setX(this->icon4->getX() - this->width);
    }
    //if (this->icon1->getX() < 0)
   // {
      //  this->icon1->setX(this->icon1->getX() + this->width);
    //    this->icon2->setX(this->icon2->getX() + this->width);
    //}
    
}