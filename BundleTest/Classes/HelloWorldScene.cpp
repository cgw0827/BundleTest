#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "DataInputStream.h"
#include "Define.h"
#include "CCBundle.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCBundle* bundle=CCBundle::mainBundle();
//    bundle->localizedStringForKey(key,comment,tbl);
//    CCString *str = CCLocalizedStringFromTable("0", "FarmEventTalkWord", nil);
    if(bundle){
//          CCLog("-（（））））））））））））（）（）（");
         CCString* temp=CCString::create("142");
    CCString  *str= bundle->localizedForKey(temp->m_sString,"","FarmEventTalkWord");
//         str = CCLocalizedStringFromTable(temp->m_sString, "FarmEventTalkWord", "");
        CCLog("--------------------------------------- %s ",str->getCString());

    }
    
      /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
//    CCDate*date;
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    struct cocos2d::cc_timeval now;  // 秒，毫秒
    cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL);
    struct tm * tm;
    tm = localtime(&now.tv_sec);
    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;
    int second = tm->tm_sec;
    
    CCLog("年%d,月%d,日%d, %d点%d分%d秒", year, month, day, hour, minute, second);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
