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
	//��ʼ���ٶȣ�����֡ѭ��
	virtual bool init();
	//����ÿһ֡��Ҫ�����£������ƶ���
	virtual void update(float dt);
	void setSpeedX(int Speed);
	void setSpeedY(int Speed);

	int m_speedX;
	int m_speedY;
	//ע����Ļ�����¼�
	/*void registeTouchEvent();*/
};

#endif