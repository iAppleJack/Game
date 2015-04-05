//
//  Land.h
//  Game_macosx
//
//  Created by iAppleJack on 01/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__Land__
#define __Game_macosx__Land__

#include <iostream>

#include "Unit.h"

#endif /* defined(__Game_macosx__Box__) */

DECLARE_SMART(Land, land);
class Land: public Unit
{
public:
    Land(double x , double y, int width, int height, std::string path);
    
};