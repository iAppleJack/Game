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

Menu::Menu()
{
    load();
}
spGame game;
void Menu::load()
{
    res::load();
    game = new Game;
	game->init();
    game->attachTo(getStage());
    spTween t = game->addTween(TweenDummy(), 16.6);
	t->setDoneCallback(CLOSURE(this, &Menu::nextTakt));
    
}

void Menu::nextTakt(Event *e)
{
    game->phisic();
    spTween t = game->addTween(TweenDummy(), 16.6);
	t->setDoneCallback(CLOSURE(this, &Menu::nextTakt));
}

