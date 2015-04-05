//
//  Box.cpp
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Box.h"


Box::Box(double x , double y, int width, int height):Unit( x, y, "box", false, 0)
{
    this->icon->setScale(width/icon->getWidth() , height/icon->getHeight());
    //this->icon->setRotation(arc);
    
    
}



