
#pragma once
#include "oxygine-framework.h"
#include <list>
using namespace oxygine;

DECLARE_SMART(Game, spGame);

class Game: public Actor
{
public:
   
    
	Game();
	~Game();
    void phisic();
	void init();
    void keylistener(Event *event);
};