#ifndef CONTROLLERLISTENER_H
#define CONTROLLERLISTENER_H

#include "cocos2d.h"
using namespace cocos2d;
class ControllerListener{
public:
	//����Ŀ�����꣬�麯��
	virtual void setTagPosition(int x, int y) = 0;
	//��ȡĿ�����꣬�麯��
	virtual Point getTagPosition() = 0;
};
#endif