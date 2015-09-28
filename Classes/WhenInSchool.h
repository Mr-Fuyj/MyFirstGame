#ifndef _WhenInSchool_H_
#define _WhenInSchool_H_
#include "cocos2d.h"
using namespace cocos2d;

class WhenInSchool : public cocos2d::Layer {
public:
	static Scene* createScene();


	virtual bool init();


	CREATE_FUNC(WhenInSchool);
};

#endif