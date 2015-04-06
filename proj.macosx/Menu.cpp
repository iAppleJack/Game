//
//  Menu.cpp
//  Game_macosx
//
//  Created by iAppleJack on 18/03/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//
#include "oxygine-framework.h"

#include "Box.h"
#include "Fortress.h"
#include "Menu.h"
#include "res.h"
#include "Land.h"
#include "Runner.h"
#include "Background.h"
#include "Button.h"


using namespace oxygine;

Menu::Menu()
{
    load();
}



Unit *us;

spTextField mtf;
Fortress *redFortress;
Fortress *blueFortress ;
std::vector<Unit*> units;
std::vector<Unit*> builds;
std::vector<Background*> backgrounds;
int takt = 0;
void Menu::load()
{
    
    res::load();
    
    mtf = new TextField();
    //attach it as child to button
    
    //centered in button
    mtf->setPosition(100,100);
    
    //initialize text style
    TextStyle style;
    style.font = res::ui.getResFont("main")->getFont();
    
    style.fontSize2Scale = 30;
    style.color = Color::Green;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_CENTER;
    
    mtf->setStyle(style);
	addChild(mtf);
    us  = new Unit(100,100,"mouse", true,5 );
    
    
   
   
  //  addChild(us->icon);

    backgrounds.push_back(new Background(0 , 0,getStage()->getWidth(), getStage()->getHeight(),  0.6, "background1"));
    builds.push_back(new Land (0 , (getStage()->getHeight()*0.95) , 5000, 1000, "pump"));
    
    
     redFortress = new Fortress( 10 , builds[0]->icon->getY() - 200, 200, 200);
    blueFortress = new Fortress( 3000 , builds[0]->icon->getY() - 200, 200, 200);
    builds.push_back(redFortress);
    builds.push_back(blueFortress);
    
   // builds.push_back(new Fortress(100, builds[0]->icon->getY() - 200,200,200));
    
       //units.push_back(new Wa(0, 10,0.5f,0.5f, "mouse"));
   // units.push_back(new Runner(80, 10,0.0,0.0));
  //  units.push_back(new Box(0 , 300, 200, 50));
    builds.push_back(new Box(300, builds[0]->icon->getY()-100,50,100));
    builds.push_back(new Box(500, builds[0]->icon->getY()-100,250,100));
    builds.push_back(new Box(575, builds[0]->icon->getY()-200,150,100));
     builds.push_back(new Box(655, builds[0]->icon->getY()-300,150,100));
    
    
  //  units.push_back(new Box(400 , 220, 200, 50));
  //  units.push_back(new Box(600 , 520, 100, 50));
   // units.push_back(new Box(700 , 320, 300, 50));
    
    //units.erase(units.begin()+1, units.begin()+2);
    for (int i = 0; i < backgrounds.size(); i++)
    {
        addChild(backgrounds[i]->icon1);
        addChild(backgrounds[i]->icon2);
    }
    for (int i = 0; i < units.size(); i++)
    {
        addChild(units[i]->icon);
        addChild(units[i]->hp->icon);
    }
    
    for (int i = 0; i < builds.size(); i++)
    {
        addChild(builds[i]->icon);
    }
   // addChild(us->icon);
    //removeChild(us2->icon);
  
    //units.clear();
    
    //Button btest = Button();
    //btest.setResAnim(res::ui.getResAnim("button"));
    //addChild(&btest);
   
    //units[0]->stopmove(1.2);
    /*game = new Game;
	game->init();
    game->attachTo(getStage());*/
    
    spTween t = this->addTween(TweenDummy(), 16.6);
	t->setDoneCallback(CLOSURE(this, &Menu::nextTakt));
     this->attachTo(getStage());
     includeButton(_button,500,100, "test");
    includeButton(_rbutton,900,100, "right");
    includeButton(_lbutton,0,100, "left");
    EventCallback cb = CLOSURE(this, &Menu::buttonClicked);
    _button->addEventListener(TouchEvent::CLICK, cb);
    
    EventCallback cbr = CLOSURE(this, &Menu::rightclick);
    _rbutton->addEventListener(TouchEvent::CLICK, cbr);
}

void Menu::deleteUnit(int unitid)
{
    removeChild(units[unitid]->hp->icon);
    removeChild(units[unitid]->icon);
    
    delete units[unitid]->hp;
    delete units[unitid];
    units.erase(units.begin() + unitid);
   // delete &u;
    
}

void Menu::nextTakt(Event *e)
{
    
   
    
   // mtf->setText("test " + std::to_string(units[0]->icon->getWidth()));
    //units[2]->gomove(5);
    gravity();
    for (int i = 0; i < units.size(); i++)
    {
        
        units[i]->move();
        units[i]->hp->hp --  ;
        
    }
    for (int i = 0; i < units.size(); i++)
    {
        if ( units[i]->hp->hp <= 0)
        {
            deleteUnit(i);
            break;
        }
    }
    
   // us->gravity(units);
   // us->move();
   // printf("te");
    //Runner *r = (Runner*)units[0];
    //r->rotate();
    spTween t = this->addTween(TweenDummy(), 16.6);
	t->setDoneCallback(CLOSURE(this, &Menu::nextTakt));
}


