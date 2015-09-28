#ifndef ANIMATIONUTIL_H
#define ANIMATIONUTIL_H

#include "cocos2d.h"
USING_NS_CC;

class AnimationUtil{
public:
	//direction��һ��intֵ������0�����£�1������2�����ң�3������
	//nameֵ����Ҫ�Ӻ�׺������hero.png��ֻ������hero���ɡ�
	//delayΪ�л��ٶȡ�
	//iloopΪѭ��������-1ʱΪѭ�����š�
	static Animation*createWithSingleFrameNameBig(const char*name, int direction, float delay, int iLoops);
	static Animation*createWithSingleFrameNameSmall(const char*name, char* direction, float delay, int iLoops);
};

#endif