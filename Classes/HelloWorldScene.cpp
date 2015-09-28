#include "HelloWorldScene.h"
#include "gamescene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include"Global.h"
#include "game.h"
#include "PreviewCG.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

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
	if (!Layer::init())
	{
		return false;
	}

	Sprite *backGround = Sprite::create("BG.jpg");
	Size size = Director::sharedDirector()->getWinSize();
	float scalX = size.width / backGround->getContentSize().width;///设置x轴方向的缩放系数
	float scalY = size.height / backGround->getContentSize().height;//设置y轴方向的缩放系数
	backGround->setScaleX(scalX);
	backGround->setScaleY(scalY);
	backGround->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(backGround, 0, 0);//菜单背景

	/*Sprite *spritetitle = Sprite::create("title.png");
	Size s = spritetitle->getContentSize();
	spritetitle->setPosition(ccp(size.width / 2, size.height - s.height / 2));
	addChild(spritetitle, 1);*/
	//标题

	auto menu = Menu::create(MenuItemImage::create("StartWhenEased.png", "StartWhenTouched.png", [](Object* obj){
		auto scene1 = game::createScene();//创建待切换的场景
		auto transition = TransitionFade::create(0.2f, scene1);//给场景包装动画特效  
		Director::getInstance()->replaceScene(transition);//运用导演类来进行切换场景
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //停止背景音乐
	}), NULL);
	menu->setPosition(ccp(size.width / 4, size.height / 2));
	addChild(menu, 1);  //开始按钮



	auto menu1 = Menu::create(MenuItemImage::create("LoadWhenEased.png", "LoadWhenTouched.png", [](Object* obj){
		sGlobal->load = 1;
		auto scene1 = GameScene::createScene();//创建待切换的场景
		
		auto transition = TransitionFade::create(0.2f, scene1);//给场景包装动画特效  
		Director::getInstance()->replaceScene(transition);//运用导演类来进行切换场景
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //停止背景音乐
	
	}), NULL);
	menu1->setPosition(ccp(size.width / 4, size.height / 3));
	addChild(menu1, 1);   //载入按钮



	auto closeItem = Menu::create(MenuItemImage::create("ExitWhenEased.png", "ExitWhenTouched.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this)), NULL);

	closeItem->setPosition(ccp(size.width / 4, size.height / 6));

	this->addChild(closeItem, 1);// 这里是退出按钮

	auto menu3 = Menu::create(MenuItemImage::create("EndWhenEased1.png", "EndWhenTouched1.png", [](Object* obj){
		auto scene2 = PreviewCG::createScene();//创建待切换的场景
		auto transition = TransitionFade::create(0.2f, scene2);//给场景包装动画特效  
		Director::getInstance()->replaceScene(transition);//运用导演类来进行切换场景
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //停止背景音乐
	}), NULL);
	menu3->setPosition(ccp(size.width / 4, size.height / 15));
	addChild(menu3, 1);  //开始按钮


	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundBGM.mp3", true);//背景bgm

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
