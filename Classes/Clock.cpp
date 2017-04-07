#include "Clock.h"
USING_NS_CC;
Clock::Clock():_time(0),_first(NULL),_second(NULL),_clock(NULL)
{
}
Clock * Clock::create()
{
	auto clock = new Clock();
	if (clock&&clock->init())
	{
		clock->autorelease();
		return clock;
	}
	CC_SAFE_DELETE(clock);
	return nullptr;
}

bool Clock::init()
{
	if(!Sprite::init())
	return false;
	/*auto texture =SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("HLDDZ_MainGame0_2x_1number_%02d.png", 1));*/
	_clock = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_202.png");
	_first = Sprite::createWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_1number_%02d.png",0));
	_second = Sprite::createWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_1number_%02d.png",0));
	_first->setPosition(_clock->getContentSize().width *2/5 , _clock->getContentSize().height *2/ 5);
	_first->setScale(0.7f);
	_second->setPosition(_clock->getContentSize().width *3/ 5, _clock->getContentSize().height*2 / 5);
	_second->setScale(0.7f);
	_clock->addChild(_first,1);
	_clock->addChild(_second,1);
	/*_first->setSpriteFrame(texture);*/
	this->addChild(_clock);
	this->schedule(schedule_selector(Clock::changeTimeSprite), 1.0f);
	return true;
}

void Clock::setTime(int time)
{
	_time = time;
	setTimeSprite(time);
}

int Clock::getTime() 
{
	return _time;
}

void Clock::changeTimeSprite(float dt)
{
	//log("1");
	_time--;
	if (_time < 0)
		_time = 0;
	setTimeSprite(_time);
}

void Clock::setTimeSprite(int time)
{
	int first = time / 10;
	int second = time % 10;
	auto firstTexture = SpriteFrameCache::getInstance()->getSpriteFrameByName((StringUtils::format("HLDDZ_MainGame0_2x_1number_%02d.png", first)));
	auto secondTexture = SpriteFrameCache::getInstance()->getSpriteFrameByName((StringUtils::format("HLDDZ_MainGame0_2x_1number_%02d.png", second)));
	_first->setSpriteFrame(firstTexture);
	_second->setSpriteFrame(secondTexture);
}
