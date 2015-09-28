#ifndef CONTROLLERLISTENER_H
#define CONTROLLERLISTENER_H

#include "cocos2d.h"
using namespace cocos2d;
class ControllerListener{
public:
	//设置目标坐标，虚函数
	virtual void setTagPosition(int x, int y) = 0;
	//获取目标坐标，虚函数
	virtual Point getTagPosition() = 0;
};
#endif