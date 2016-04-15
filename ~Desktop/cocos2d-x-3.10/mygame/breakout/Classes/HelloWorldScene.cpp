#include "HelloWorldScene.h"



USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _player = Sprite::create("player.png");
    _player->setPosition(Vec2(visibleSize.width/2, _player->getContentSize().height/2));
    
    this->addChild(_player);
    
    //BLOCKS
    for(int i=0; i<8; i++)
    {
        auto temp= Sprite::create("plataforma.png");
        temp->setPosition(Vec2(72+110*i+temp->getContentSize().width/2,visibleSize.height/2));
        this->addChild(temp);
        _blocks.pushBack(temp);
        
    
    }
    _ball = Sprite::create("ball.png");
    _ball->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    
    auto ballBody = PhysicsBody::createCircle(15,PhysicsMaterial(0.1,1.0,0.0));
    ballBody->setDynamic(true);
    _ball->addComponent(ballBody);
    this->addChild(_ball);

    // TEXTO DEBUG
    
    std::stringstream mStr;
    mStr << visibleSize.width << "x"<< visibleSize.height;
    auto label = Label::createWithTTF(mStr.str(), "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    
    // position the sprite on the center of the screen
    
    
    // creating a keyboard event listener
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->scheduleUpdate();

    return true;
}
// Implementation of the keyboard event callback function prototype

void HelloWorld::update(float td)
{
    if(leftPressed)
    {
        _player->setPositionX(_player->getPositionX()-10);
    }
    if(rightPressed)
    {
        _player->setPositionX(_player->getPositionX()+10);
    }

    if(spacePressed)
    {
        _player->setPositionX(_player->getPositionY()+10);
    }

}
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if(EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode)
    {
        leftPressed = true;
    }
    else if(EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode)
    {
        rightPressed = true;
    }else if(EventKeyboard::KeyCode::KEY_SPACE == keyCode)
    {
        spacePressed = true;
        
    }
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    if(leftPressed)
    {
        leftPressed = false;
    }
    if(rightPressed)
    {
        rightPressed = false;
    }
    
    if(spacePressed)
    {
        spacePressed = false;
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
