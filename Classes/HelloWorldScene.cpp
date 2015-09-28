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

	auto menu = Menu::create(MenuItemImage::create("StartWhenEased.png", "StartWhenTouched.png", [](Object* obj){
		auto scene1 = game::createScene();//�������л��ĳ���
		auto transition = TransitionFade::create(0.2f, scene1);//��������װ������Ч  
		Director::getInstance()->replaceScene(transition);//���õ������������л�����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //ֹͣ��������
	}), NULL);
	menu->setPosition(ccp(size.width / 4, size.height / 2));
	addChild(menu, 1);  //��ʼ��ť



	auto menu1 = Menu::create(MenuItemImage::create("LoadWhenEased.png", "LoadWhenTouched.png", [](Object* obj){
		sGlobal->load = 1;
		auto scene1 = GameScene::createScene();//�������л��ĳ���
		
		auto transition = TransitionFade::create(0.2f, scene1);//��������װ������Ч  
		Director::getInstance()->replaceScene(transition);//���õ������������л�����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //ֹͣ��������
	
	}), NULL);
	menu1->setPosition(ccp(size.width / 4, size.height / 3));
	addChild(menu1, 1);   //���밴ť



	auto closeItem = Menu::create(MenuItemImage::create("ExitWhenEased.png", "ExitWhenTouched.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this)), NULL);

	closeItem->setPosition(ccp(size.width / 4, size.height / 6));

	this->addChild(closeItem, 1);// �������˳���ť

	auto menu3 = Menu::create(MenuItemImage::create("EndWhenEased1.png", "EndWhenTouched1.png", [](Object* obj){
		auto scene2 = PreviewCG::createScene();//�������л��ĳ���
		auto transition = TransitionFade::create(0.2f, scene2);//��������װ������Ч  
		Director::getInstance()->replaceScene(transition);//���õ������������л�����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //ֹͣ��������
	}), NULL);
	menu3->setPosition(ccp(size.width / 4, size.height / 15));
	addChild(menu3, 1);  //��ʼ��ť


	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundBGM.mp3", true);//����bgm

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
