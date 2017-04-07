#ifndef __BASESCENE_H__
#define __BASESCENE_H__

#include "cocos2d.h"

class BaseScene :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(BaseScene);
	void menuCallback(cocos2d::Ref * sender);
private:

};
#endif
