#ifndef __CLOCK_H__
#define __CLOCK_H__

#include"cocos2d.h"

class Clock :public cocos2d::Sprite
{
public:
	Clock();
	static Clock* create();
	virtual bool init();
	void setTime(int time);
	int getTime();
	void changeTimeSprite(float dt);
	void setTimeSprite(int time);
private:
	int _time;
	cocos2d::Sprite*_first;
	cocos2d::Sprite* _second;
	cocos2d::Sprite* _clock;
	
};

#endif
