#include "MoveController.h"
#include"Global.h"

bool MoveController::init(){
	this->m_speedX = 0;
	this->m_speedY = 0;
	//开启帧循环
	this->scheduleUpdate();
	/*registeTouchEvent();*/
	return true;
}

void MoveController::update(float dt){
	if (sGlobal->load){
		Point loadPosition = sGlobal->hero->tileCoordForPosition(Point(CCUserDefault::sharedUserDefault()->getIntegerForKey("heroPositionX"), CCUserDefault::sharedUserDefault()->getIntegerForKey("heroPositionY")));
		int mapNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("mapNum");
		for (int i = 0; i <= 17; i++){
			bool a = CCUserDefault::sharedUserDefault()->getBoolForKey((StringUtils::format("bool_%d", i)).c_str());
			sGlobal->hero->plot[i] = CCUserDefault::sharedUserDefault()->getBoolForKey((StringUtils::format("bool_%d", i)).c_str());
		}
		sGlobal->gameScene->changeMap(loadPosition , mapNum);
		sGlobal->load = 0;
	}
	if (m_controllerListener == NULL){
		return;
	}
	if (sGlobal->hero->speekOrNot == 1){
		m_speedX = 0;
		m_speedY = 0;
	}
	Point position = m_controllerListener->getTagPosition();
	position.x += m_speedX;
	position.y += m_speedY;
	m_controllerListener->setTagPosition(position.x, position.y);
	///*log("update");*/
	//Point currentPosition = sGlobal->map->convertToNodeSpace(m_controllerListener->getTagPosition());
	//Point touchPosition = sGlobal->convertedTouchPosition;
	//if (sGlobal->touchPositionGlobal != Point(-1, -1)){
	//	/*Point touchPosition = sGlobal->touchPositionGlobal;*/
	//	if ((touchPosition.x > currentPosition.x+36 ) || (touchPosition.x<currentPosition.x-36 )){
	//		if (touchPosition.x > currentPosition.x+36){
	//			currentPosition.x += m_speedX;
	//			sGlobal->hero->run("Right");
	//		}
	//		else {
	//			currentPosition.x -= m_speedX;
	//			sGlobal->hero->run("Left");
	//		}
	//	}
	//	else if ((!((touchPosition.x > currentPosition.x+36 ) || (touchPosition.x<currentPosition.x-36 )) )
	//		&&((touchPosition.y>currentPosition.y+36 ) || (touchPosition.y < currentPosition.y-36 ))){
	//		if (touchPosition.y > currentPosition.y+36 ){
	//			currentPosition.y += m_speedY;
	//			sGlobal->hero->run("Up");
	//		}
	//		else{
	//			currentPosition.y -= m_speedY;
	//			sGlobal->hero->run("Down");
	//		}
	//	}
	//	else{
	//		log("end");
	//	}
	//	//else{
	//	//	sGlobal->hero->a
	//	//}
	//}
	//Point worldPosition=sGlobal->map->convertToWorldSpace(currentPosition);
	//m_controllerListener->setTagPosition(worldPosition.x, worldPosition.y);
}

void MoveController::setSpeedX(int speed){
	this->m_speedX = speed;
	log("speed x change");
}

void MoveController::setSpeedY(int speed){
	this->m_speedY = speed;
	log("speed y change");
}

MoveController::MoveController(){
	sGlobal->moveController = this;
}













//我觉得我写的不大对……
//void MoveController::registeTouchEvent(){
//	auto listener = EventListenerTouchOneByOne::create();
//	listener->onTouchBegan = [](Touch*touch, Event*event){
//		log("touchbegan");
//		return true;
//	};
//	listener->onTouchEnded = [&](Touch*touch, Event*event){
//		//获取触摸点的坐标，基于cocos2d
//		Point touchPosition = Director::getInstance()->convertToGL(touch->getLocationInView());
//		sGlobal->touchPositionGlobal = touchPosition;
//		sGlobal->convertedTouchPosition = sGlobal->map->convertToNodeSpace(touchPosition);
//	};
//
//
//
//
//
//
//
//
//
//	//listener->onTouchMoved = [&](Touch*touch, Event*event){
//	//	//获取触摸点的坐标，基于cocos2d
//	//	Point touchPosition = Director::getInstance()->convertToGL(touch->getLocationInView());
//	//	//获取对象坐标
//	//	Point myPosition = m_controllerListener->getTagPosition();
//	//	int speedX = 0;
//	//	int speedY = 0;
//	//	//判断移动方向
//	//	/*while (touchPosition != myPosition){*/
//	//		log("touch");
//	//		/*if (touchPosition != myPosition){*/
//	//			if (touchPosition.x > myPosition.x+16){
//	//				speedX = 1;
//	//				sGlobal->hero->run("Right");
//	//			}
//	//			else if (touchPosition.x < myPosition.x-16){
//	//				speedX = -1;
//	//				sGlobal->hero->run("Left");
//	//			}
//	//			setSpeedX(speedX);
//	//		/*}*/
//	//		/*else {*/
//	//			if (touchPosition.y > myPosition.y+16){
//	//				speedY = 1;
//	//				sGlobal->hero->run("Up");
//	//			}
//	//			else if (touchPosition.y < myPosition.y-16){
//	//				speedY = -1;
//	//				sGlobal->hero->run("Down");
//	//			}
//	//			setSpeedY(speedY); 
//	//		/*}*/
//	//			sGlobal->hero->setViewPointByPlayer();
//	//		touchPosition = Director::getInstance()->convertToGL(touch->getLocationInView());
//	//		myPosition = m_controllerListener->getTagPosition();
//	//	//}
//	////	speedX = 0;
//	////	speedY = 0;
//	//};
//	//listener->onTouchEnded = [&](Touch*touch, Event*event){
//	//	setSpeedY(0);
//	//	setSpeedX(0);
//	//};
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//}
