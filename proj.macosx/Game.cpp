#include "Game.h"
#include "res.h"
#include "Bart.h"
#include "Box.h"
#include <string>

#include <vector>  //for std::vector

Game::Game()
{
	
}

Bart *b;
spSprite pump;
spTextField textfield;
spTextField testfield;
std::vector<Box> boxes;
int hit = 0;
void Game::init()
{
	//scene layer would have size of display
    
    
    
    boxes.push_back(*new Box(25,25,1100,520));
    boxes.push_back(*new Box(25,25,2500,520));
    boxes.push_back(*new Box(25,25,3200,520));
    boxes.push_back(*new Box(25,25,4000,520));
    boxes.push_back(*new Box(25,25,5000,520));
    boxes.push_back(*new Box(25,25,6000,520));
    boxes.push_back(*new Box(25,25,7500,520));
    boxes.push_back(*new Box(25,25,7600,520));
    boxes.push_back(*new Box(25,25,9000,520));
    boxes.push_back(*new Box(25,25,9350,520));
    boxes.push_back(*new Box(25,25,9350,420));
    boxes.push_back(*new Box(25,25,11000,520));
    boxes.push_back(*new Box(25,25,11100,420));
    boxes.push_back(*new Box(25,25,13000,520));
    boxes.push_back(*new Box(25,25,13500,520));
    boxes.push_back(*new Box(25,25,13900,520));
    boxes.push_back(*new Box(25,25,14300,520));
    boxes.push_back(*new Box(25,25,14500,520));
    

	setSize(getStage()->getSize());
    
    spSprite sky = new Sprite;
	sky->setResAnim(res::ui.getResAnim("sky"));
	sky->attachTo(this);
    pump = new Sprite;

    pump->setResAnim(res::ui.getResAnim("pump"));
    pump->setScale(4, 0.5);
    double pumpheight = pump->getHeight()*pump->getScaleY();
    pump->setPosition(0, getStage()->getHeight() - pumpheight);
	pump->attachTo(this);
    b = new Bart(500,200);
    b->icon->attachTo(this);

    textfield = new TextField();
    //attach it as child to button
    
    //centered in button
    textfield->setPosition(100,100);
    
    //initialize text style
    TextStyle style;
    style.font = res::ui.getResFont("main")->getFont();

    style.fontSize2Scale = 20;
    style.color = Color::Green;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_CENTER;
    
    textfield->setStyle(style);
	addChild(textfield);
    for (int i =0; i < boxes.size(); i++)
    {
        addChild(boxes[i].icon);
    }
    
    

	   
    
   /*  bart = new Sprite;
	//bart->setResAnim(res::ui.getResAnim("anim"));
    ResAnim *animation = res::ui.getResAnim("anim");
    bart->addTween(TweenAnim(animation), 500, -1);
	bart->attachTo(this);*/
    getStage()->addEventListener(KeyEvent::KEY_DOWN, CLOSURE(this, &Game::keylistener));

}

void colision()
{
    for (int i = 0; i < boxes.size(); i++)
    {
        spSprite box = boxes[i].icon;
        spSprite bartsprite = b->icon;
        double ax1 = box->getX();
        double ax2 = box->getX() + box->getWidth()*box->getScaleX();
        double ay1 = box->getY();
        double ay2 = box->getY() + box->getHeight()*box->getScaleY();
        
        double x1 = bartsprite->getX();
        double x2 = bartsprite->getX() + bartsprite->getWidth()*bartsprite->getScaleX();
        double y1 = bartsprite->getY();
        double y2 = bartsprite->getY() + bartsprite->getHeight()*bartsprite->getScaleY();
        if (((x1 > ax1 && x1 < ax2)
            || (x2 > ax1 && x2 < ax2))
            && ((y1 > ay1 && y1 < ay2)
                || (y2 > ay1 && y2 < ay2)))
        {
            hit++;
        }
    }
}
void Game::phisic ()
{
        //log::messageln("DOWN /n DOWN");

    if (b->icon->getY() + b->icon->getHeight()/2  < pump->getY() )
    {
        
        b->speed.y += 0.9832;
    }else{
        b->icon->setY(pump->getY() - b->icon->getHeight()/2 );
        if (b->speed.y >= 0)
        {
            b->step = 0;
            b->speed.y = 0;
        }
    }
    textfield->setText("speed x : " + std::to_string( b->speed.x)
                      + "\nspeed y :" +std::to_string( b->speed.y)
                       + "\nX loc :" +std::to_string( b->icon->getX())
                       + "\nspeed y :" +std::to_string( b->icon->getY())
                      + "\nstep :" +std::to_string( b->step)
                       + "\n Status :" +std::to_string( hit)
                       );

    double nextY = b->icon->getY() + b->speed.y;
    //b->icon->setX(nextX);
    b->icon->setY(nextY);
    for (int i = 0; i < boxes.size(); i++)
    {
        Box box =boxes[i];
        box.icon->setX(box.icon->getX() - + b->speed.x);
    }
    colision();
    
}

void Game::keylistener(Event *event)
{
    KeyEvent* e = (KeyEvent*)event;
    
    switch(e->data->keysym.sym)
    {
        case SDLK_DOWN:
            
            
            break;
        case SDLK_UP:
        {
            if (b->step < 3)
            {
                b->speed.y -= 9.832;
                b->icon->setY(b->icon->getY() );
                b->step++;
            }
            
            //b->speed.x += 1.0;
            /*spTweenQueue tweenQueue = new TweenQueue();
            tweenQueue->setDelay(100);
            tweenQueue->add(Sprite::TweenPosition( b->icon->getX()+ b->icon->getWidth()*2, b->icon->getY() - b->icon->getWidth()*3), 500, 1);
            tweenQueue->add(Sprite::TweenPosition( b->icon->getX(), b->icon->getY()), 500, 1);
            b->icon->addTween(tweenQueue);*/
            break;
        }
        case SDLK_RIGHT:
            b->speed.x += 0.8;
            break;
        case SDLK_LEFT:
        {
            if (b->speed.x > 0)
            {
                b->speed.x -= 0.5;
            }
                break;
        }
        case SDLK_SPACE:
        {
            b->speed.x -= 2.8;
            break;
        }
            
        default:
            return;
    }

       //b->icon->setPosition(eX, eY);
    //newGameButton->setX(newGameButton->getX() + eX);
    //newGameButton->setY(newGameButton->getY() + eY);
}
Game::~Game()
{
    
}
