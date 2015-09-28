#include "gamescene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "WhenNotGoToDream.h"
#include "WhenInTaxi.h"

Scene* WhenNotGoToDream::createScene() {
	auto scene = Scene::create();

	auto layer = WhenNotGoToDream::create();

	scene->addChild(layer);

	return scene;
}

bool WhenNotGoToDream::init() {

	Sprite *backGround = Sprite::create("WhenInPub.jpg");
	Size size = Director::sharedDirector()->getWinSize();
	float scalX = size.width / backGround->getContentSize().width;///设置x轴方向的缩放系数
	float scalY = size.height / backGround->getContentSize().height;//设置y轴方向的缩放系数
	backGround->setScaleX(scalX);
	backGround->setScaleY(scalY);
	backGround->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(backGround, 0, 0);//菜单背景

	/*Sprite *TalkBox = Sprite::create("TalkBackGround2.png");
	TalkBox->setAnchorPoint(Point(0.5,0.5));
	TalkBox->setPosition(Point(size.width/2,TalkBox->getContentSize().height/2));
	this->addChild(TalkBox);*/


	Size s = Director::getInstance()->getVisibleSize(); //获取屏幕大小

	__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
	__String* a = (__String*)string->objectForKey("1");
	const char* b = a->getCString();
	Label* label1 = Label::createWithSystemFont(b, "Arial", 30);//第一句旁白的层
	/*TalkBox->setAnchorPoint(Point(0.5,0.5));
	TalkBox->setPosition(Point(size.width/2,TalkBox->getContentSize().height/2));*/
	label1->setAnchorPoint(Point(0.5,0.5));
	label1->setPosition(Point(s.width/2,label1->getContentSize().height/3*2));
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
			__String* a = (__String*)string->objectForKey("2");
			const char* b = a->getCString();
			Label* label2 = Label::createWithSystemFont(b, "Arial", 30);//第2句旁白的层
			label2->setAnchorPoint(Point(0.5,0.5));
	label2->setPosition(Point(s.width/2,label2->getContentSize().height/3*2));
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
			__String* a = (__String*)string->objectForKey("3");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//第3句旁白的层
			label3->setAnchorPoint(Point(0.5,0.5));
	label3->setPosition(Point(s.width/2,label3->getContentSize().height/3*2));
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
			__String* a = (__String*)string->objectForKey("4");
			const char* b = a->getCString();
			Label* label4 = Label::createWithSystemFont(b, "Arial", 30);//第4句旁白的层
			label4->setAnchorPoint(Point(0.5,0.5));
	label4->setPosition(Point(s.width/2,label4->getContentSize().height/3*2));
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
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("5");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 5)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("6");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 6)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("7");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 7)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("8");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 8)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("9");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}


		else if(count == 9)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("10");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 10)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("11");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}


		else if(count == 11)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("12");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 12)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("13");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}


		else if(count == 13)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("14");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 14)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("15");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 15)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("16");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}


		else if(count == 16)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("17");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}

		else if(count == 17)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("18");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;
		}


		else if(count == 18)
		{
			this->removeChildByTag(1);
			Size s = Director::getInstance()->getVisibleSize();//获取屏幕大小
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("19");
			const char* b = a->getCString();
			Label* label5 = Label::createWithSystemFont(b, "Arial", 30);//第5句旁白的层
			label5->setAnchorPoint(Point(0.5,0.5));
	label5->setPosition(Point(s.width/2,label5->getContentSize().height/3*2));
			label5->setOpacity(0);
			this->addChild(label5,3,1);
			auto action2 = FadeIn::create(1.0f);
			label5->runAction(action2);
			count = count+1;

			auto menu = Menu::create(MenuItemImage::create("jixuWhenEased.png", "jixuWhenTouched.png", [](Object* obj){
				auto scene1 = WhenInTaxi::createScene();//创建待切换的场景
		    auto transition = TransitionFade::create(0.2f, scene1);//给场景包装动画特效  
	     	Director::getInstance()->replaceScene(transition);//运用导演类来进行切换场景
			count = 1;
	       }), NULL);
	       menu->setPosition(ccp(s.width / 9*8, s.height /10));
	      addChild(menu, 1);  //开始按钮

		 
		} 
		return true;
		


	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenerForDialogue1,this);


	return true;
}