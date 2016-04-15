#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <iostream>
#include <sstream>

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    
    
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    
    void update(float dt) override;
    
private:
    Sprite* _player;
    Vector<Sprite*> _blocks;
    Sprite* _ball;
    bool leftPressed;
    bool spacePressed;
    bool rightPressed;
};

#endif // __HELLOWORLD_SCENE_H__