void Menu::includeButton(spSprite &tempbutton , double x, double y, std::string label)
{
    spSprite button = new Sprite();
    button->setResAnim(res::ui.getResAnim("button"));
    //Vector2 pos = getStage()->getSize()/2 - button->getSize()/2;
    button->setPosition(x,y);
    //EventCallback cb = CLOSURE(this, &Menu::buttonClicked);
    //button->addEventListener(TouchEvent::CLICK, cb);
    addChild(button);
    
    tempbutton = button;

    //create TextField Actor
    spTextField text = new TextField();
    text->attachTo(button);
    text->setPosition(button->getSize()/2);
    
    //initialize text style
    TextStyle style;
    style.font = res::ui.getResFont("main")->getFont();
    style.color = Color::White;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_CENTER;
    
    text->setStyle(style);
    text->setText(label);
    
    _text = text;
}


void Menu::buttonClicked(Event *event)
{
    //user clicked to button
    
    //animate button by chaning color
    _button->setColor(Color::White);
    _button->addTween(Sprite::TweenColor(Color::Green), 500, 1, true);
    
    //animate text by scaling
    _text->setScale(1.0f);
    _text->addTween(Actor::TweenScale(1.1f), 500, 1, true);
    
    //and change text
    for (int i = 0; i < 4 ; i ++ ){
    int a = rand()%2;
    Runner* r ;
    if (a == 0)
    {
        r = new Runner(0, 10,0.5f,0.5f, "mouse");
    }else
    {
        r = new Runner(0, 10,0.5f,0.5f, "gad");

    }
       //Runner* r = new Runner(0, 10,0.5f,0.5f, "mouse");
    r->gomove(0.3 + (rand()%100)*0.014);
    addChild(r->icon);
    addChild(r->Unit::hp->icon);
    units.push_back(r);
    }
    //lets create and run sprite with simple animation
    
}


void Menu::rightclick(Event *event)
{
    //user clicked to button
    
    //animate button by chaning color
    _rbutton->setColor(Color::White);
    _rbutton->addTween(Sprite::TweenColor(Color::Green), 500, 1, true);
    
    //animate text by scaling
    _text->setScale(1.0f);
    _text->addTween(Actor::TweenScale(1.1f), 500, 1, true);
    
    //and change text
    for (int i = 0; i < backgrounds.size(); i++)
    {
        Background* b =(Background*) backgrounds[i];
        b->icon1->setX(b->icon1->getX() - 15*0.6l);
        b->icon2->setX(b->icon2->getX() - 15*0.6);
        
    }
    for (int i = 0; i < units.size(); i++)
    {
        Unit* u = (Unit*) units[i];
        u->icon->setX(u->icon->getX() - 15);
    }
    
    for (int i = 0; i < builds.size(); i++)
    {
        Unit* u = (Unit*) builds[i];
        u->icon->setX(u->icon->getX() - 15);
    }
    
    //lets create and run sprite with simple animation
    
}


void Menu::gravity()
{
    for (int j = 0; j < units.size(); j++)
    {
        if (units[j]->isgravity)
        {
            units[j]->speed.y += 0.9834;
            
        }
    for (int i = 0; i < builds.size(); i++)
    {
        
        Unit  *unit = builds[i];
        Unit *myunitsprite = units[j];
        
        double ax1 = unit->icon->getX() - unit->icon->getWidth()*unit->icon->getScaleX()*(unit->icon->getAnchorX());
        double ax2 = unit->icon->getX() + unit->icon->getWidth()*unit->icon->getScaleX()*(1 - unit->icon->getAnchorX());
        double ay1 = unit->icon->getY() - + unit->icon->getHeight()*unit->icon->getScaleY()*(unit->icon->getAnchorY());
        double ay2 = unit->icon->getY() + unit->icon->getHeight()*unit->icon->getScaleY()*(1 - unit->icon->getAnchorX());
        
        double x1 = myunitsprite->icon->getX() - myunitsprite->icon->getWidth()*myunitsprite->icon->getScaleX()*(myunitsprite->icon->getAnchorX());
        double x2 = myunitsprite->icon->getX() + myunitsprite->icon->getWidth()*myunitsprite->icon->getScaleX()*( 1 - myunitsprite->icon->getAnchorX());
        double y1 = myunitsprite->icon->getY() - myunitsprite->icon->getHeight()*myunitsprite->icon->getScaleY()*(myunitsprite->icon->getAnchorY());
        double y2 = myunitsprite->icon->getY() + myunitsprite->icon->getHeight()*myunitsprite->icon->getScaleY()*(1 - (myunitsprite->icon->getAnchorY()));
        
        if (ax1 - x1 < 75 && ax1 - x1 > 0 &&  myunitsprite->speed.y < 0.2 && myunitsprite->speed.y >= - 0.2)
        {
            //this->speed.y = - 15;
            myunitsprite->jump();
        }
        
        if ((
             
             ((x1 >= ax1 && x1 <= ax2)
              || (x2 >= ax1 && x2 <= ax2)
              
              )
             &&
             
             ((y1 >= ay1 && y1 <= ay2)
              || (y2 >= ay1 && y2 <= ay2)
              
              
              )
             
             
             )
            
            && myunitsprite->speed.y > 0
            
            && unit != myunitsprite  )
        {
            
            myunitsprite->speed.y = -(myunitsprite->jumppoint)*myunitsprite->speed.y;
            // jump();
            
        }
        
    }
    }
}


