#include "MenuLayer.h"
#include "gamescene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Hero.h"
#include "AppDelegate.h"
#include"Global.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio::timeline;

//Scene* MenuLayer::createScene()
//{
//	auto scene = Scene::create();
//
//	auto layer = MenuLayer::create();
//
//	scene->addChild(layer);
//
//	return scene;
//}

bool MenuLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//添加背景地图

	Sprite *backGround = Sprite::create("Backround.png");
	float scalX = visibleSize.width / backGround->getContentSize().width;///设置x轴方向的缩放系数
	float scalY = visibleSize.height / backGround->getContentSize().height;//设置y轴方向的缩放系数
	backGround->setScaleX(scalX);
	backGround->setScaleY(scalY);
	backGround->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(backGround, 0, 0);//菜单背景

	//返回标题按钮
	auto menuLayerOn = Menu::create(MenuItemImage::create("TitleWhenEased.png", "TitleWhenTouched.png", [&](Object* obj){
		auto sceneBack = HelloWorld::createScene();
		auto transitionSceneBack = TransitionFade::create(0.2f, sceneBack);
		Director::getInstance()->replaceScene(sceneBack);//运用导演类来进行切换场景
	}), NULL);

	auto spBack = Sprite::create("TitleWhenEased.png");
	menuLayerOn->setAnchorPoint(Point(0, 0));
	menuLayerOn->setPosition(Point(spBack->getContentSize().width/2, visibleSize.height -spBack->getContentSize().height));
	this->addChild(menuLayerOn, 8);

	//存档按钮
	auto menuLayerSave = Menu::create(MenuItemImage::create("SaveWhenEased.png", "SaveWhenTouched.png", [&](Object* obj){
		for (int i = 0; i <= 17; i++){
			CCUserDefault::sharedUserDefault()->setBoolForKey((StringUtils::format("bool_%d",i)).c_str() , sGlobal->hero->plot[i]);
		}
		sGlobal->loadMapNum = sGlobal->mapNum;
			CCUserDefault::sharedUserDefault()->setIntegerForKey("mapNum", sGlobal->loadMapNum);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("heroPositionX", sGlobal->hero->getPosition().x);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("heroPositionY", sGlobal->hero->getPosition().y);
	}), NULL);

	auto spSave = Sprite::create("SaveWhenEased.png");
	menuLayerSave->setAnchorPoint(Point(0, 0));
	menuLayerSave->setPosition(Point(spSave->getContentSize().width/2, visibleSize.height - spSave->getContentSize().height-60));
	this->addChild(menuLayerSave, 8);

	//继续游戏按钮
	auto menuLayerout = Menu::create(MenuItemImage::create("ContinueWhenEased.png", "ContinueWhenTouched.png", [&](Object* obj){
	this->getParent()->removeChildByName("tag");
	}), NULL);

	auto spOn = Sprite::create("ContinueWhenEased.png");
	menuLayerout->setAnchorPoint(Point(0, 0));
	menuLayerout->setPosition(Point(spOn->getContentSize().width/2, visibleSize.height - spOn->getContentSize().height - 120));
	this->addChild(menuLayerout, 8);
	this->itemNum = 100;


	//获得物品按钮
	auto menuLayerItem= Menu::create(MenuItemImage::create("itemWhenEased.png", "itemWhenTouched.png", [&](Object* obj){
		
		//创建物品大图精灵并添加
		/*int itemNum = 100;*/
		auto itemMain1 = Sprite::create("thing_100.png");
		auto spItem = Sprite::create("SaveWhenEased.png");
		this->addChild(itemMain1, 500,100);
		itemMain1->setGlobalZOrder(1000);
		//设置一些设置位置要用的数据
		this-> spItemWidth = spItem->getContentSize().width;
		this-> spItemHeight = spItem->getContentSize().height;
		this-> itemMainWidth = itemMain1->getContentSize().width;
		this-> itemMainHight = itemMain1->getContentSize().height;

		//设置物品大图图片位置
		itemMain1->setAnchorPoint(Point(0, 0));
		itemMain1->setPosition(Point(spItemWidth +10, visibleSize.height ));

		//第二个大图
		auto itemMain2 = Sprite::create("thing_200.png");
		this->addChild(itemMain2, 500, 200);
		itemMain2->setAnchorPoint(Point(0, 0));
		itemMain2->setPosition(Point(spItemWidth + 10, visibleSize.height));
		itemMain2->setOpacity(0);
		itemMain2->setGlobalZOrder(1000);

		//第三个大图
		auto itemMain3 = Sprite::create("thing_300.png");
		this->addChild(itemMain3, 500, 300);
		itemMain3->setAnchorPoint(Point(0, 0));
		itemMain3->setPosition(Point(spItemWidth + 10, visibleSize.height));
		itemMain3->setOpacity(0);
		itemMain3->setGlobalZOrder(1000);

		//第四个大图
		auto itemMain4 = Sprite::create("thing_400.png");
		this->addChild(itemMain4, 500,400);
		itemMain4->setAnchorPoint(Point(0, 0));
		itemMain4->setPosition(Point(spItemWidth + 10, visibleSize.height));
		itemMain4->setOpacity(0);
		itemMain4->setGlobalZOrder(1000);
		







	//	//创建物品大图精灵并添加
	//	/*int itemNum = 200;*/
	//	auto itemMain2 = Sprite::create("thing_200.png");
	///*	auto spItem = Sprite::create("SaveWhenEased.png");*/
	//	this->addChild(itemMain2, 50, 100);
	//	//设置一些设置位置要用的数据
	//	/*float spItemWidth = spItem->getContentSize().width;
	//	float spItemHeight = spItem->getContentSize().height;*/
	//	float itemMainWidth2 = itemMain2->getContentSize().width;
	//	float itemMainHight2 = itemMain2->getContentSize().height;

	//	//设置物品大图图片位置
	//	itemMain2->setAnchorPoint(Point(0, 0));
	//	itemMain2->setPosition(Point(spItemWidth + 10, visibleSize.height));
	//	itemMain2->setOpacity(0);

		//给物品大图绑定触摸事件
		auto listener = EventListenerTouchOneByOne::create();

		//触摸开始

		//窃以为因为此处要对itemNum变量进行修改
		//所以应该用&引用模式而非=赋值模式
		listener->onTouchBegan = [&](Touch* touch, Event* event) {

			Point pos1 = touch->getLocationInView();//获取2D坐标
			Point pos2 = Director::getInstance()->convertToGL(pos1);//转换为Cocos2d-x坐标
			this-> pos2x = pos2.x;
			this-> pos2y = pos2.y;

			auto target = static_cast<Sprite*>(event->getCurrentTarget());
			
			//窃以为由于这是个每次点击都会被循环的动作
			//所以这个标定值应该是一个init函数的变量
			//而不应该是一个触摸事件的变量
			/*int itemNum = 100;*/

			
			//窃以为用透明度的的方法的话这里要把原来的精灵透明度设为0
			//而不是直接删除
			/*removeChildByTag(itemNum);*/
			Sprite*sprite1 = (Sprite*)(this->getChildByTag(itemNum));
			sprite1->setOpacity(0);
			//窃以为这里缺少一个接收upOrDown函数返回值的变量
			/*upOrDown();*/
			
			itemNum=upOrDown();
			Sprite*sprite2 = (Sprite*)(this->getChildByTag(itemNum));
			sprite2 =(Sprite*) (this->getChildByTag(itemNum));
			sprite2->setOpacity(255);

			
			//auto itemMain = Sprite::create(StringUtils::format("thing_%d.png", itemNum));
			//this->addChild(itemMain, 50, itemNum);
			////设置一些设置位置要用的数据
			//float spItemWidth = spItem->getContentSize().width;
			//float spItemHeight = spItem->getContentSize().height;
			//float itemMainWidth = itemMain->getContentSize().width;
			//float itemMainHight = itemMain->getContentSize().height;

			////设置物品大图图片位置
			//itemMain->setAnchorPoint(Point(0, 0));
			//itemMain->setPosition(Point(spItemWidth + 10, visibleSize.height));


		/*	itemMain->setOpacity(255);*/
			return true;
		};
		
		//触摸进行
		//listener->onTouchMoved = [=](Touch* touch, Event* event) {
		//	//窃以为没有运行的必要
		//	/*auto target = static_cast<Sprite*>(event->getCurrentTarget());*/

		//};


		//触摸结束
		//listener->onTouchEnded = [=](Touch* touch, Event* event) {
		//	//理由同上
		//	/*auto target = static_cast<Sprite*>(event->getCurrentTarget());*/

		///*	auto test = Sprite::create("itemButterflyMini.png");
		//	test->setAnchorPoint(Point(0, 0));
		//	test->setPosition(Point(100,100));
		//	addChild(test, 51);*/
		//};

		listener->setSwallowTouches(true);
		//添加监听事件
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, Mne);
		//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), itemMain2);
		//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), itemMain3);
		//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), itemMain4);
	}), NULL);
	
	//获得物品按钮的位置
	auto spItem = Sprite::create("ItemWhenEased.png");
	menuLayerItem->setAnchorPoint(Point(0, 0));
	menuLayerItem->setPosition(Point(spItem->getContentSize().width / 2, visibleSize.height - spItem->getContentSize().height - 180));
	this->addChild(menuLayerItem, 8);

	return true;
}
//upOrDown函数的实现
int MenuLayer::upOrDown() {
	//窃以为判断机制有问题
	if (/*(spItemWidth < pos2x)||*/(pos2x > (spItemWidth + itemMainWidth / 2)))
	{
		if (itemNum == 400)
			return itemNum;
		else
			//在更改了参数之后要记得将相关区域同时更改
			return (itemNum+=100);
	}
	else if (((spItemWidth + itemMainWidth / 2) > pos2x)/*||(pos2x < (spItemWidth + itemMainWidth)*/)
	{
		if (itemNum == 100)
				return itemNum;
		else
			return (itemNum-=100);
	}
}
//Point pos1 = touch->getLocationInView();//获取2D坐标
//Point pos2 = Director::getInstance()->convertToGL(pos1);//转换为Cocos2d-x坐标
//float pos2x = pos2.x;
//float pos2y = pos2.y;

////替换前一张物品大图并添加后一张物品大图
////创建物品大图精灵并添加
///*int itemNum = 200;
//auto itemMainS = Sprite::create(StringUtils::format("thing_%d.png", itemNum));*/

//int itemNum = 200;
//auto itemMainS = Sprite::create("thing_200.png");

//
////设置物品大图图片位置
//itemMainS->setAnchorPoint(Point(0, 0));
///*itemMainS->setPosition(Point(spItemWidth + 10, visibleSize.height));*/
//itemMainS->setPosition(Point(100,100));
//addChild(itemMain, 60,itemNum);
/*upOrDown();
auto itemMain = Sprite::create(StringUtils::format("thing_%d.png", itemNum));
itemMain->setAnchorPoint(Point(0, 0));
itemMain->setPosition(Point(spItemWidth + 10, visibleSize.height));
this->addChild(itemMain, 50, itemNum);*/
