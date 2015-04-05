//
//  Land.cpp
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Land.h"


Land::Land(double x , double y, int width, int height, std::string path):Unit( x, y, path, false, 0)
{
    this->icon->setScale(width/icon->getWidth() , height/icon->getHeight());
    this->icon->setWidth(width);
    this->icon->setHeight(height);

    //this->icon->setRotation(arc);
    
    
}


