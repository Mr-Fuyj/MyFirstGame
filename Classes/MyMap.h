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
	//��ЩPoint������Ƭ��ͼ��������
	//��ʾ�뿪�˵�ͼ�Ĵ��͵�����
	Point transmitPoint[20];
	//��ʾ��Ӧ���͵㽫Ҫ�����λ��
	Destination destination[20];
	//��ʾ�õ�ͼ�е�npc
	NPC npc[10];
	//�趨�õ�ͼ������npc������
	void setAllNPC();
	//�趨�õ�ͼĳ��npc������
	void setNPC(int NumInMap,int NPCNum,int positionX,int positionY,int keyStart,int KeyEnd);
	void changeMap(Point transmitPoint);
	CREATE_FUNC(MyMap);
	//�����趨point��ֵ
	void setPoint(Point&point,int x,int y);
	//����ת��cocos�������Ƭ��������
	Point positionForTileCoord(Point tileCoord);
	//�����趨destination��ֵ
	void setDestination(int Point, int map, int x, int y);
	//������ʾ�Ի�����
	bool showDialogBox(Point NPCPosition);
	//����ȷ������ͷ��
	void setNPCPortrait(Size visibleSize, int NPCNum);
	//��������Ի�����
	void outDialog(Size visibleSize, int NPCNum);
	//��������ѡ��
	void makeChoice(Size visibleSize, int NPCNum);
	//��ȡ��Ʒ
	void getButterfly();
	void getBox();
	void getNote();
	void getSchedule();
	void getSister();
	void setDay(int day);
	//�˺����������ص�ͼ���
	int getMapNum(int sceneNum);
	//�ж��Ƿ�������Ѱ����npc��������Ӧ��Ӧ
	void unusualNPC(Size visibleSize ,int NPCNum);
	bool init();
};

#endif