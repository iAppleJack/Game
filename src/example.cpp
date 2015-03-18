#include "oxygine-framework.h"
#include <functional>

using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. 
//It is important on mobile devices with limited memory and you would load/unload them

/*
 
 */
Resources gameResources;


class MainActor: public Actor
{
private:
    spSprite newGameButton;
public:
	spTextField _text;
	spSprite	_button;
    double eX = 0.0;
    double eY = 0.0;
    double arc;

	MainActor()
	{
       
        newGameButton = new Sprite();
        newGameButton->setResAnim(gameResources.getResAnim("anim"));
        ResAnim *animation = gameResources.getResAnim("anim");
        newGameButton->addTween(TweenAnim(animation), 500, -1);
        newGameButton->setScale(2, 2);
        getStage()->addEventListener(KeyEvent::KEY_DOWN, CLOSURE(this, &MainActor::keylistener));
        

        addChild(newGameButton);
		//create simple Sprite
        
		
	}

    void keylistener(Event *event)
    {
        KeyEvent* e = (KeyEvent*)event;
        
        switch(e->data->keysym.sym)
        {
            case SDLK_DOWN:
                eY =eY + newGameButton->getScaleY()*newGameButton->getHeight();
                break;
            case SDLK_UP:
                eY =eY  -newGameButton->getScaleY()*newGameButton->getHeight();
                break;
            case SDLK_RIGHT:
                eX =eX + newGameButton->getScaleX()*newGameButton->getWidth();
                break;
            case SDLK_LEFT:
                eX = eX -newGameButton->getScaleX()*newGameButton->getWidth();
                break;
            case SDLK_SPACE:
                arc += 0.1;
                newGameButton->setRotation(arc);
                break;
                default:
                return;
        }
        
        spTweenQueue tweenQueue = new TweenQueue();
		tweenQueue->setDelay(1);
		//first, move sprite to dest position
        
		tweenQueue->add(Sprite::TweenPosition( eX, eY), 500, 1);
		//then fade it out smoothly
		//tweenQueue->add(Sprite::TweenAlpha(0), 500, 1);
		
		newGameButton->addTween(tweenQueue);
       // tweenQueue->setDetachActor(true);

        
        //newGameButton->setX(newGameButton->getX() + eX);
        //newGameButton->setY(newGameButton->getY() + eY);
    }
    
	

};
//declare spMainActor as intrusive_ptr holder of MainActor
typedef oxygine::intrusive_ptr<MainActor> spMainActor;

void example_preinit(){}

//called from entry_point.cpp
void example_init()
{
	gameResources.loadXML("res.xml");
		

	
	spMainActor actor = new MainActor;

	getStage()->addChild(actor);
    
}


//called each frame from entry_point.cpp	
void example_update()
{	
}

//called each frame from entry_point.cpp	
void example_destroy()
{
	//free previously loaded resources
	gameResources.free();
}
