//
//  Background.h
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__Background__
#define __Game_macosx__Background__
#include "oxygine-framework.h"

#include <iostream>

#endif /* defined(__Game_macosx__Background__) */



class Background
{
private:
    int width;
    int height;
public:
    double speedlevel; // задаем на сколько медленее двигается фон относительно персонажа
    oxygine::spSprite icon1;
    oxygine::spSprite icon2;
    Background(double x , double y, int width, int height, double speedlevel, std::string path);
    void move(double speed);
    
};