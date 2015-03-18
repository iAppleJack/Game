//
//  Menu.cpp
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//
#include "oxygine-framework.h"
#include "Menu.h"
#include "res.h"
#include "Game.h"
using namespace oxygine;
void load()
{
    res::load();
    spGame game = new Game;
	game->init();
    game->attachTo(getStage());


}