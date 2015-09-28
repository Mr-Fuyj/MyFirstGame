#ifndef ENTITY_H
#define ENTITY_H

#include "cocos2d.h"
#include "ControllerListener.h"
#include "Controller.h"
using namespace cocos2d;
//ʵ���࣬��ΪHero��NPC�ȵĸ��࣬���ܰ����þ������
class Entity :public Node,public ControllerListener{
	//��Ա����
public:
	//�󶨾������
	void bindSprite(Sprite*sprite);
	//�󶨿�����
	void setController(Controller*controller);
	//ʵ�ֽӿڷ���
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
	//��Ա����
public:
	//ʹ�õľ������
	Sprite*m_sprite;
	Controller*m_controller;
};
#endif