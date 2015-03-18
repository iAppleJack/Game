//
//  Unit.h
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#pragma once
#include "oxygine-framework.h"
#include <list>
using namespace oxygine;

DECLARE_SMART(Unit, bart );


class Unit: public Actor
{
public:
	Unit();
	~Unit();
    
	void init();
    void move ();
};