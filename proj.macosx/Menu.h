//
//  Menu.h
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//
#pragma once
#include "oxygine-framework.h"
#include "res.h"
#include <list>
using namespace oxygine;
class Menu: public Actor
{
public:
    Menu();
    spTextField _text;
	spSprite	_button;
    
    
    spTextField _rtext;
	spSprite	_rbutton;
    
    spTextField _ltext;
	spSprite	_lbutton;
    void load();
    void nextTakt(oxygine::Event *e);
    void deleteUnit(int unitid);
    void includeButton(spSprite &tempbutton , double x, double y, std::string label);
    void buttonClicked(Event *e);
    void rightclick(Event *e);
    void addcalback (spSprite &s);
    void gravity();
    
};

