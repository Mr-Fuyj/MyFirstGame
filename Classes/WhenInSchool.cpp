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
	float scalX = size.width / backGround->getContentSize().width;///����x�᷽�������ϵ��
	float scalY = size.height / backGround->getContentSize().height;//����y�᷽�������ϵ��
	backGround->setScaleX(scalX);
	backGround->setScaleY(scalY);
	backGround->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(backGround, 0, 0);//�˵�����


	Size s = Director::getInstance()->getVisibleSize(); //��ȡ��Ļ��С

	__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
	__String* a = (__String*)string->objectForKey("24");
	const char* b = a->getCString();
	Label* label1 = Label::createWithSystemFont(b, "Arial", 30);//��һ���԰׵Ĳ�
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
			Size s = Director::getInstance()->getVisibleSize();//��ȡ��Ļ��С
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("25");
			const char* b = a->getCString();
			Label* label2 = Label::createWithSystemFont(b, "Arial", 30);//��2���԰׵Ĳ�
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
			Size s = Director::getInstance()->getVisibleSize();//��ȡ��Ļ��С
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("26");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//��3���԰׵Ĳ�
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
			Size s = Director::getInstance()->getVisibleSize();//��ȡ��Ļ��С
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("27");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//��3���԰׵Ĳ�
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
			Size s = Director::getInstance()->getVisibleSize();//��ȡ��Ļ��С
			__Dictionary* string = __Dictionary::createWithContentsOfFile("WhenNotGoToDream.xml");
			__String* a = (__String*)string->objectForKey("28");
			const char* b = a->getCString();
			Label* label3 = Label::createWithSystemFont(b, "Arial", 30);//��3���԰׵Ĳ�
			label3->setAnchorPoint(Point(1,1));
			label3->setPosition(Point(s.width,s.height));
			label3->setOpacity(0);
			this->addChild(label3,3,1);
			auto action2 = FadeIn::create(1.0f);
			label3->runAction(action2);
			count = count+1;
			auto menu = Menu::create(MenuItemImage::create("jixuWhenEased.png", "jixuWhenTouched.png", [](Object* obj){
				auto scene1 = GameScene::createScene();//�������л��ĳ���
				auto transition = TransitionFade::create(0.2f, scene1);//��������װ������Ч  
				Director::getInstance()->replaceScene(transition);//���õ������������л�����
				CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("WhenInSchool.mp3");
				count = 1;
			}), NULL);
			menu->setPosition(ccp(s.width / 9 * 8, s.height / 10));
			addChild(menu, 1);  //��ʼ��ť

			
		}
		
		

		return true;

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenerForDialogue1,this);


	return true;
}