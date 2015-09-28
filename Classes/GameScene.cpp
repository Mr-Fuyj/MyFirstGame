#include "GameScene.h"
#include"AnimationUtil.h"
#include"Hero.h"
#include"MoveController.h"
#include"Global.h"
#include"ControllerLayer.h"
#include"TalkLayer.h"
#include"MyMap.h"
#include"MenuLayer.h"
#include "SimpleAudioEngine.h"
//创建一个场景，并且将一个GameScene层加入场景中
Scene* GameScene::createScene(){
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer,3,"GameLayer");
	sGlobal->gameScene =layer;

	return scene;
}

bool GameScene::init(){
	if (!Layer::init()){ 
		return false; 
	}

	

	//此处测试MyMap地图
	sGlobal->mapNum = 0;
	sGlobal->caseNum = 0;
	MyMap* myMap = MyMap::create();
	sGlobal->map = myMap->m_map;
	sGlobal->myMap = myMap;
	this->addChild(myMap,5,sGlobal->mapNum);
	this->addChild(myMap->m_map,6,"map");

	////加载Tiled地图，添加到层中
	////地图是层的child
	//TMXTiledMap*map = TMXTiledMap::create("scene12test.tmx");
	///*map->setAnchorPoint(Point(0, 0));*/
	///*map->setPosition(Point(0,0));*/
	//this->addChild(map,5,"map");
	//sGlobal->map = map;

	ControllerLayer*controllerLayer = ControllerLayer::create();
	this->addChild(controllerLayer,20);

	//测试Hero类，包括对其的添加和动画的正常运行
	addHero(myMap->m_map,Point(100,100));


	log("这是斜杠n/n,而这是反斜杠n\nhehe");


	//此处正式测试菜单
	//创建精灵便于getContentSize()函数调用
	auto  menuLogo = Sprite::create("MenuWhenTouched.png");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto menuLogoBag = Menu::create(MenuItemImage::create("MenuWhenEased.png", "MenuWhenTouched.png", [&](Object* obj){

		//此处切换成菜单层
		auto menuLayer = MenuLayer::create();//创建菜单层
		this->getParent()->addChild(menuLayer, 10, "tag");//把菜单层添加到游戏场景中
	}), NULL);
	menuLogoBag->setGlobalZOrder(128);

	//设置位置锚点并添加
	menuLogoBag->setAnchorPoint(Point(0, 0));
	menuLogoBag->setPosition(Point(menuLogo->getContentSize().width / 2, (visibleSize.height) - (menuLogo->getContentSize().height / 2 + 10)));
	this->addChild(menuLogoBag, 6);
	
	///*此处测试对话
	//TalkLayer* talkLayer = TalkLayer::create();
	//this->addChild(talkLayer,60);*/
	
	////此处测试菜单窗口
	//MenuLayer*menuLayer = MenuLayer::create();
	//this->addChild(menuLayer, 200);
	
	////此处测试动画
	//Sprite*runSp = Sprite::createWithSpriteFrame(SpriteFrame::create("Hero_Down_0.png", Rect(0, 0, 32, 32)));
	//runSp->setPosition(Point(300, 500));
	//this->addChild(runSp,7);
	////加载图片帧到缓存池
	//SpriteFrameCache*frameCache = SpriteFrameCache::getInstance();
	//frameCache->addSpriteFramesWithFile("Hero.plist", "Hero.png");
	////用 AnimationUtil类创建动画
	//Animation*animation = AnimationUtil::createWithSingleFrameNameSmall("Hero", "Up", 0.1f, -1);
	//runSp->runAction(Animate::create(animation));
		
	//auto menu1 = Menu::create(MenuItemImage::create("LoadWhenEased.png", "LoadWhenTouched.png", [&](Object* obj){
	//	//此处测试切换成菜单层
	//	/*auto layer2 = Layer::create();*/
	//	auto layer2 = Layer::create();
	//	TMXTiledMap*map1 = TMXTiledMap::create("scene13.tmx");
	//	layer2->addChild(map1);
	//	
	//	this->getParent()->addChild(layer2,10,"tag");

	//	//此处测试菜单层的删除
	//	auto menu2 = Menu::create(MenuItemImage::create("LoadWhenEased.png", "LoadWhenTouched.png", [&](Object* obj){

	//		this->getParent()->removeChildByName("tag");
	//	}), NULL);
	//	Size size2 = Director::sharedDirector()->getWinSize();
	//	menu2->setPosition(ccp(size2.width / 4, size2.height / 2));
	//	layer2->addChild(menu2, 6);   //载入按钮

	//}), NULL);
	//Size size = Director::sharedDirector()->getWinSize();
	//menu1->setPosition(ccp(size.width / 4, size.height / 3));
	//this->addChild(menu1, 6);   //载入按钮
	
	/*bool s = sGlobal->load;
	if (sGlobal->load){
		Point loadPosition = Point(CCUserDefault::sharedUserDefault()->getIntegerForKey("heroPositionX"), CCUserDefault::sharedUserDefault()->getIntegerForKey("heroPositionY"));
		int mapNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("mapNum");
		for (int i = 0; i <= 17; i++){
			bool a = CCUserDefault::sharedUserDefault()->getBoolForKey((StringUtils::format("bool_%d", i)).c_str());
			sGlobal->hero->plot[i] = CCUserDefault::sharedUserDefault()->getBoolForKey((StringUtils::format("bool_%d", i)).c_str());
		}
		this->changeMap(loadPosition, mapNum);
		sGlobal->load = 0;
	}*/
	
	return true;
}

void GameScene::addHero(TMXTiledMap*map,Point startPoint){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//创造精灵
	Sprite*heroSprite = Sprite::create("Hero_Down_0.png");
	//将精灵绑在玩家身上
	Hero*mHero = Hero::create();
	mHero->bindSprite(heroSprite);
	/*mHero->run("Left");*/
	mHero->setTiledMap(map);
	//设置玩家坐标
	mHero->setPosition(startPoint);
	//添加玩家为child


	map->addChild(mHero,20,"Hero");
	//创建控制器
	MoveController*moveController = MoveController::create();
	moveController->setSpeedX(0);
	moveController->setSpeedY(0);
	//添加到场景中
	this->addChild(moveController);
	//设置控制器到主角身上
	mHero->setController(moveController);
}

void GameScene::changeMap(Point startPoint,int mapPoint){
	this->removeChildByName("map");
	this->removeChildByTag(sGlobal->mapNum);
	sGlobal->mapNum = mapPoint;
	MyMap* myMap = MyMap::create();
	sGlobal->map = myMap->m_map;
	sGlobal->myMap = myMap;
	myMap->setPosition(Point(100, 100));
	myMap->m_map->setPosition(Point(-100, -100));
	this->addChild(myMap, 5, sGlobal->mapNum);
	this->addChild(myMap->m_map,6,"map");
	/*myMap->setPosition(Point(0, 0));*/
	myMap->m_map->addChild(sGlobal->hero);
	/*sGlobal->map->addChild(sGlobal->hero);*/
	sGlobal->hero->setTiledMap(sGlobal->map);
	sGlobal->hero->setPosition(sGlobal->myMap->positionForTileCoord(startPoint));
	/*this->addHero(sGlobal->map, sGlobal->myMap->positionForTileCoord(startPoint-Point(2,2)));*/
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("WhenInSchool.mp3", true);
}