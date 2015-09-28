#ifndef TALKLAYER_H
#define TALKLAYER_H

#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;

class TalkLayer :public Layer{
public:
	CREATE_FUNC(TalkLayer);
	bool init();
};

#endif