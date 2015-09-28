#ifndef _EndOfStay_H_
#define _EndOfStay_H_
#include "cocos2d.h"
using namespace cocos2d;

class EndOfStay : public cocos2d::Layer {
public:
	static Scene* createScene();


	virtual bool init();


	CREATE_FUNC(EndOfStay);
};

#endif