#include "TalkLayer.h"
#include "Global.h"

USING_NS_CC;

bool TalkLayer::init(){
	if (!Layer::init()){
		return false;
	}
	//获取窗口大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//获取背景图片

	
	//创建对话背景图片
	Sprite*backGround = Sprite::create("TalkBackGround.png");
	backGround->setAnchorPoint(Point(0, 0));
	backGround->setPosition(Point(visibleSize.width*0.09, visibleSize.height*0.05));
	this->addChild(backGround);

	//创建人物头像
	Sprite*portrait = Sprite::create("chen1.png");
	portrait->setAnchorPoint(Point(0, 0));
	portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	this->addChild(portrait);


	FadeIn* fadeIn = FadeIn::create(0.1f);
	/*this->removeChildByTag(1);*/
	sGlobal->dialogStartNum++;
	String* cKey = String::createWithFormat("%d", sGlobal->dialogStartNum);
	std::string key = cKey->_string;
	Dictionary*dialogDictionary = Dictionary::createWithContentsOfFile("wenben.xml");
	const char*dialog = ((String*)dialogDictionary->objectForKey(key))->getCString();


	auto label = Label::createWithTTF(dialog, "arial.ttf", 24);
	label->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	this->addChild(label, 500, 1);









	//监听事件
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan=[&](Touch*touch, Event*event){
		this->removeChildByTag(1);
		return true;
	};
	listener->onTouchEnded = [&](Touch*touch, Event*event){
		/*FadeIn* fadeIn = FadeIn::create(0.1f);*/
		/*this->removeChildByTag(1);*/
		sGlobal->dialogStartNum++;
		String* cKey = String::createWithFormat("%d", sGlobal->dialogStartNum);
		std::string key = cKey->_string;
		Dictionary*dialogDictionary = Dictionary::createWithContentsOfFile("wenben.xml");
		const char*dialog = ((String*)dialogDictionary->objectForKey(key))->getCString();


		label = Label::createWithTTF(dialog, "ziti.TTF", 24);
		label->setPosition(Point(960*0.21, 640*0.25));
		this->addChild(label, 500, 1);
		/*label->setOpacity(0);*/
		/*Label* lb1 = Label::createWithTTF("123abc", "arial.TTF", 24);*/
		/*this->addChild(lb1, 500, 1);*/
		/*lb1->setPosition(Point(visibleSize.width*0.5f, visibleSize.height*0.5f));*/
		/*label->setGlobalZOrder(500);*/
		/*label->runAction(fadeIn);*/
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	
}
