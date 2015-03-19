#include "Game.h"
#include "res.h"
#include "Bart.h"
#include "Box.h"
#include "Background.h"
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
Background *background;
void Game::init()
{
	//scene layer would have size of display
    
    boxes.push_back(*new Box(25,25,1000,520));
    boxes.push_back(*new Box(25,25,1100,520));
    boxes.push_back(*new Box(25,25,1700,520));
    boxes.push_back(*new Box(25,25,4000,520));
    boxes.push_back(*new Box(25,25,5000,520));
    boxes.push_back(*new Box(25,25,5000,420));
    boxes.push_back(*new Box(25,25,6500,520));
    boxes.push_back(*new Box(25,25,6500,420));
    boxes.push_back(*new Box(25,25,6550,320));
    
    

	setSize(getStage()->getSize());
    background = new Background(getStage()->getWidth(), getStage()->getHeight());
    
    
    background->icon3->attachTo(this);
    background->icon4->attachTo(this);
    background->icon1->attachTo(this);
    
    background->icon2->attachTo(this);

    /*spSprite sky2 = new Sprite;
	sky2->setResAnim(res::ui.getResAnim("background2"));
    double width = getStage()->getWidth()/sky2->getWidth();
    double heigth = getStage()->getHeight()/sky2->getHeight();
    sky2->setScale(width, heigth);
	sky2->attachTo(this);
    
    
    
    spSprite sky = new Sprite;
	sky->setResAnim(res::ui.getResAnim("background1"));
    width = getStage()->getWidth()/sky->getWidth();
    heigth = getStage()->getHeight()/sky->getHeight();
    sky->setScale(width, heigth);
	sky->attachTo(this);*/
    

    
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
    background->moveTo(-b->speed.x);
    for (int i = 0; i < boxes.size(); i++)
    {
        Box tempbox =boxes[i];
        tempbox.icon->setX(tempbox.icon->getX() - + b->speed.x);
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
