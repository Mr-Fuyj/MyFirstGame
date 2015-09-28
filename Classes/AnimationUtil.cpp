#include "AnimationUtil.h"

Animation* AnimationUtil::createWithSingleFrameNameBig(const char*name, int direction, float delay, int iLoops){
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;
	int index = 1;
	//act�Ƕ�����ţ�0�����ҽţ�2�������
	int act = 0;
	//0�����£�1������2�����ң�3������
	int directionNum=direction;
	//��ȡpng��һ������Ϊframe
	frame = SpriteFrame::create(StringUtils::format("%s.png", name), Rect(act * 32, directionNum * 32, 32, 32));
	act = 2;
	//�������
	frameVec.pushBack(frame);
	//ͬ��
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