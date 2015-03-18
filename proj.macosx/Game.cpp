#include "Game.h"
#include "res.h"

Game::Game()
{
	
}

spSprite bart;
void Game::init()
{
	//scene layer would have size of display
	setSize(getStage()->getSize());
    
	//create background
    
	spSprite sky = new Sprite;
	sky->setResAnim(res::ui.getResAnim("sky"));
	sky->attachTo(this);
    
     bart = new Sprite;
	//bart->setResAnim(res::ui.getResAnim("anim"));
    ResAnim *animation = res::ui.getResAnim("anim");
    bart->addTween(TweenAnim(animation), 500, -1);
	bart->attachTo(this);
    getStage()->addEventListener(KeyEvent::KEY_DOWN, CLOSURE(this, &Game::keylistener));
      

}

void Game::keylistener(Event *event)
{
    KeyEvent* e = (KeyEvent*)event;
    double eX = 0.0;
    double eY = 0.0;
    switch(e->data->keysym.sym)
    {
        case SDLK_DOWN:
            eY = bart->getScaleY()*bart->getHeight();
            
            break;
        case SDLK_UP:
            eY = -bart->getScaleY()*bart->getHeight();
            break;
        case SDLK_RIGHT:
            eX = bart->getScaleX()*bart->getWidth();
            break;
        case SDLK_LEFT:
            eX = -bart->getScaleX()*bart->getWidth();
            break;
        default:
            return;
    }
    
    spTweenQueue tweenQueue = new TweenQueue();
    tweenQueue->setDelay(1);
    //first, move sprite to dest position
    
    tweenQueue->add(Sprite::TweenPosition(bart->getX() + eX,bart->getY() + eY), 500, 1);
    //then fade it out smoothly
    //tweenQueue->add(Sprite::TweenAlpha(0), 500, 1);
    
    bart->addTween(tweenQueue);
    
    //newGameButton->setX(newGameButton->getX() + eX);
    //newGameButton->setY(newGameButton->getY() + eY);
}
Game::~Game()
{
    
}
