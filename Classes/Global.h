#ifndef GLOBAL_H
#define GLOBAL_H
#include"ControllerLayer.h"
#include"cocos2d.h"
#include "Hero.h"
#include"Singleton.h"
#include"MoveController.h"
#include"GameScene.h"
#include"MyMap.h"
using namespace cocos2d;
class MoveController;
class Global : public Singleton<Global>{
public:
	Hero *hero;
	Point touchPositionGlobal;
	Point convertedTouchPosition;
	MyMap *myMap;
	TMXTiledMap *map;
	Point menuTouchPosition;
	ControllerLayer *controllerLayer;
	MoveController *moveController;
	GameScene *gameScene;
	int dialogStartNum;
	int dialogEndNum;
	//���ڴ�����ͼʱ�������
	int mapNum;
	//���ڴ�����ͼʱ����caseֵ
	int caseNum;
	int NPCNum;
	Size visibleSize;
	bool load;
	int loadMapNum;
	Global();
	~Global();
	
};
#define sGlobal Global::instance()
#endif