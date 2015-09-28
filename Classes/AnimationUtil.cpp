#include "AnimationUtil.h"

Animation* AnimationUtil::createWithSingleFrameNameBig(const char*name, int direction, float delay, int iLoops){
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;
	int index = 1;
	//act是动作标号，0代表右脚，2代表左脚
	int act = 0;
	//0代表下，1代表左，2代表右，3代表上
	int directionNum=direction;
	//截取png的一部分作为frame
	frame = SpriteFrame::create(StringUtils::format("%s.png", name), Rect(act * 32, directionNum * 32, 32, 32));
	act = 2;
	//推入队列
	frameVec.pushBack(frame);
	//同上
	frame = SpriteFrame::create(StringUtils::format("%s.png", name), Rect(act * 32, directionNum * 32, 32, 32));
	frameVec.pushBack(frame);
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}
Animation* AnimationUtil::createWithSingleFrameNameSmall(const char*name, char* direction, float delay, int iLoops){
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*>frameVec;
	SpriteFrame* frame = NULL;
	int index = 1;
	if ((strcmp(direction, "UpStop") != 0) && (strcmp(direction, "DownStop") != 0) && (strcmp(direction, "RightStop") != 0) && (strcmp(direction, "LeftStop") != 0)){
		for (int i = 1; i <= 2; i++){
			frame = cache->getSpriteFrameByName(StringUtils::format("%s_%s_%d.png", name, direction, i));
			if (frame == NULL){
				break;
			}
			frameVec.pushBack(frame);
		}
	}
	else{
		if (strcmp(direction, "UpStop") == 0){
			frame = cache->getSpriteFrameByName(StringUtils::format("%s_Up_0.png", name));
			frameVec.pushBack(frame);
		}
		else 	if (strcmp(direction, "DownStop") == 0){
			frame = cache->getSpriteFrameByName(StringUtils::format("%s_Down_0.png", name));
			frameVec.pushBack(frame);
		}
		else 	if (strcmp(direction, "RightStop") == 0){
			frame = cache->getSpriteFrameByName(StringUtils::format("%s_Right_0.png", name));
			frameVec.pushBack(frame);
		}
		else 	if (strcmp(direction, "LeftStop") == 0){
			frame = cache->getSpriteFrameByName(StringUtils::format("%s_Left_0.png", name));
			frameVec.pushBack(frame);
		}
	}
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}