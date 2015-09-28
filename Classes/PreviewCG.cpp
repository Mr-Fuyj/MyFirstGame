#include "SimpleAudioEngine.h"
#include "gamescene.h"
#include "PreviewCG.h"
#include "EndOfLeave.h"
#include "EndOfStay.h"
#include "EndOfStay_another.h"

USING_NS_CC;

Scene* PreviewCG::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PreviewCG::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PreviewCG::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	Sprite *backGround = Sprite::create("BG.jpg");
	Size size = Director::sharedDirector()->getWinSize();
	float scalX = size.width / backGround->getContentSize().width;///����x�᷽�������ϵ��
	float scalY = size.height / backGround->getContentSize().height;//����y�᷽�������ϵ��
	backGround->setScaleX(scalX);
	backGround->setScaleY(scalY);
	backGround->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(backGround, 0, 0);//�˵�����

	/*Sprite *spritetitle = Sprite::create("title.png");
	Size s = spritetitle->getContentSize();
	spritetitle->setPosition(ccp(size.width / 2, size.height - s.height / 2));
	addChild(spritetitle, 1);*/
	//����
	
	auto menu = Menu::create(MenuItemImage::create("TrueEndWhenEased.png", "TrueEndWhenTouched.png", [](Object* obj){
		auto scene1 = EndOfStayanother::createScene();//�������л��ĳ���
		auto transition = TransitionFade::create(0.2f, scene1);//��������װ������Ч  
		Director::getInstance()->replaceScene(transition);//���õ������������л�����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //ֹͣ��������
	}), NULL);
	menu->setPosition(ccp(size.width / 4, size.height /2));
	addChild(menu, 1);  //��ʼ��ť

	auto menu2 = Menu::create(MenuItemImage::create("GoodEndWhenEased.png", "GoodEndWhenTouched.png", [](Object* obj){
		auto scene2 = EndOfLeave::createScene();//�������л��ĳ���
		auto transition = TransitionFade::create(0.2f, scene2);//��������װ������Ч  
		Director::getInstance()->replaceScene(transition);//���õ������������л�����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //ֹͣ��������
	}), NULL);
	menu2->setPosition(ccp(size.width / 4, size.height /3));
	addChild(menu2, 1);  //��ʼ��ť

	auto menu3 = Menu::create(MenuItemImage::create("AnotherEndWhenEased.png", "AnotherEndWhenTouched.png", [](Object* obj){
		auto scene3 = EndOfStay::createScene();//�������л��ĳ���
		auto transition = TransitionFade::create(0.2f, scene3);//��������װ������Ч  
		Director::getInstance()->replaceScene(transition);//���õ������������л�����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //ֹͣ��������
	}), NULL);
	menu3->setPosition(ccp(size.width / 4, size.height /6));
	addChild(menu3, 1);  //��ʼ��ť



	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundBGM.mp3", true);//����bgm

    return true;
}


void PreviewCG::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
