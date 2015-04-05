//
//  jButton.h
//  Game_macosx
//
//  Created by iAppleJack on 02/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#ifndef __Game_macosx__jButton__
#define __Game_macosx__jButton__

#include <iostream>
#include "oxygine-framework.h"
#include "res.h"
using namespace oxygine;


#endif /* defined(__Game_macosx__jButton__) */


class jButton {
    
public:
    oxygine::spSprite button;
    spTextField text = new TextField();
    jButton(double x, double y, std::string text, EventCallback _cb);
    void right(Event *e);
};