//
//  Runner.h
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__Runner__
#define __Game_macosx__Runner__

#include <iostream>

#include "Unit.h"
#include "res.h"
#include "oxygine-framework.h"

#endif /* defined(__Game_macosx__Box__) */

class Runner: public Unit
{
public:
    int team;
    double arc;
    int hp;
    std::string path;
    Runner(double x , double y, double ax, double ay, std::string label);
    
    void rotate ();
    
};