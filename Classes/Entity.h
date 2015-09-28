#ifndef ENTITY_H
#define ENTITY_H

#include "cocos2d.h"
#include "ControllerListener.h"
#include "Controller.h"
using namespace cocos2d;
//实体类，作为Hero，NPC等的父类，仅能绑定设置精灵对象
class Entity :public Node,public ControllerListener{
	//成员函数
public:
	//绑定精灵对象
	void bindSprite(Sprite*sprite);
	//绑定控制器
	void setController(Controller*controller);
	//实现接口方法
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
	//成员变量
public:
	//使用的精灵对象
	Sprite*m_sprite;
	Controller*m_controller;
};
#endif