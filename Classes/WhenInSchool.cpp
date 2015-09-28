#include "WhenInTaxi.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "WhenInSchool.h"
#include "GameScene.h"

Scene* WhenInSchool::createScene() {
	auto scene = Scene::create();

	auto layer = WhenInSchool::create();

	scene->addChild(layer);

	return scene;
}

bool WhenInSchool::init() {

	Sprite *backGround = Sprite::create("Classroom.jpg");
	Size size = Director::sharedDirector()->getWinSize();
	float scalX = size.width / backGround->getContentSize().width;///设置x轴方向的缩放系数
	float scalY = size.height / backGround->getContentSize().height;//设置y轴方向的缩放系数
	backGround->setScaleX(scalX);
	backGround->setScaleY(scalY);
	backGround->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(backGround, 0, 0);//菜单背景


	Size s = Director::getInstance()->getVisibleSize(); //获取屏幕大小

	__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
	__String* a = (__String*)string->objectForKey("24");
	const char* b = a->getCString();
	Label* label1 = Label::createWithSystemFont(b, "Arial", 30);//第一句旁白的层
	label1->setAnchorPoint(Point(1,1));
			label1->setPosition(Point(s.width,s.height));
	label1->setOpacity(0);
	this->addChild(label1,2,1);
	auto action1 = FadeIn::create(1.0f);
	label1->runAction(action1);

	auto ListenerForDialogue1 = EventListenerTouchOneByOne::create();

	static int count = 1;
	ListenerForDialogue1->onTouchBegan = [&](Touch* touch,Event* event){
		auto target = static_cast<Label*>(event->getCurrentTarget());
		if (count == 1){
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("25");
			const char* b = a->getCString();
			Label* label2 = Label::createWithSystemFont(b, "Arial", 30);//第2句旁白的层
			label2->setAnchorPoint(Point(1,1));
			label2->setPosition(Point(s.width,s.height));
			label2->setOpacity(0);
			this->addChild(label2,3,1);
			auto action2 = FadeIn::create(1.0f);
			label2->runAction(action2);
			count = count+1;}


		else if(count == 2)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("26");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//第3句旁白的层
			label3->setAnchorPoint(Point(1,1));
			label3->setPosition(Point(s.width,s.height));
			label3->setOpacity(0);
			this->addChild(label3,3,1);
			auto action2 = FadeIn::create(1.0f);
			label3->runAction(action2);
			count = count+1;
		}

		else if(count == 3)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("27");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//第3句旁白的层
			label3->setAnchorPoint(Point(1,1));
			label3->setPosition(Point(s.width,s.height));
			label3->setOpacity(0);
			this->addChild(label3,3,1);
			auto action2 = FadeIn::create(1.0f);
			label3->runAction(action2);
			count = count+1;
		}

		else if(count == 4)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("28");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//第3句旁白的层
			label3->setAnchorPoint(Point(1,1));
			label3->setPosition(Point(s.width,s.height));
			label3->setOpacity(0);
			this->addChild(label3,3,1);
			auto action2 = FadeIn::create(1.0f);
			label3->runAction(action2);
			count = count+1;
			auto menu = Menu::create(MenuItemImage::create("jixuWhenEased.png", "jixuWhenTouched.png", [](Object* obj){
				auto scene1 = GameScene::createScene();//创建待切换的场景
				auto transition = TransitionFade::create(0.2f, scene1);//给场景包装动画特效  
				Director::getInstance()->replaceScene(transition);//运用导演类来进行切换场景
				CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("WhenInSchool.mp3");
				count = 1;
			}), NULL);
			menu->setPosition(ccp(s.width / 9 * 8, s.height / 10));
			addChild(menu, 1);  //开始按钮

			
		}
		
		

		return true;

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenerForDialogue1,this);


	return true;
}