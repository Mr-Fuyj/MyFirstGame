#ifndef MAP_H
#define MAP_H

#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;

enum Item{
	choice ,
	butterfly,
	box,
	note,
	mySchedule,
	sister,
	day1,
	day2,
	day3,
	day4
};

struct Destination{
	int mapNum=-1;
	Point startPosition = Point(-1, -1);
};

struct NPC{
	int NPCNum = -1;
	Point NPCPosition = Point(-1, -1);
	int keyStart = -1;
	int keyEnd = -1;
	int NumInMap = -1;
};

class MyMap :public Node{
public:
	TMXTiledMap* m_map;
	//这些Point都是瓦片地图格子坐标
	//表示离开此地图的传送点坐标
	Point transmitPoint[20];
	//表示对应传送点将要到达的位置
	Destination destination[20];
	//表示该地图中的npc
	NPC npc[10];
	//设定该地图的所有npc各属性
	void setAllNPC();
	//设定该地图某个npc各属性
	void setNPC(int NumInMap,int NPCNum,int positionX,int positionY,int keyStart,int KeyEnd);
	void changeMap(Point transmitPoint);
	CREATE_FUNC(MyMap);
	//用以设定point的值
	void setPoint(Point&point,int x,int y);
	//用以转换cocos坐标和瓦片网格坐标
	Point positionForTileCoord(Point tileCoord);
	//用以设定destination的值
	void setDestination(int Point, int map, int x, int y);
	//用以显示对话窗口
	bool showDialogBox(Point NPCPosition);
	//用以确定人设头像
	void setNPCPortrait(Size visibleSize, int NPCNum);
	//用以输出对话内容
	void outDialog(Size visibleSize, int NPCNum);
	//用以做出选择
	void makeChoice(Size visibleSize, int NPCNum);
	//获取物品
	void getButterfly();
	void getBox();
	void getNote();
	void getSchedule();
	void getSister();
	void setDay(int day);
	//此函数用来返回地图序号
	int getMapNum(int sceneNum);
	//判断是否遇到不寻常的npc并作出相应响应
	void unusualNPC(Size visibleSize ,int NPCNum);
	bool init();
};

#endif