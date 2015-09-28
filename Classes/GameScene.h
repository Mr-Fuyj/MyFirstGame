#ifndef GAMESCENE_H
#define GAMESCENE_H

#include"cocos2d.h"
using namespace cocos2d;
class GameScene :public Layer{
public:
	static Scene*createScene();
	CREATE_FUNC(GameScene);
	virtual bool init();
	void addHero(TMXTiledMap*map,Point startPoint);
	void changeMap(Point startPoint,int mapNum);
};
#endif