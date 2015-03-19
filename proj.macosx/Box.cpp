//
//  Box.cpp
//  Game_macosx
//
//  Created by iAppleJack on 19/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Box.h"
#include "res.h"
#include "oxygine-framework.h"
Box::Box(double width, double height,  double x, double y)
{
    this->size.x = width;
    this->size.y = height;
    this->icon = new Sprite();
    this->icon->setPosition(x,y);
    
    ResAnim *animation = res::ui.getResAnim("box");
    this->icon->addTween(TweenAnim(animation), 500, -1);
}