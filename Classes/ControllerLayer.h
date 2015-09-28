#ifndef CONTROLLERLAYER_H
#define CONTROLLERLAYER_H

#include "cocos2d.h"
using namespace cocos2d;

class ControllerLayer :public Layer{
public:
	ControllerLayer();
	~ControllerLayer();
	bool init();
	CREATE_FUNC(ControllerLayer);
};

#endif