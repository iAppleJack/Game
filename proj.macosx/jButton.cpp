//
//  jButton.cpp
//  Game_macosx
//
//  Created by iAppleJack on 02/04/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "jButton.h"

jButton::jButton(double x, double y, std::string ttext, EventCallback _cb)
{
    
    //setup it:
    //set button.png image. Resource 'button' defined in 'res.xml'
    button->setResAnim(res::ui.getResAnim("button"));
    
    //centered button at screen
    Vector2 pos = getStage()->getSize()/2 - button->getSize()/2;
    button->setPosition(pos);
    
    //handle click to button
    EventCallback cb = _cb;
    button->addEventListener(TouchEvent::CLICK, cb);
    

   // addChild(button);
    
    
    

    text->attachTo(button);
    text->setPosition(button->getSize()/2);
    
    //initialize text style
    TextStyle style;
    style.font = res::ui.getResFont("main")->getFont();
    style.color = Color::White;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_CENTER;
    
    text->setStyle(style);
    text->setText(ttext);
}



void jButton::right(Event *event)
{
    //user clicked to button
    
    //animate button by chaning color
    button->setColor(Color::White);
    button->addTween(Sprite::TweenColor(Color::Blue), 500, 1, true);
    
    //animate text by scaling
    text->setScale(1.0f);
    text->addTween(Actor::TweenScale(1.1f), 500, 1, true);
    
    //and change text
    
    
    
    //lets create and run sprite with simple animation
    
}
