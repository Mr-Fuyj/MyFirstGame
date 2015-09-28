#ifndef HERO_H
#define HERO_H

#include "Entity.h"

class Hero :public Entity{
public:
	TMXTiledMap*m_map;
	bool speekOrNot;
	TMXLayer*meta;
	bool plot[18];
	/*bool possession[4];*/
	bool madeChoiceOrNot;
	CREATE_FUNC(Hero);
	virtual bool init();
	//用以加载Hero不同奔跑方向的动画。方向格式为：Up，Down，Left，Right
	void run(char*direction);
	void setViewPointByPlayer();
	void setTiledMap(TMXTiledMap*map);
	virtual void setTagPosition(int x, int y);
	Point tileCoordForPosition(Point pos);
};

#endif