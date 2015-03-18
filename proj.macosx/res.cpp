//
//  res.cpp
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//
#include "res.h"

namespace res
{
	Resources ui;
    
	void load()
	{
		ui.loadXML("res.xml");

	}
    
	void free()
	{
		ui.free();
        
	}
}