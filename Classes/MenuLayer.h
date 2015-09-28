#ifndef _MenuLayer_H_
#define _MenuLayer_H_
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio::timeline;
#include "cocos2d.h"
using namespace cocos2d;

class MenuLayer :public  Layer {
public:
	//����Ϊ�����������Ҫ����
	//��Ϊ���ز����µ�scene
	/*static Scene* createScene();*/

	virtual bool init();

	CREATE_FUNC(MenuLayer);

	int MenuLayer::upOrDown();

	float spItemWidth;
	float spItemHeight;
	float itemMainWidth;
	float itemMainHight;
	int itemNum;
	float pos2x;
	float pos2y;
	
	EventListenerTouchOneByOne* listener;
	Sprite* itemMain;
};

#endif