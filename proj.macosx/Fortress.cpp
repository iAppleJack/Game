//
//  Fortress.cpp
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Fortress.h"



Fortress::Fortress(double x , double y, int width, int height):Unit( x, y, "FRT", false, 0)
{
    this->icon->setScale(width/icon->getWidth() , height/icon->getHeight());
    //this->icon->setRotation(arc);
    
    
}

