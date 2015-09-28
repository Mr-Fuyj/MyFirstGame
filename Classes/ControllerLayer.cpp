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

	//��ʼ�����ĸ���ť
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












	//ǰ������
	//��Ϊ��ʱ�����Բ������ܽ�ɺ���
	//���Ի�ܳ�
	//��ʱ��Ҫ�Ļ���




















	//up��ť�ļ�����
	auto listenerUp = EventListenerTouchOneByOne::create();
	listenerUp->onTouchBegan = [&](Touch*touch, Event*event){
		//�������Ҷ����������ų���
		//��˵������ȡ��ע������¼�ʱ�󶨵�node����
		//����target�ǰ󶨵ľ������
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//�жϵ����Χ�Ƿ��뾫���غ�
		if (target->getBoundingBox().containsPoint(position)){
			//����͸���ȣ�������Ч��
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
	//��up��ť����¼�
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerUp, up);









	//Down��ť�ļ�����
	auto listenerDown = EventListenerTouchOneByOne::create();
	listenerDown->onTouchBegan = [&](Touch*touch, Event*event){
		//�⼸���Ҷ����������ų���
		//��˵������ȡ��ע������¼�ʱ�󶨵�node����
		//����target�ǰ󶨵ľ������
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//�жϵ����Χ�Ƿ��뾫���غ�
		if (target->getBoundingBox().containsPoint(position)){
			//����͸���ȣ�������Ч��
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
	//��down��ť����¼�
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerDown, down);










	//Left��ť�������
	auto listenerLeft = EventListenerTouchOneByOne::create();
	listenerLeft->onTouchBegan = [&](Touch*touch, Event*event){
		//�⼸���Ҷ����������ų���
		//��˵������ȡ��ע������¼�ʱ�󶨵�node����
		//����target�ǰ󶨵ľ������
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//�жϵ����Χ�Ƿ��뾫���غ�
		if (target->getBoundingBox().containsPoint(position)){
			//����͸���ȣ�������Ч��
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
	//��left��ť�������
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerLeft, left);













	//Right��ť�������
	auto listenerRight = EventListenerTouchOneByOne::create();
	listenerRight->onTouchBegan = [&](Touch*touch, Event*event){
		//�������Ҷ����������ų���
		//��˵������ȡ��ע������¼�ʱ�󶨵�node����
		//����target�ǰ󶨵ľ������
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point position = Director::getInstance()->convertToGL(touch->getLocationInView());
		//�жϵ����Χ�Ƿ��뾫���غ�
		if (target->getBoundingBox().containsPoint(position)){
			//����͸���ȣ�������Ч��
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
	//��right��ť�������
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerRight, right);
}