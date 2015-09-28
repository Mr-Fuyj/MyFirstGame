#include "game.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "WhenNotGoToDream.h"

Scene* game::createScene() {
	auto scene = Scene::create();

	auto layer = game::create();

	scene->addChild(layer);

	return scene;
}

bool game::init() {

	Size s = Director::getInstance()->getVisibleSize(); //获取屏幕大小

	__Dictionary* string = __Dictionary::createWithContentsOfFile("StartGameWord.xml");
	__String* a = (__String*)string->objectForKey("1");
	const char* b = a->getCString();
	Label* label1 = Label::createWithSystemFont(b, "Marker Felt", 30);//第一句旁白的层
	label1->setPosition(Point(s.width/2,s.height/2));
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
		__Dictionary* string = __Dictionary::createWithContentsOfFile("StartGameWord.xml");
		__String* a = (__String*)string->objectForKey("2");
		const char* b = a->getCString();
		Label* label2 = Label::createWithSystemFont(b, "Marker Felt", 30);//第2句旁白的层
		label2->setPosition(Point(s.width/2,s.height/2));
		label2->setOpacity(0);
		this->addChild(label2,3,1);
		auto action2 = FadeIn::create(1.0f);
		label2->runAction(action2);
		count = count+1;}


		else if(count == 2)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("StartGameWord.xml");
			__String* a = (__String*)string->objectForKey("3");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "arial", 30);//第3句旁白的层
			label3->setPosition(Point(s.width/2,s.height/2));
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
			__Dictionary* string = __Dictionary::createWithContentsOfFile("StartGameWord.xml");
			__String* a = (__String*)string->objectForKey("4");
			const char* b = a->getCString();
			Label* label4 = Label::createWithSystemFont(b, "Arial", 30);//第4句旁白的层
			label4->setPosition(Point(s.width/2,s.height/2));
			label4->setOpacity(0);
			this->addChild(label4,3,1);
			auto action2 = FadeIn::create(1.0f);
			label4->runAction(action2);
			count = count+1;
		}

		else if(count == 4)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("StartGameWord.xml");
			__String* a = (__String*)string->objectForKey("5");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setPosition(Point(s.width/2,s.height/2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;


		    auto menu = Menu::create(MenuItemImage::create("jixuWhenEased.png", "jixuWhenTouched.png", [](Object* obj){
			auto scene1 = WhenNotGoToDream::createScene();//创建待切换的场景
		    auto transition = TransitionFade::create(0.2f, scene1);//给场景包装动画特效  
	     	Director::getInstance()->replaceScene(transition);//运用导演类来进行切换场景
			count = 1;
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("backgroundBGM.mp3"); //停止背景音乐
	}), NULL);
	       menu->setPosition(ccp(s.width / 9*8, s.height /10));
	      addChild(menu, 1);  //开始按钮

		  
		}
		return true;

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenerForDialogue1,this);


	return true;
}