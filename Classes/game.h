#ifndef _game_H_
#define _game_H_
#include "cocos2d.h"
using namespace cocos2d;

class game : public cocos2d::Layer {
public:
	static Scene* createScene();


	virtual bool init();


	CREATE_FUNC(game);
};

#endif