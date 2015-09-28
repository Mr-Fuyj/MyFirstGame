#ifndef ANIMATIONUTIL_H
#define ANIMATIONUTIL_H

#include "cocos2d.h"
USING_NS_CC;

class AnimationUtil{
public:
	//direction是一个int值，其中0代表下，1代表左，2代表右，3代表上
	//name值不需要加后缀名。如hero.png，只需输入hero即可。
	//delay为切换速度。
	//iloop为循环次数。-1时为循环播放。
	static Animation*createWithSingleFrameNameBig(const char*name, int direction, float delay, int iLoops);
	static Animation*createWithSingleFrameNameSmall(const char*name, char* direction, float delay, int iLoops);
};

#endif