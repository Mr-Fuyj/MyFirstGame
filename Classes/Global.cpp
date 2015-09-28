#include "Global.h"

DECLARE_SINGLETON_MEMBER(Global);

Global::Global(void)
{
	hero = NULL;
	touchPositionGlobal = Point(-1, -1);
	map = NULL;
	menuTouchPosition = Point(-1, -1);
	controllerLayer = NULL;
	moveController = NULL;
	dialogStartNum = 0;
	dialogEndNum = 0;
	mapNum = -1;
	myMap = NULL;
	gameScene = NULL;
	caseNum = -1;
	NPCNum = -1;
	load = 0;
	loadMapNum = -1;
}

Global::~Global(void)
{

}