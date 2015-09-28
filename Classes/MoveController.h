#ifndef MOVECONTROLLER_H
#define MOVECONTROLLER_H

#include"cocos2d.h"
#include"Global.h"
#include"Controller.h"
using namespace cocos2d;

class MoveController :public Controller{
public:
	MoveController();
	CREATE_FUNC(MoveController);
	//初始化速度，开启帧循环
	virtual bool init();
	//设置每一帧都要做的事，包括移动等
	virtual void update(float dt);
	void setSpeedX(int Speed);
	void setSpeedY(int Speed);

	int m_speedX;
	int m_speedY;
	//注册屏幕触摸事件
	/*void registeTouchEvent();*/
};

#endif