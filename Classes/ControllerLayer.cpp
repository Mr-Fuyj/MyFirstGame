#include"ControllerLayer.h"
#include"Global.h"
#define SPEED 3

ControllerLayer::ControllerLayer(){
	sGlobal->controllerLayer = this;
}
ControllerLayer::~ControllerLayer(){

}

bool ControllerLayer::init(){
	if (!Layer::init()){ 
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//开始创建四个按钮
	Sprite*up = Sprite::create("UpButtonWhenTouched.png");
	up->setPosition(Point(visibleSize.width*0.85f, visibleSize.height*0.25f));
	this->addChild(up);
	Sprite*down = Sprite::create("DownButtonWhenTouched.png");
	down->setPosition(Point(visibleSize.width*0.85f, visibleSize.height*0.1f));
	this->addChild(down);	
	Sprite*left = Sprite::create("LeftButtonWhenTouched.png");
	left->setPosition(Point(visibleSize.width*0.75f, visibleSize.height*0.1f));
	this->addChild(left);	
	Sprite*right = Sprite::create("RightButtonWhenTouched.png");
	right->setPosition(Point(visibleSize.width*0.95f, visibleSize.height*0.1f));
	this->addChild(right);












	//前方高能
	//因为赶时间所以不把他总结成函数
	//所以会很丑
	//有时间要改回来




















	//up按钮的监听者
	auto listenerUp = EventListenerTouchOneByOne::create();
	listenerUp->onTouchBegan = [&](Touch*touch, Event*event){
		//这两句我都看不大懂照着抄的
		//据说是用来取出注册监听事件时绑定的node对象
		//估计target是绑定的精灵对象
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//判断点击范围是否与精灵重合
		if (target->getBoundingBox().containsPoint(position)){
			//更改透明度，即按动效果
			target->setOpacity(170);
			sGlobal->moveController->setSpeedY(SPEED);
			/*sGlobal->hero->stopAllActions();*/
			Director::sharedDirector()->getActionManager()->removeAllActions();
			sGlobal->hero->run("Up");
			return true;
		}
		return false;
	};
	listenerUp->onTouchMoved = [&](Touch*touch, Event*event){
		log("up");
	};
	listenerUp->onTouchEnded = [&](Touch*touch, Event*event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setOpacity(255);
		sGlobal->moveController->setSpeedY(0);
		/*sGlobal->hero->stopAllActions();*/
		Director::sharedDirector()->getActionManager()->removeAllActions();
		sGlobal->hero->run("UpStop");
		log("endup");
	};
	//绑定up按钮与该事件
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerUp, up);









	//Down按钮的监听者
	auto listenerDown = EventListenerTouchOneByOne::create();
	listenerDown->onTouchBegan = [&](Touch*touch, Event*event){
		//这几句我都看不大懂照着抄的
		//据说是用来取出注册监听事件时绑定的node对象
		//估计target是绑定的精灵对象
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//判断点击范围是否与精灵重合
		if (target->getBoundingBox().containsPoint(position)){
			//更改透明度，即按动效果
			sGlobal->moveController->setSpeedY(-SPEED);
			target->setOpacity(170);
			/*sGlobal->hero->stopAllActions();*/
			Director::sharedDirector()->getActionManager()->removeAllActions();
			sGlobal->hero->run("Down");
			return true;
		}
		return false;
	};
	listenerDown->onTouchMoved = [&](Touch*touch, Event*event){
		log("down");
	};
	listenerDown->onTouchEnded = [&](Touch*touch, Event*event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		sGlobal->moveController->setSpeedY(0);
		target->setOpacity(255);
		/*sGlobal->hero->stopAllActions();*/
		Director::sharedDirector()->getActionManager()->removeAllActions();
		sGlobal->hero->run("DownStop");
		log("enddown");
	};
	//绑定down按钮与该事件
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerDown, down);










	//Left按钮与监听者
	auto listenerLeft = EventListenerTouchOneByOne::create();
	listenerLeft->onTouchBegan = [&](Touch*touch, Event*event){
		//这几句我都看不大懂照着抄的
		//据说是用来取出注册监听事件时绑定的node对象
		//估计target是绑定的精灵对象
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//判断点击范围是否与精灵重合
		if (target->getBoundingBox().containsPoint(position)){
			//更改透明度，即按动效果
			target->setOpacity(170);
			sGlobal->moveController->setSpeedX(-SPEED);
			/*sGlobal->hero->stopAllActions();*/
			Director::sharedDirector()->getActionManager()->removeAllActions();
			sGlobal->hero->run("Left");
			return true;
		}
		return false;
	};
	listenerLeft->onTouchMoved = [&](Touch*touch, Event*event){
		log("left");
	};
	listenerLeft->onTouchEnded = [&](Touch*touch, Event*event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setOpacity(255);
		sGlobal->moveController->setSpeedX(0);
		/*sGlobal->hero->stopAllActions();*/
		Director::sharedDirector()->getActionManager()->removeAllActions();
		sGlobal->hero->run("LeftStop");
		log("endleft");
	};
	//绑定left按钮与监听者
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerLeft, left);













	//Right按钮与监听者
	auto listenerRight = EventListenerTouchOneByOne::create();
	listenerRight->onTouchBegan = [&](Touch*touch, Event*event){
		//这两句我都看不大懂照着抄的
		//据说是用来取出注册监听事件时绑定的node对象
		//估计target是绑定的精灵对象
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//判断点击范围是否与精灵重合
		if (target->getBoundingBox().containsPoint(position)){
			//更改透明度，即按动效果
			target->setOpacity(170);
			sGlobal->moveController->setSpeedX(SPEED);
			/*sGlobal->hero->stopAllActions();*/
			Director::sharedDirector()->getActionManager()->removeAllActions();
			sGlobal->hero->run("Right");
			return true;
		}
		return false;
	};
	listenerRight->onTouchMoved = [&](Touch*touch, Event*event){
		log("right");
	};
	listenerRight->onTouchEnded = [&](Touch*touch, Event*event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setOpacity(255);
		sGlobal->moveController->setSpeedX(0);
		/*sGlobal->hero->stopAllActions();*/
		Director::sharedDirector()->getActionManager()->removeAllActions();
		sGlobal->hero->run("RightStop");
		log("endright");
	};
	//绑定right按钮与监听者
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerRight, right);
}