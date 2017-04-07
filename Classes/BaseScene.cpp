#include"BaseScene.h"
#include"GameScene.h"

USING_NS_CC;

Scene * BaseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BaseScene::create();
	scene->addChild(layer);
	return scene;
}

bool BaseScene::init()
{
	if(!Layer::init())
	    return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("HLDDZ_MainGame0_2x.plist");

	auto background = Sprite::create("Common_BG1_2x.png");
	background->setScale(800.0 / 960);
	background->setAnchorPoint(Vec2(0, 1));
	background->setPosition(0, visibleSize.height);
	this->addChild(background,0);

	auto normal = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_start.png");
	auto selected = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_start.png");

	auto startMenuImage = MenuItemSprite::create(normal,selected, CC_CALLBACK_1(BaseScene::menuCallback, this));
	auto menu = Menu::create(startMenuImage, NULL);
	this->addChild(menu,1);
	menu->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	return true;
}

void BaseScene::menuCallback(cocos2d::Ref * sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
