#include"GameScene.h"

USING_NS_CC;

GameScene::GameScene()
{
	
}

GameScene::~GameScene()
{
	delete _gameRule;
	_gameRule = nullptr;
}

Scene * GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("Common_BG2_2x.png");
	background->setScale(800.0 / 960.0f);
	background->setAnchorPoint(Vec2(0, 1));
	background->setPosition(0, visibleSize.height);
	this->addChild(background, 0);

	initData();
	newGame();

	//clock
	_clock = Clock::create();
	_clock->setScale(0.5f);
	_clock->setPosition(Vec2(visibleSize.width * 5 / 9 - 15, visibleSize.height * 2 / 5));
	this->addChild(_clock, 3, CLOCKSPRITE);
	_clock->setTime(30);

	//Sprite* temp1;
	//Sprite* temp2;
	////不抢
	//_player1BuQiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
	//temp1->setPosition(Vec2(_player1BuQiang->getContentSize().width*3/2, _player1BuQiang->getContentSize().height/2));
	//_player1BuQiang->addChild(temp1);
	//_player1BuQiang->setScale(0.7);
	//_player1BuQiang->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	//this->addChild(_player1BuQiang,1);

	//_player2BuQiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
	//temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
	//temp1->setPosition(Vec2(_player2BuQiang->getContentSize().width * 3 / 2, _player2BuQiang->getContentSize().height / 2));
	//_player2BuQiang->addChild(temp1);
	//_player2BuQiang->setScale(0.7);
	//_player2BuQiang->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	//this->addChild(_player2BuQiang,1);

	//_player3BuQiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
	//temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
	//temp1->setPosition(Vec2(_player3BuQiang->getContentSize().width * 3 / 2, _player3BuQiang->getContentSize().height / 2));
	//_player3BuQiang->addChild(temp1);
	//_player3BuQiang->setScale(0.7);
	//_player3BuQiang->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	//this->addChild(_player3BuQiang, 1);
	////抢地主
	//
	//_player1Qiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
	//temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
	//temp2= Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
	//temp1->setPosition(Vec2(_player1Qiang->getContentSize().width * 3 / 2, _player1Qiang->getContentSize().height / 2));
	//temp2->setPosition(Vec2(_player1Qiang->getContentSize().width * 5 / 2, _player1Qiang->getContentSize().height / 2));
	//_player1Qiang->addChild(temp1);
	//_player1Qiang->addChild(temp2);
	// _player1Qiang->setScale(0.7);
	// _player1Qiang->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player1Qiang, 1);

	// _player2Qiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
	// temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
	// temp1->setPosition(Vec2(_player2Qiang->getContentSize().width * 3 / 2, _player2Qiang->getContentSize().height / 2));
	// temp2->setPosition(Vec2(_player2Qiang->getContentSize().width * 5 / 2, _player2Qiang->getContentSize().height / 2));
	// _player2Qiang->addChild(temp1);
	// _player2Qiang->addChild(temp2);
	// _player2Qiang->setScale(0.7);
	// _player2Qiang->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player2Qiang, 1);

	// _player3Qiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
	// temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
	// temp1->setPosition(Vec2(_player3Qiang->getContentSize().width * 3 / 2, _player3Qiang->getContentSize().height / 2));
	// temp2->setPosition(Vec2(_player3Qiang->getContentSize().width * 5 / 2, _player3Qiang->getContentSize().height / 2));
	// _player3Qiang->addChild(temp1);
	// _player3Qiang->addChild(temp2);
	// _player3Qiang->setScale(0.7);
	// _player3Qiang->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player3Qiang, 1);

	////不叫
	//
	// _player1BuJiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
	// temp1->setPosition(Vec2(_player1BuJiao->getContentSize().width * 3 / 2, _player1BuJiao->getContentSize().height / 2));
	// _player1BuJiao->addChild(temp1);
	// _player1BuJiao->setScale(0.7);
	// _player1BuJiao->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player1BuJiao, 1);

	// _player2BuJiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
	// temp1->setPosition(Vec2(_player2BuJiao->getContentSize().width * 3 / 2, _player2BuJiao->getContentSize().height / 2));
	// _player2BuJiao->addChild(temp1);
	// _player2BuJiao->setScale(0.7);
	// _player2BuJiao->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player2BuJiao, 1);
	//
	// _player3BuJiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
	// temp1->setPosition(Vec2(_player3BuJiao->getContentSize().width * 3 / 2, _player3BuJiao->getContentSize().height / 2));
	// _player3BuJiao->addChild(temp1);
	// _player3BuJiao->setScale(0.7);
	// _player3BuJiao->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player3BuJiao, 1);
	////叫地主
	// 
	// _player1Jiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
	// temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
	// temp1->setPosition(Vec2(_player1Jiao->getContentSize().width * 3 / 2, _player1Jiao->getContentSize().height / 2));
	// temp2->setPosition(Vec2(_player1Jiao->getContentSize().width * 5 / 2, _player1Jiao->getContentSize().height / 2));
	// _player1Jiao->addChild(temp1);
	// _player1Jiao->addChild(temp2);
	// _player1Jiao->setScale(0.7);
	// _player1Jiao->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player1Jiao, 1);

	// _player2Jiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
	// temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
	// temp1->setPosition(Vec2(_player2Jiao->getContentSize().width * 3 / 2, _player2Jiao->getContentSize().height / 2));
	// temp2->setPosition(Vec2(_player2Jiao->getContentSize().width * 5 / 2, _player2Jiao->getContentSize().height / 2));
	// _player2Jiao->addChild(temp1);
	// _player2Jiao->addChild(temp2);
	// _player2Jiao->setScale(0.7);
	// _player2Jiao->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player2Jiao, 1);

	// _player3Jiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
	// temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
	// temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
	// temp1->setPosition(Vec2(_player3Jiao->getContentSize().width * 3 / 2, _player3Jiao->getContentSize().height / 2));
	// temp2->setPosition(Vec2(_player3Jiao->getContentSize().width * 5 / 2, _player3Jiao->getContentSize().height / 2));
	// _player3Jiao->addChild(temp1);
	// _player3Jiao->addChild(temp2);
	// _player3Jiao->setScale(0.7);
	// _player3Jiao->setPosition(Vec2(visibleSize.width / 2, -visibleSize.height / 2));
	// this->addChild(_player3Jiao, 1);
	////玩家2牌背景
	auto _player2Card = Sprite::createWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_0card_b.png"));
	_player2Card->setScale(0.5);
	_player2Card->setPosition(Vec2(650, 300));
	this->addChild(_player2Card);
	//玩家3牌背景
	auto _player3Card = Sprite::createWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_0card_b.png"));
	_player3Card->setScale(0.5);
	_player3Card->setPosition(Vec2(150, 300));
	this->addChild(_player3Card);
	//玩家2牌数
	_player2CardNumber = Label::createWithSystemFont(StringUtils::format("%d", _player2->getCardNumber()), "Arial", 30);
	_player2CardNumber->setColor(Color3B::BLACK);
	_player2CardNumber->setPosition(_player2Card->getContentSize().width / 2, _player2Card->getContentSize().height / 2);
	_player2Card->addChild(_player2CardNumber);
	//玩家3牌数
	_player3CardNumber = Label::createWithSystemFont(StringUtils::format("%d", _player3->getCardNumber()), "Arial", 30);
	_player3CardNumber->setColor(Color3B::BLACK);
	_player3CardNumber->setPosition(_player3Card->getContentSize().width / 2, _player3Card->getContentSize().height / 2);
	_player3Card->addChild(_player3CardNumber);

	auto jiao = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_169.png");//叫
	auto di = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_171.png");//低
	auto zhu = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_172.png");//主
	auto jiao1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_169.png");//叫1
	jiao1->setScale(0.9f);
	auto di1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_171.png");//地1
	di1->setScale(0.9f);
	auto zhu1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_172.png");//主1
	zhu1->setScale(0.9f);
	auto normalJiaoBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌左背景
	auto normalJiaoBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌右背景
	auto selectedJiaoBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌左背景
	auto selectedJiaoBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌右背景

	normalJiaoBgR->runAction(FlipX::create(true));
	selectedJiaoBgR->runAction(FlipX::create(true));

	jiao->setPosition(Vec2(normalJiaoBgL->getContentSize().width / 2, normalJiaoBgL->getContentSize().height / 2));
	jiao1->setPosition(Vec2(selectedJiaoBgL->getContentSize().width / 2, selectedJiaoBgL->getContentSize().height / 2));

	di->setPosition(Vec2(normalJiaoBgL->getContentSize().width * 2 / 2, normalJiaoBgL->getContentSize().height / 2));
	di1->setPosition(Vec2(selectedJiaoBgL->getContentSize().width * 2 / 2, selectedJiaoBgL->getContentSize().height / 2));

	zhu->setPosition(Vec2(normalJiaoBgL->getContentSize().width * 3 / 2, normalJiaoBgL->getContentSize().height / 2));
	zhu1->setPosition(Vec2(selectedJiaoBgL->getContentSize().width * 3 / 2, selectedJiaoBgL->getContentSize().height / 2));

	normalJiaoBgR->setPosition(Vec2(normalJiaoBgL->getContentSize().width * 3 / 2, normalJiaoBgL->getContentSize().height / 2));
	selectedJiaoBgR->setPosition(Vec2(selectedJiaoBgL->getContentSize().width * 3 / 2, selectedJiaoBgL->getContentSize().height / 2));

	normalJiaoBgL->addChild(normalJiaoBgR);
	normalJiaoBgL->addChild(jiao);
	normalJiaoBgL->addChild(di);
	normalJiaoBgL->addChild(zhu);
	normalJiaoBgL->setScale(0.5);
	normalJiaoBgL->setContentSize(Size(normalJiaoBgL->getContentSize().width / 2, normalJiaoBgL->getContentSize().height / 2));

	selectedJiaoBgL->addChild(selectedJiaoBgR);
	selectedJiaoBgL->addChild(jiao1);
	selectedJiaoBgL->addChild(di1);
	selectedJiaoBgL->addChild(zhu1);
	selectedJiaoBgL->setScale(0.5);
	selectedJiaoBgL->setContentSize(Size(selectedJiaoBgL->getContentSize().width / 2, selectedJiaoBgL->getContentSize().height / 2));

	jiaoButton = MenuItemSprite::create(normalJiaoBgL, selectedJiaoBgL, CC_CALLBACK_0(GameScene::callLandlord, this));
	jiaoButton->setContentSize(Size(jiaoButton->getContentSize().width * 2, jiaoButton->getContentSize().height));

	auto qiang = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_170.png");//抢
	auto di2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_171.png");//低
	auto zhu2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_172.png");//主
	auto qiang1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_170.png");//叫1
	qiang1->setScale(0.9f);
	auto di3 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_171.png");//牌1
	di3->setScale(0.9f);
	auto zhu3 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_172.png");//牌1
	zhu3->setScale(0.9f);
	auto normalQiangBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌左背景
	auto normalQiangBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌右背景
	auto selectedQiangBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌左背景
	auto selectedQiangBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌右背景

	normalQiangBgR->runAction(FlipX::create(true));
	selectedQiangBgR->runAction(FlipX::create(true));

	qiang->setPosition(Vec2(normalQiangBgL->getContentSize().width / 2, normalQiangBgL->getContentSize().height / 2));
	qiang1->setPosition(Vec2(selectedQiangBgL->getContentSize().width / 2, selectedQiangBgL->getContentSize().height / 2));

	di2->setPosition(Vec2(normalQiangBgL->getContentSize().width * 2 / 2, normalQiangBgL->getContentSize().height / 2));
	di3->setPosition(Vec2(selectedQiangBgL->getContentSize().width * 2 / 2, selectedQiangBgL->getContentSize().height / 2));

	zhu2->setPosition(Vec2(normalQiangBgL->getContentSize().width * 3 / 2, normalQiangBgL->getContentSize().height / 2));
	zhu3->setPosition(Vec2(selectedQiangBgL->getContentSize().width * 3 / 2, selectedQiangBgL->getContentSize().height / 2));

	normalQiangBgR->setPosition(Vec2(normalQiangBgL->getContentSize().width * 3 / 2, normalQiangBgL->getContentSize().height / 2));
	selectedQiangBgR->setPosition(Vec2(selectedQiangBgL->getContentSize().width * 3 / 2, selectedQiangBgL->getContentSize().height / 2));

	normalQiangBgL->addChild(normalQiangBgR);
	normalQiangBgL->addChild(qiang);
	normalQiangBgL->addChild(di2);
	normalQiangBgL->addChild(zhu2);
	normalQiangBgL->setScale(0.5);
	normalQiangBgL->setContentSize(Size(normalQiangBgL->getContentSize().width / 2, normalQiangBgL->getContentSize().height / 2));

	selectedQiangBgL->addChild(selectedQiangBgR);
	selectedQiangBgL->addChild(qiang1);
	selectedQiangBgL->addChild(di3);
	selectedQiangBgL->addChild(zhu3);
	selectedQiangBgL->setScale(0.5);
	selectedQiangBgL->setContentSize(Size(selectedQiangBgL->getContentSize().width / 2, selectedQiangBgL->getContentSize().height / 2));

	qiangButton = MenuItemSprite::create(normalQiangBgL, selectedQiangBgL, CC_CALLBACK_0(GameScene::robLandlord, this));
	qiangButton->setContentSize(Size(qiangButton->getContentSize().width * 2, qiangButton->getContentSize().height));

	auto qiangSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_170.png");//抢
	auto buSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_167.png");//不
	auto qiangSprite1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_170.png");//抢1
	qiangSprite1->setScale(0.9f);
	auto buSprite1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_167.png");//不1
	buSprite1->setScale(0.9f);
	auto normalBuBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌左背景
	auto normalBuBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌右背景
	auto selectedBuBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌左背景
	auto selectedBuBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌右背景

	normalBuBgR->runAction(FlipX::create(true));
	selectedBuBgR->runAction(FlipX::create(true));

	qiangSprite->setPosition(Vec2(normalBuBgL->getContentSize().width * 3 / 2, normalBuBgL->getContentSize().height / 2));
	qiangSprite1->setPosition(Vec2(selectedBuBgL->getContentSize().width * 3 / 2, selectedBuBgL->getContentSize().height / 2));

	buSprite->setPosition(Vec2(normalBuBgL->getContentSize().width / 2, normalBuBgL->getContentSize().height / 2));
	buSprite1->setPosition(Vec2(selectedBuBgL->getContentSize().width / 2, selectedBuBgL->getContentSize().height / 2));

	normalBuBgR->setPosition(Vec2(normalBuBgL->getContentSize().width * 3 / 2, normalBuBgL->getContentSize().height / 2));
	selectedBuBgR->setPosition(Vec2(selectedBuBgL->getContentSize().width * 3 / 2, selectedBuBgL->getContentSize().height / 2));

	normalBuBgL->addChild(normalBuBgR);
	normalBuBgL->addChild(qiangSprite);
	normalBuBgL->addChild(buSprite);
	normalBuBgL->setScale(0.5);
	normalBuBgL->setContentSize(Size(normalBuBgL->getContentSize().width / 2, normalBuBgL->getContentSize().height / 2));

	selectedBuBgL->addChild(selectedBuBgR);
	selectedBuBgL->addChild(qiangSprite1);
	selectedBuBgL->addChild(buSprite1);
	selectedBuBgL->setScale(0.5);
	selectedBuBgL->setContentSize(Size(selectedBuBgL->getContentSize().width / 2, selectedBuBgL->getContentSize().height / 2));

	buqiangButton = MenuItemSprite::create(normalBuBgL, selectedBuBgL, CC_CALLBACK_0(GameScene::notRobLandlord, this));
	buqiangButton->setContentSize(Size(buqiangButton->getContentSize().width * 2, buqiangButton->getContentSize().height));

	auto jiaoSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_169.png");//叫
	auto buSprite2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_167.png");//不
	auto jiaoSprite1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_169.png");//叫1
	jiaoSprite1->setScale(0.9f);
	auto buSprite3 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_167.png");//不1
	buSprite3->setScale(0.9f);
	auto normalBuJiaoBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌左背景
	auto normalBuJiaoBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌右背景
	auto selectedBuJiaoBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌左背景
	auto selectedBuJiaoBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌右背景

	normalBuJiaoBgR->runAction(FlipX::create(true));
	selectedBuJiaoBgR->runAction(FlipX::create(true));

	jiaoSprite->setPosition(Vec2(normalBuJiaoBgL->getContentSize().width * 3 / 2, normalBuJiaoBgL->getContentSize().height / 2));
	jiaoSprite1->setPosition(Vec2(selectedBuJiaoBgL->getContentSize().width * 3 / 2, selectedBuJiaoBgL->getContentSize().height / 2));

	buSprite2->setPosition(Vec2(normalBuJiaoBgL->getContentSize().width / 2, normalBuJiaoBgL->getContentSize().height / 2));
	buSprite3->setPosition(Vec2(selectedBuJiaoBgL->getContentSize().width / 2, selectedBuJiaoBgL->getContentSize().height / 2));

	normalBuJiaoBgR->setPosition(Vec2(normalBuJiaoBgL->getContentSize().width * 3 / 2, normalBuJiaoBgL->getContentSize().height / 2));
	selectedBuJiaoBgR->setPosition(Vec2(selectedBuJiaoBgL->getContentSize().width * 3 / 2, selectedBuJiaoBgL->getContentSize().height / 2));

	normalBuJiaoBgL->addChild(normalBuJiaoBgR);
	normalBuJiaoBgL->addChild(jiaoSprite);
	normalBuJiaoBgL->addChild(buSprite2);
	normalBuJiaoBgL->setScale(0.5);
	normalBuJiaoBgL->setContentSize(Size(normalBuJiaoBgL->getContentSize().width / 2, normalBuJiaoBgL->getContentSize().height / 2));

	selectedBuJiaoBgL->addChild(selectedBuJiaoBgR);
	selectedBuJiaoBgL->addChild(jiaoSprite1);
	selectedBuJiaoBgL->addChild(buSprite3);
	selectedBuJiaoBgL->setScale(0.5);
	selectedBuJiaoBgL->setContentSize(Size(selectedBuJiaoBgL->getContentSize().width / 2, selectedBuJiaoBgL->getContentSize().height / 2));

	bujiaoButton = MenuItemSprite::create(normalBuJiaoBgL, selectedBuJiaoBgL, CC_CALLBACK_0(GameScene::notCallLandlord, this));
	bujiaoButton->setContentSize(Size(bujiaoButton->getContentSize().width * 2, bujiaoButton->getContentSize().height));

	auto chu = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_193.png");//出
	auto pai = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_194.png");//牌
	auto chu1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_193.png");//出1
	chu1->setScale(0.9f);
	auto pai1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_194.png");//牌1
	pai1->setScale(0.9f);
	auto normalChuBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_295.png");//出牌左背景
	auto normalChuBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_295.png");//出牌右背景
	auto selectedChuBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_296.png");//出牌左背景
	auto selectedChuBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_296.png");//出牌右背景

	normalChuBgR->runAction(FlipX::create(true));
	selectedChuBgR->runAction(FlipX::create(true));

	chu->setPosition(Vec2(normalChuBgL->getContentSize().width / 2, normalChuBgL->getContentSize().height / 2));
	chu1->setPosition(Vec2(selectedChuBgL->getContentSize().width / 2, selectedChuBgL->getContentSize().height / 2));

	pai->setPosition(Vec2(normalChuBgL->getContentSize().width * 3 / 2, normalChuBgL->getContentSize().height / 2));
	pai1->setPosition(Vec2(selectedChuBgL->getContentSize().width * 3 / 2, selectedChuBgL->getContentSize().height / 2));

	normalChuBgR->setPosition(Vec2(normalChuBgL->getContentSize().width * 3 / 2, normalChuBgL->getContentSize().height / 2));
	selectedChuBgR->setPosition(Vec2(selectedChuBgL->getContentSize().width * 3 / 2, selectedChuBgL->getContentSize().height / 2));

	normalChuBgL->addChild(normalChuBgR);
	normalChuBgL->addChild(chu);
	normalChuBgL->addChild(pai);
	normalChuBgL->setScale(0.5);
	normalChuBgL->setContentSize(Size(normalChuBgL->getContentSize().width / 2, normalChuBgL->getContentSize().height / 2));

	selectedChuBgL->addChild(selectedChuBgR);
	selectedChuBgL->addChild(chu1);
	selectedChuBgL->addChild(pai1);
	selectedChuBgL->setScale(0.5);
	selectedChuBgL->setContentSize(Size(selectedChuBgL->getContentSize().width / 2, selectedChuBgL->getContentSize().height / 2));

	chuButton = MenuItemSprite::create(normalChuBgL, selectedChuBgL, CC_CALLBACK_0(GameScene::pushCard, this));
	chuButton->setContentSize(Size(chuButton->getContentSize().width * 2, chuButton->getContentSize().height));
	//不出
	auto passSprite1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_167.png");//不
	auto passSprite2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_168.png");//出
	auto passSprite3 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_167.png");//不1
	passSprite3->setScale(0.9f);
	auto passSprite4 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_168.png");//出1
	passSprite4->setScale(0.9f);
	auto normalPassBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌左背景
	auto normalPassBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌右背景
	auto selectedPassBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌左背景
	auto selectedPassBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌右背景

	normalPassBgR->runAction(FlipX::create(true));
	selectedPassBgR->runAction(FlipX::create(true));

	passSprite1->setPosition(Vec2(normalPassBgL->getContentSize().width / 2, normalPassBgL->getContentSize().height / 2));
	passSprite3->setPosition(Vec2(selectedPassBgL->getContentSize().width / 2, selectedPassBgL->getContentSize().height / 2));

	passSprite2->setPosition(Vec2(normalPassBgL->getContentSize().width * 3 / 2, normalPassBgL->getContentSize().height / 2));
	passSprite4->setPosition(Vec2(selectedPassBgL->getContentSize().width * 3 / 2, selectedPassBgL->getContentSize().height / 2));

	normalPassBgR->setPosition(Vec2(normalPassBgL->getContentSize().width * 3 / 2, normalPassBgL->getContentSize().height / 2));
	selectedPassBgR->setPosition(Vec2(selectedPassBgL->getContentSize().width * 3 / 2, selectedPassBgL->getContentSize().height / 2));

	normalPassBgL->addChild(normalPassBgR);
	normalPassBgL->addChild(passSprite1);
	normalPassBgL->addChild(passSprite2);
	normalPassBgL->setScale(0.5);
	normalPassBgL->setContentSize(Size(normalPassBgL->getContentSize().width / 2, normalPassBgL->getContentSize().height / 2));

	selectedPassBgL->addChild(selectedPassBgR);
	selectedPassBgL->addChild(passSprite3);
	selectedPassBgL->addChild(passSprite4);
	selectedPassBgL->setScale(0.5);
	selectedPassBgL->setContentSize(Size(selectedPassBgL->getContentSize().width / 2, selectedPassBgL->getContentSize().height / 2));
	passButton = MenuItemSprite::create(normalPassBgL, selectedPassBgL, CC_CALLBACK_0(GameScene::pass, this, _player1));
	passButton->setContentSize(Size(passButton->getContentSize().width * 2, passButton->getContentSize().height));
	//提示
	auto hintSprite1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_191.png");//ti
	auto hintSprite2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_192.png");//shi
	auto hintSprite3 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_191.png");//ti
	hintSprite3->setScale(0.9f);
	auto hintSprite4 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_192.png");//shi
	hintSprite4->setScale(0.9f);
	auto normalHintBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌左背景
	auto normalHintBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_285.png");//出牌右背景
	auto selectedHintBgL = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌左背景
	auto selectedHintBgR = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_286.png");//出牌右背景

	normalHintBgR->runAction(FlipX::create(true));
	selectedHintBgR->runAction(FlipX::create(true));

	hintSprite1->setPosition(Vec2(normalHintBgL->getContentSize().width / 2, normalHintBgL->getContentSize().height / 2));
	hintSprite3->setPosition(Vec2(selectedHintBgL->getContentSize().width / 2, selectedHintBgL->getContentSize().height / 2));

	hintSprite2->setPosition(Vec2(normalHintBgL->getContentSize().width * 3 / 2, normalHintBgL->getContentSize().height / 2));
	hintSprite4->setPosition(Vec2(selectedHintBgL->getContentSize().width * 3 / 2, selectedHintBgL->getContentSize().height / 2));

	normalHintBgR->setPosition(Vec2(normalHintBgL->getContentSize().width * 3 / 2, normalHintBgL->getContentSize().height / 2));
	selectedHintBgR->setPosition(Vec2(selectedHintBgL->getContentSize().width * 3 / 2, selectedHintBgL->getContentSize().height / 2));

	normalHintBgL->addChild(normalHintBgR);
	normalHintBgL->addChild(hintSprite1);
	normalHintBgL->addChild(hintSprite2);
	normalHintBgL->setScale(0.5);
	normalHintBgL->setContentSize(Size(normalHintBgL->getContentSize().width / 2, normalHintBgL->getContentSize().height / 2));

	selectedHintBgL->addChild(selectedHintBgR);
	selectedHintBgL->addChild(hintSprite3);
	selectedHintBgL->addChild(hintSprite4);
	selectedHintBgL->setScale(0.5);
	selectedHintBgL->setContentSize(Size(selectedHintBgL->getContentSize().width / 2, selectedHintBgL->getContentSize().height / 2));
	hintButton = MenuItemSprite::create(normalHintBgL, selectedHintBgL, CC_CALLBACK_0(GameScene::hint, this, _player1));
	hintButton->setContentSize(Size(hintButton->getContentSize().width * 2, hintButton->getContentSize().height));
	//
	chuButton->setPosition(Vec2(visibleSize.width * 6 / 9 - 36, visibleSize.height * 2 / 5));
	passButton->setPosition(Vec2(visibleSize.width * 3 / 9 - 5, visibleSize.height * 2 / 5));
	hintButton->setPosition(Vec2(visibleSize.width * 4 / 9 + 3, visibleSize.height * 2 / 5));

	jiaoButton->setPosition(Vec2(visibleSize.width * 4 / 9 - 40, visibleSize.height * 2 / 5));
	qiangButton->setPosition(Vec2(visibleSize.width * 4 / 9 - 40, visibleSize.height * 2 / 5));
	buqiangButton->setPosition(Vec2(visibleSize.width * 6 / 9 - 70, visibleSize.height * 2 / 5));
	bujiaoButton->setPosition(Vec2(visibleSize.width * 6 / 9 - 70, visibleSize.height * 2 / 5));

	auto menu = Menu::create(chuButton, passButton, hintButton, NULL);
	auto qiangMenu = Menu::create(qiangButton, buqiangButton, NULL);
	auto jiaoMenu = Menu::create(jiaoButton, bujiaoButton, NULL);
	/*menu->alignItemsHorizontally();*/
	/*menu->setPosition(Vec2(visibleSize.width * 3 / 8, visibleSize.height *2/ 5));*/
	menu->setPosition(Vec2::ZERO);
	qiangMenu->setPosition(Vec2::ZERO);
	jiaoMenu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1, 10);//button tag =10
	this->addChild(jiaoMenu, 1, 10);
	this->addChild(qiangMenu, 1, 10);
	//chuButton->setEnabled(false);

	chuButton->setEnabled(false);
	passButton->setEnabled(false);
	hintButton->setEnabled(false);
	qiangButton->setEnabled(false);
	jiaoButton->setEnabled(false);
	bujiaoButton->setEnabled(false);
	buqiangButton->setEnabled(false);

	chuButton->setVisible(false);
	passButton->setVisible(false);
	hintButton->setVisible(false);
	qiangButton->setVisible(false);
	jiaoButton->setVisible(false);
	bujiaoButton->setVisible(false);
	buqiangButton->setVisible(false);

	//_currentPlayer = _player1;//玩家1先出牌

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	//时钟检测回调
	this->schedule(schedule_selector(GameScene::testTime), 1.0f);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	if (1/*rand() % 3 == 0*/)
	{
		jiaoButton->setEnabled(true);             //启用叫地主按钮
		bujiaoButton->setEnabled(true);

		jiaoButton->setVisible(true);
		bujiaoButton->setVisible(true);

		_currentPlayer = _player1;
		updateClock(_currentPlayer, 15);
	}
	else if (rand() % 3 == 1)
	{
		_currentPlayer = _player2;
		updateClock(_currentPlayer, 15);

		if (rand() % 10 > 5)
			this->runAction(Sequence::create(DelayTime::create(2.0f),
				CallFunc::create(CC_CALLBACK_0(GameScene::callLandlord, this)), NULL));
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f),
				CallFunc::create(CC_CALLBACK_0(GameScene::notCallLandlord, this)), NULL));
	}
	else
	{
		_currentPlayer = _player3;
		updateClock(_currentPlayer, 15);

		if (rand() % 10 > 5)
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::callLandlord, this)), NULL));
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notCallLandlord, this)), NULL));
	}

	return true;
}

bool GameScene::initData()
{
    _cardType = CardType::NOTYPE;
	_cardArrayNumber=0;
	_cardLength = 0;
	_passTimes = 0;
	_isPass = false;

	_gameRule = new GameRule();

	_prePlayer1BuChu = NULL;
	_prePlayer2BuChu = NULL;
	_prePlayer3BuChu = NULL;


	//不抢
	 _player1NotRob=NULL;
	 _player2NotRob = NULL;
	 _player3NotRob = NULL;
	//抢地主
	 _player1Rob = NULL;
	 _player2Rob = NULL;
	 _player3Rob = NULL;
	//不叫
	 _player1NotCall = NULL;
	 _player2NotCall = NULL;
	 _player3NotCall = NULL;
	//叫地主
	_player1Call = NULL;
	 _player2Call = NULL;
	 _player3Call = NULL;

	_currentPlayer = NULL;
	_callLandlord = NULL;
	_clock = NULL;

	_player1 = Player::create(playerType::PLAYER_1);
	_player2 = Player::create(playerType::PLAYER_2);
	_player3 = Player::create(playerType::PLAYER_3);
	
	_player1->setAI(false);
	_player2->setAI(true);
	_player3->setAI(true);

	this->addChild(_player1);
	this->addChild(_player2);
	this->addChild(_player3);
	_currentCard.clear();

	bujiaoTimes = 0;
	return true;
}
void GameScene::showCard()
{
	_player1->arrangeCard();
	_player2->arrangeCard();
	_player3->arrangeCard();
	_player1->showCard();
	_player2->showCard();
	_player3->showCard();
}
//发牌
void GameScene::sendCard()
{
	for (auto i=0;i<51;i++ )
	{
		if (i < 17)
			_player1->getCard(_vCard.at(i));
		else if (i >= 17 && i<=33)
			_player2->getCard(_vCard.at(i));
		else
			_player3->getCard(_vCard.at(i));
	}
}
//洗牌
void GameScene::shuffleCard()
{
	
	srand((unsigned int)time(NULL));
	for (int i = 53; i >0; i--)
	{
		int j = rand() % i;
		_vCard.swap(_vCard.at(i), _vCard.at(j));
	}
}

void GameScene::createCard()
{
	for (int i = 1; i <= 13; i++)
	{
		auto cardHeart = Card::createCard( i, CardColor::RED, CardFlower::HEART, CardOwner::FARM);
		_vCard.pushBack(cardHeart);
		auto cartDiamond = Card::createCard( i, CardColor::RED, CardFlower::DIAMOND, CardOwner::FARM);
		_vCard.pushBack(cartDiamond);
		auto cardSpade = Card::createCard( i, CardColor::BLACK, CardFlower::SPADE, CardOwner::FARM);
		_vCard.pushBack(cardSpade);
		auto cardClub = Card::createCard( i, CardColor::BLACK, CardFlower::CLUB, CardOwner::FARM);
		_vCard.pushBack(cardClub);
	}
	auto joker1 = Card::createCard( 14, CardColor::BLACK, CardFlower::NONE, CardOwner::FARM);
	auto joker2 = Card::createCard( 15, CardColor::RED, CardFlower::NONE, CardOwner::FARM);
	_vCard.pushBack(joker1);
	_vCard.pushBack(joker2);
}

void GameScene::newGame()
{
	createCard();
	shuffleCard();
	sendCard();
	showCard();
}

void GameScene::restartGame()
{
	this->removeAllChildrenWithCleanup(true);
	 _vCard.clear();
	 _player1 = NULL;
	 _player2 = NULL;
	 _player3 = NULL;
	//上一轮出的牌
	 _prePlayer1Card.clear();
	 _prePlayer2Card.clear();
	 _prePlayer3Card.clear();
	//上一轮的不出
	 _prePlayer1BuChu = NULL;
	 _prePlayer2BuChu = NULL;
	 _prePlayer3BuChu = NULL;
	////当前出的牌
	 _currentCard.clear();
	//当前出牌的人
	 _currentPlayer = NULL;
	 delete _gameRule;
	 _gameRule = NULL;
	//当前出牌的类型
	//当前出牌类型

	 _player2CardNumber = NULL;
	 _player3CardNumber = NULL;
	  chuButton = NULL;
	 passButton = NULL;
	 hintButton = NULL;
	 jiaoButton = NULL;
	 qiangButton = NULL;
	 buqiangButton = NULL;
	 bujiaoButton = NULL;
	 while (!wantLandlord.empty())
		 wantLandlord.pop();
	 _callLandlord = NULL;//叫地主玩家
	 bujiaoTimes =0;
	 this->runAction(Sequence::create(DelayTime::create(1.0f),CallFunc::create([&]() {init(); }),NULL));
	 /*init();*/
}

void GameScene::pushCard()
{
	/*log("_currentCard.size 1= %d", _currentPlayer->getCurrentCard().size());*/
	if (_currentPlayer == _player1)                      //删除玩家2上一次的牌
	{
		if (_prePlayer2Card.size() != 0)
		{
			for (auto card : _prePlayer2Card)
			{
				card->runAction(RemoveSelf::create(true));
			}
			_prePlayer2Card.clear();
		}
		if (_prePlayer2BuChu != NULL)                         //删除玩家2上一次的不出
		{
			_prePlayer2BuChu->removeFromParentAndCleanup(true);
			_prePlayer2BuChu = NULL;
		}
	}
	else if (_currentPlayer == _player2)                //删除玩家3上一次的牌
	{
		if (_prePlayer3Card.size() != 0)
		{
			for (auto card : _prePlayer3Card)
			{
				card->runAction(RemoveSelf::create(true));
			}
			_prePlayer3Card.clear();
		}
		if (_prePlayer3BuChu != NULL)                //删除玩家3上一次的不出
		{
			_prePlayer3BuChu->removeFromParentAndCleanup(true);
			_prePlayer3BuChu = NULL;
		}	
	}
	else                                               //删除玩家1上一次的牌
	{
		if (_prePlayer1Card.size() != 0)
		{
			for (auto card : _prePlayer1Card)
			{
				card->runAction(RemoveSelf::create(true));
			}
			_prePlayer1Card.clear();
		}
		if (_prePlayer1BuChu != NULL)                   //删除玩家1上一次的不出
		{
			_prePlayer1BuChu->removeFromParentAndCleanup(true);
			_prePlayer1BuChu = NULL;
		}
	}
	if (!_isPass)//没过
	{
		/*for (auto i = 0; i < _currentPlayer->getCurrentCard().size(); i++)
			log("%d", _currentPlayer->getCurrentCard().at(i)->getCardNumber());*/
			//    牌符合规则，且比别人的大
			if (_currentPlayer == _player1)
			{
				if (_gameRule->isLegal(_currentPlayer->getCurrentCard()) && _gameRule->isLargerCard(_cardLength, _cardType, _cardArrayNumber, _currentPlayer->getCurrentCard(), _gameRule->getCardType(), _gameRule->getCardArrayNumber()))
				{
					/*log("_currentCard.size 2= %d", _currentPlayer->getCurrentCard().size());*/
					/*std::sort(_currentPlayer->getCurrentCard().begin(), _currentPlayer->getCurrentCard().end(), GameRule::largerCard);*/
					_cardType = _gameRule->getCardType();
					_cardArrayNumber = _gameRule->getCardArrayNumber();
					_cardLength = _gameRule->getCardLength();
				}
				//出的牌不合理
				else   //牌不合理
				{
					auto sp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_282.png");
					auto sp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_287.png");
					auto sp3 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_283.png");
					sp2->setAnchorPoint(Vec2(0, 1.0 / 2));
					sp2->setPosition(Vec2(sp1->getContentSize().width, sp1->getContentSize().height / 2));
					sp1->addChild(sp2);
					sp3->setAnchorPoint(Vec2(0, 1.0 / 2));
					sp3->setPosition(Vec2(sp2->getContentSize().width, sp2->getContentSize().height / 2));
					sp2->addChild(sp3);
					this->addChild(sp1,3);
					sp1->setPosition(Vec2(200, 50));
					sp1->runAction(Sequence::create(FadeOut::create(2.0f), RemoveSelf::create(), NULL));
					sp2->runAction(FadeOut::create(2.0f));
					sp3->runAction(FadeOut::create(2.0f));
					return;
				}
			}

		if (_currentPlayer != _player1)
		{
			_cardType = _currentPlayer->getGameRule()->getCardType();
			_cardArrayNumber = _currentPlayer->getGameRule()->getCardArrayNumber();
			_cardLength = _currentPlayer->getGameRule()->getCardLength();
		}
		if (_currentPlayer == _player1)
			log("-----------_player1: cardType %d   cardArrayNUm   %d cardLength %d  ",_cardType,_cardArrayNumber,_cardLength);
		else if (_currentPlayer == _player2)
			log("-----------_player2: cardType %d   cardArrayNUm   %d cardLength %d  ", _cardType, _cardArrayNumber, _cardLength);
		else if (_currentPlayer == _player3)
			log("-----------_player3: cardType %d   cardArrayNUm   %d cardLength %d  ", _cardType, _cardArrayNumber, _cardLength);
		_currentCard.clear();
		//当前出的牌
		_currentCard = _currentPlayer->getCurrentCard();
		//添加本次出的牌
		if (_currentPlayer == _player1)
		{
			_prePlayer1Card = _currentCard;
			log("prePlayer1Card size:%d", _prePlayer1Card.size());
		}
		else if (_currentPlayer == _player2)
		{
			_prePlayer2Card = _currentCard;
			log("prePlayer2Card size:%d", _prePlayer2Card.size());
		}
		else
		{
			_prePlayer3Card = _currentCard;
			log("prePlayer3Card size:%d", _prePlayer3Card.size());
		}

		/*log("CurrentPlayer: %d pushCard ,Length: %d,CardType: %d ,CardArraynumber: %d", _currentPlayer->getPlayerType(), _gameRule->getCardLength(), _cardType, _cardArrayNumber);*/

		//出牌的位置
		double posStart = 0;
		if (_currentPlayer->getCurrentCard().size() <= 8)
			posStart = (cardSizeX*cardScale*0.4*0.33*((int)_currentPlayer->getCurrentCard().size() / 2));
		else
			posStart = (cardSizeX*cardScale*0.4*0.33*((int)(8) / 2));
		for (int i = 0; i < (_currentPlayer->getCurrentCard()).size(); i++)
		{
			(_currentPlayer->getCurrentCard()).at(i)->removeFromParentAndCleanup(false);
			this->addChild((_currentPlayer->getCurrentCard()).at(i));
		}
		for (int i = 0; i < (_currentPlayer->getCurrentCard()).size(); i++)
		{
			if (i < 8)
			{
				if (_currentPlayer == _player1)
				{
					((_currentPlayer->getCurrentCard()).at(i))->runAction(Sequence::create(FadeOut::create(0.0f),
						ScaleTo::create(0.0f, 0.4f),
						MoveTo::create(0.3f, Vec2(370 - posStart + i*1.0 / 5 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 230)),
						FadeIn::create(0.0f),
						/*RemoveSelf::create(true),*/
						NULL));
				}/* CallFuncN::create([](Node*card) {	((Card*)card)->removeFromParent(); log("123%d",card->getCardNumber()); }), NULL)*/
				else  if (_currentPlayer == _player2)
				{
					((_currentPlayer->getCurrentCard()).at(i))->runAction(Sequence::create(Show::create(), FadeOut::create(0.0f),
						ScaleTo::create(0.0f, 0.4f),
						MoveTo::create(0.3f, Vec2(550 - posStart + i*1.0 / 5 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 300)),
						FadeIn::create(0.0f),
						/*RemoveSelf::create(true),*/
						NULL));
				}
				else
				{
					((_currentPlayer->getCurrentCard()).at(i))->runAction(Sequence::create(Show::create(), FadeOut::create(0.0f),
						ScaleTo::create(0.0f, 0.4f),
						MoveTo::create(0.3f, Vec2(230 + i*1.0 / 5 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 300)),
						FadeIn::create(0.0f),
						/*RemoveSelf::create(true),*/
						NULL));
				}
				//if (_currentPlayer->getCurrentCard().at(i)->getCardNumber() < 14)
				//	_currentPlayer->getCurrentCard().at(i)->getChildByTag(CardBody::FLOWER)->runAction(Sequence::create(FadeOut::create(0.5f),
				//		FadeIn::create(0.5),
				//		/*RemoveSelf::create(true),*/
				//		NULL));
				//_currentPlayer->getCurrentCard().at(i)->getChildByTag(CardBody::NUMBER)->runAction(Sequence::create(FadeOut::create(0.5f),
				//	FadeIn::create(0.5),
				//	///*RemoveSelf::create(true),*/
				//	NULL));
			}
			else
			{
				if (_currentPlayer == _player1)
				{
					((_currentPlayer->getCurrentCard()).at(i))->runAction(Sequence::create(FadeOut::create(0.0f),
						ScaleTo::create(0.0f, 0.4f),
						MoveTo::create(0.3f, Vec2(370 - posStart + (i - 8)*1.0 / 5 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 230 - 1.0 / 2 * _currentPlayer->getCurrentCard().at(i)->getContentSize().height*0.4)),
						FadeIn::create(0.0f),
						/*RemoveSelf::create(true),*/
						NULL));/* CallFuncN::create([](Node*card) {	((Card*)card)->removeFromParent(); log("123%d",card->getCardNumber()); }), NULL)*/
				}
				else if (_currentPlayer == _player2)
				{
					((_currentPlayer->getCurrentCard()).at(i))->runAction(Sequence::create(Show::create(), FadeOut::create(0.0f),
						ScaleTo::create(0.0f, 0.4f),
						MoveTo::create(0.3f, Vec2(550 - posStart + (i - 8)*1.0 / 5 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 300 - 1.0 / 2 * _currentPlayer->getCurrentCard().at(i)->getContentSize().height)),
						FadeIn::create(0.0f),
						/*RemoveSelf::create(true),*/
						NULL));
				}
				else
				{
					((_currentPlayer->getCurrentCard()).at(i))->runAction(Sequence::create(Show::create(), FadeOut::create(0.0f),
						ScaleTo::create(0.0f, 0.4f),
						MoveTo::create(0.3f, Vec2(230 + (i - 8)*1.0 / 5 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 300 - 1.0 / 2 * _currentPlayer->getCurrentCard().at(i)->getContentSize().height)),
						FadeIn::create(0.0f),
						/*RemoveSelf::create(true),*/
						NULL));
				}
				//if (_currentPlayer->getCurrentCard().at(i)->getCardNumber() < 14)
				//	_currentPlayer->getCurrentCard().at(i)->getChildByTag(CardBody::FLOWER)->runAction(Sequence::create(FadeOut::create(0.5f),
				//		FadeIn::create(0.5),
				//		/*RemoveSelf::create(true),*/
				//		NULL));
				//_currentPlayer->getCurrentCard().at(i)->getChildByTag(CardBody::NUMBER)->runAction(Sequence::create(FadeOut::create(0.5f),
				//	FadeIn::create(0.5),
				//	///*RemoveSelf::create(true),*/
				//	NULL));
			}
		}
		/*for (int i = 0; i < (_currentPlayer->getCurrentCard()).size(); i++)
		{
		_currentPlayer->getCurrentCard().at(i)->setScale(0.5f);
		if(i<8)
		_currentPlayer->getCurrentCard().at(i)->setPosition(Vec2(300 + i*1.0 / 6 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width,200));
		else
		_currentPlayer->getCurrentCard().at(i)->setPosition(Vec2(300 + (i-8)*1.0 / 6 * _currentPlayer->getCurrentCard().at(i)->getContentSize().width, 200-1.0/2*_currentPlayer->getCurrentCard().at(i)->getContentSize().height));


		/*log("_currentCard.size 3= %d", _currentPlayer->getCurrentCard().size());*/
		_currentPlayer->pushCard();  //出牌

		if (_currentPlayer == _player2)           //更新显示的牌的数字
		{
			_player2CardNumber->setString(StringUtils::format("%d", _player2->getVCard().size()));
		}
		else if (_currentPlayer == _player3)
		{
			_player3CardNumber->setString(StringUtils::format("%d", _player3->getVCard().size()));
		}

		//更换出牌玩家
		if (_currentPlayer == _player1)
		{
			chuButton->setEnabled(false);
			passButton->setEnabled(false);
			hintButton->setEnabled(false);

			chuButton->setVisible(false);
			passButton->setVisible(false);
			hintButton->setVisible(false);

			this->getChildByTag(CLOCKSPRITE)->runAction(FadeOut::create(0.1f));
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER2X, PLAYER2Y));

			log("LUNdao Player2");
			changePlayer(_player2);

			if (_cardType != CardType::NOTYPE)// 之前有人出牌
			{
				if (_player2->findFitCard(_cardType, _cardArrayNumber, _cardLength)) // 能管上
				{
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					_passTimes = 0;
					this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
					/*if (_currentPlayer == _player2)*/
					/*log("player2");*/
				}
				else // 管不上
				{
					_player2->getCurrentCard().clear();
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(10);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					pass(_player2);
				}

			}
			else    //之前没有认出牌
			{
				((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
				this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
				hint(_player2);
			}
		}
		else if (_currentPlayer == _player2)
		{
			this->getChildByTag(CLOCKSPRITE)->runAction(FadeOut::create(0.1f));
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER3X, PLAYER3Y));

			log("LUNdao Player3");
			changePlayer(_player3);
			if (_cardType != CardType::NOTYPE)// 之前有人出牌
			{
				if (_player3->findFitCard(_cardType, _cardArrayNumber, _cardLength))// 能管上
				{
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					_passTimes = 0;
					this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
				}
				else  // pass
				{
					_player3->getCurrentCard().clear();
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(10);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					pass(_player3);
				}
			}
			else
			{
				((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
				this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
				hint(_player3);
			}
		}
		else  //轮到玩家1
		{
			this->getChildByTag(CLOCKSPRITE)->runAction(FadeOut::create(0.1f));
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER1X2, PLAYER1Y2));

			chuButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
				[&]() { chuButton->setEnabled(true); chuButton->setVisible(true); }), NULL));
			passButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
				[&]() { passButton->setEnabled(true); passButton->setVisible(true); }), NULL));
			hintButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
				[&]() { hintButton->setEnabled(true); hintButton->setVisible(true); }), NULL));

			log("LUNdao Player1");
			changePlayer(_player1);
			if (_cardType != CardType::NOTYPE)// 之前有人出牌
			{
				Vector<Card*> t = _player1->getCurrentCard();//保存之前选的牌
				if (!_player1->findFitCard(_cardType, _cardArrayNumber, _cardLength))// 不能管上，显示没有大过大家的牌
				{
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(10);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					auto cannotSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_249.png");
					cannotSprite->setPosition(Vec2(300, 50));
					this->addChild(cannotSprite,3);
					cannotSprite->setVisible(false);
					cannotSprite->runAction(Sequence::create(/*DelayTime::create(2.0f),*/Show::create(), FadeOut::create(3.0f), RemoveSelf::create(true), NULL));
					//将出牌,提示按钮设为禁用
					chuButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
						[&]() { chuButton->setEnabled(false); chuButton->setVisible(false); }), NULL));
					hintButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
						[&]() { hintButton->setEnabled(false); hintButton->setVisible(false); }), NULL));
				}
				else
				{
					_player1->getCurrentCard().clear();
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
				}
				_player1->getCurrentCard() = t;//恢复选择的牌
			}
			else
			{    //禁用不出和提示
				passButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
					[&]() { passButton->setEnabled(false); passButton->setVisible(false); }), NULL));
				hintButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
					[&]() { hintButton->setEnabled(false); hintButton->setVisible(false); }), NULL));
				((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
				this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
			}
		}
	}
	else//过
	{
		if (_currentPlayer == _player1)
		{
			_prePlayer1BuChu = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");
			auto chuSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_02.png");
			chuSprite->setPosition(Vec2(_prePlayer1BuChu->getContentSize().width, 0));
			chuSprite->setAnchorPoint(Vec2(0, 0));
			_prePlayer1BuChu->addChild(chuSprite);
			_prePlayer1BuChu->setPosition(400, 250);
			_prePlayer1BuChu->setScale(0.7f);
			this->addChild(_prePlayer1BuChu);
			//_prePlayer1BuChu->setVisible(false);
			//chuSprite->setVisible(false);
			//_prePlayer1BuChu->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ Show::create(), NULL));
			//chuSprite->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ Show::create(),  NULL));
		}
		else if (_currentPlayer == _player2)
		{
			_prePlayer2BuChu = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");
			auto chuSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_02.png");
			chuSprite->setPosition(Vec2(_prePlayer2BuChu->getContentSize().width, 0));
			chuSprite->setAnchorPoint(Vec2(0, 0));
			_prePlayer2BuChu->addChild(chuSprite);
			_prePlayer2BuChu->setPosition(540, 300);
			_prePlayer2BuChu->setScale(0.7f);
			this->addChild(_prePlayer2BuChu);
			//_prePlayer2BuChu->setVisible(false);
			//chuSprite->setVisible(false);
			//_prePlayer2BuChu->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ Show::create(),/* FadeOut::create(1.0f), RemoveSelf::create(true),*/ NULL));
			//chuSprite->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ Show::create()/*, FadeOut::create(1.0f), RemoveSelf::create(true)*/, NULL));
		}
		else
		{
			_prePlayer3BuChu = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");
			auto chuSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_02.png");
			chuSprite->setPosition(Vec2(_prePlayer3BuChu->getContentSize().width, 0));
			chuSprite->setAnchorPoint(Vec2(0, 0));
			_prePlayer3BuChu->addChild(chuSprite);
			_prePlayer3BuChu->setPosition(230, 300);
			_prePlayer3BuChu->setScale(0.7f);
			this->addChild(_prePlayer3BuChu);
			//_prePlayer3BuChu->setVisible(false);
			//chuSprite->setVisible(false);
			//_prePlayer3BuChu->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ Show::create(), NULL));
			//chuSprite->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ Show::create(), NULL));
		}
		_isPass = false;
		if (_passTimes == 2)  
		{
			_cardType = CardType::NOTYPE;
			_cardArrayNumber = 0;
			_cardLength = 0;
			_passTimes = 0;
		}
		//更换出牌玩家
		if (_currentPlayer == _player1)
		{
			this->getChildByTag(CLOCKSPRITE)->runAction(FadeOut::create(0.1f));
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER2X, PLAYER2Y));

			chuButton->setEnabled(false);
			passButton->setEnabled(false);
			hintButton->setEnabled(false);

			chuButton->setVisible(false);
			passButton->setVisible(false);
			hintButton->setVisible(false);
			
			for (auto card : _player1->getCurrentCard())                //清除玩家1选择的牌
			{
				card->setColor(Color3B(255, 255, 255));
				/*log("s-%d", card->getCardNumber());*/
				card->setPosition(card->getPosition() + Vec2(0, -20));
				card->setCardTouched(false);
			}
			_player1->getCurrentCard().clear();

			log("LUNdao p  Player2");
			changePlayer(_player2);
			if (_cardType != CardType::NOTYPE)// 之前有人出牌
			{
				if (_player2->findFitCard(_cardType, _cardArrayNumber, _cardLength)) // 能管上
				{
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					_passTimes = 0;
					this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
				}
				else // 管不上
				{
					_player2->getCurrentCard().clear();
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(10);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					pass(_player2);
				}
			}
			else
			{
				((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
				this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
				hint(_player2);
			}
		}
		else if (_currentPlayer == _player2)
		{
			this->getChildByTag(CLOCKSPRITE)->runAction(FadeOut::create(0.1f));
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER3X, PLAYER3Y));
			log("LUNdao p  Player3");
			changePlayer(_player3);
			if (_cardType != CardType::NOTYPE)// 之前有人出牌
			{
				if (_player3->findFitCard(_cardType, _cardArrayNumber, _cardLength))// 能管上
				{
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					_passTimes = 0;
					this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
				}
				else  // pass
				{
					_player3->getCurrentCard().clear();
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(10);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					pass(_player3);
				}
			}
			else
			{
				((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
				this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
				hint(_player3);
			}
		}
		else  
		{
			this->getChildByTag(CLOCKSPRITE)->runAction(FadeOut::create(0.1f));
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER1X2, PLAYER1Y2));

			chuButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
				[&]() { chuButton->setEnabled(true);chuButton->setVisible(true); }), NULL));
			passButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
				[&]() { passButton->setEnabled(true); passButton->setVisible(true); }), NULL));
			hintButton->runAction(Sequence::create(/*DelayTime::create(2.0f), */CallFunc::create(
				[&]() { hintButton->setEnabled(true); hintButton->setVisible(true); }), NULL));

			log("LUNdao p  Player1");
			changePlayer(_player1);
			if (_cardType != CardType::NOTYPE)// 之前有人出牌
			{
				Vector<Card*> t = _player1->getCurrentCard();//保存之前选的牌
				if (!_player1->findFitCard(_cardType, _cardArrayNumber, _cardLength))// 不能管上，显示没有大过大家的牌
				{
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(10);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
					auto cannotSprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_249.png");
					cannotSprite->setPosition(Vec2(300, 100));
					this->addChild(cannotSprite);
					cannotSprite->setVisible(false);
					cannotSprite->runAction(Sequence::create(/*DelayTime::create(2.0f),*/Show::create(),FadeOut::create(1.0f), RemoveSelf::create(true), NULL));
					//将出牌,提示按钮设为禁用
					chuButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
						[&]() { chuButton->setEnabled(false); chuButton->setVisible(false); }), NULL));
					hintButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
						[&]() { hintButton->setEnabled(false); hintButton->setVisible(false); }), NULL));
				}
				else
				{
					_player1->getCurrentCard().clear();
					((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
					this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.1f));
				}
				_player1->getCurrentCard() = t;//恢复选择的牌
			}
			else
			{
				//禁用不出和提示
				passButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
					[&]() { passButton->setEnabled(false); passButton->setVisible(false); }), NULL));
				hintButton->runAction(Sequence::create(/*DelayTime::create(2.0f),*/ CallFunc::create(
					[&]() { hintButton->setEnabled(false); hintButton->setVisible(false); }), NULL));
				((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(30);
				this->getChildByTag(CLOCKSPRITE)->runAction(FadeIn::create(0.2f));
			}
		}
	}
}

void GameScene::pass(Player* currentPlayer)
{
	_isPass = true;
	_passTimes++;
	if (currentPlayer != _player1)//不是玩家1 
		this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
	else
	{
		pushCard();
	}
}

void GameScene::hint(Player* player)
{
	if (player == GameScene::_player1)
	{
		for (auto card : player->getCurrentCard())
		{
			card->setColor(Color3B(255, 255, 255));
			/*log("s-%d", card->getCardNumber());*/
			card->setPosition(card->getPosition() + Vec2(0, -20));
			card->setCardTouched(false);
		}
		player->getCurrentCard().clear();
		player->findFitCard(_cardType, _cardArrayNumber, _cardLength);

		for (auto card : player->getCurrentCard())
		{
			card->setColor(Color3B(255, 255, 255));

			card->setPosition(card->getPosition() + Vec2(0, 20));
			card->setCardTouched(true);
		}
	}
	else
	{
		if (player->getVCard().size() == 20 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_PAIRS, 0, 20))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 16 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_PAIRS, 0, 15))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 12 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_PAIRS, 0, 10))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		 else if (player->getVCard().size() == 20 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS, 0, 20))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 16 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS, 0, 16))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 12 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS, 0, 12))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 8 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS, 0, 8))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 18 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS, 0, 18))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 15 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS, 0, 15))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 12 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS, 0, 12))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 9 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS, 0, 9))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 6 && player->findFitCard(CardType::SEQUENCE_OF_TRIPLETS, 0, 6))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() == 20 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 20))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 18 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 18))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 16 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 16))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 14 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 14))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 12 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 12))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 10 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 10))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 8 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 8))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 6 && player->findFitCard(CardType::SEQUENCE_OF_PAIRS, 0, 6))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 12 && player->findFitCard(CardType::SEQUENCE, 0, 12))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 11 && player->findFitCard(CardType::SEQUENCE, 0, 11))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 10 && player->findFitCard(CardType::SEQUENCE, 0, 10))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 9 && player->findFitCard(CardType::SEQUENCE, 0, 9))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 8 && player->findFitCard(CardType::SEQUENCE, 0, 8))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 7 && player->findFitCard(CardType::SEQUENCE, 0, 7))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 6 && player->findFitCard(CardType::SEQUENCE, 0, 6))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 5 && player->findFitCard(CardType::SEQUENCE, 0, 5))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 5 && player->findFitCard(CardType::TRIPLET_WITH_ATTACHED_PAIRS, 0, 5))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 4 && player->findFitCard(CardType::TRIPLET_WITH_ATTACHED_CARDS, 0, 4))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 1 && player->findFitCard(CardType::SINGLE, 0, 1))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		else if (player->getVCard().size() >= 2 && player->findFitCard(CardType::PAIR, 0, 2))
		{
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::pushCard, this)), NULL));
		}
		
	}
}

void GameScene::changePlayer(Player *player)
{
		_currentPlayer = player;
}

void GameScene::selectLandlord(Player *player)
{
	player->setLandlord(true);
}

void GameScene::callLandlord()      //叫地主
{
	
	if(_currentPlayer==_player1)
	{
		addChooseTypeSprite(_currentPlayer, _player1Call, ChooseType::CALL_LANDLORD);
		if (bujiaoTimes == 2)
		{
			removeLabel(_player1, 1.0f);        //1s后删除叫地主
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player1);         //选择player1 为地主
			addLandlordCard();                //添加地主牌

			this->runAction(Sequence::create(DelayTime::create(1.0f),
				CallFunc::create([&]() {

				jiaoButton->setEnabled(false);      //禁用叫地主按钮
				bujiaoButton->setEnabled(false);

				jiaoButton->setVisible(false);
				bujiaoButton->setVisible(false);

				chuButton->setEnabled(true);         //启用出牌按钮
				passButton->setEnabled(true);
				hintButton->setEnabled(true);

				chuButton->setVisible(true);
				passButton->setVisible(true);
				hintButton->setVisible(true);
			}), NULL));
		
			_currentPlayer = _player1;          
			updateClock(_currentPlayer, 30,1.0f); // 1s后更新时钟位置      
			return;
		}

		_callLandlord = _player1;
		wantLandlord.push(_player1);//玩家1放入队列
		changePlayer(_player2);
		updateClock(_currentPlayer, 15 );

		jiaoButton->setEnabled(false);            //禁用叫地主按钮
		bujiaoButton->setEnabled(false);

		jiaoButton->setVisible(false);
		bujiaoButton->setVisible(false);

		if (rand() % 10 > 5)                //玩家2
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢

	}
	else if (_currentPlayer == _player2)
	{
		addChooseTypeSprite(_currentPlayer, _player2Call, ChooseType::CALL_LANDLORD);
		if (bujiaoTimes == 2)
		{
			removeLabel(_player2, 1.0f);        //1s后删除叫地主
			removeLabel(_player1, 1.0f);
			removeLabel(_player3, 1.0f);
			
			selectLandlord(_player2);         //选择player2 为地主
			addLandlordCard();                //添加地主牌

			_currentPlayer = _player2;
			updateClock(_currentPlayer, 30, 1.0f); // 1s后更新时钟位置 

			hint(_player2);
			return;
		}

		_callLandlord = _player2;
        wantLandlord.push(_player2);
		changePlayer(_player3);
		updateClock(_currentPlayer, 15);

		if (rand() % 10 > 5)                //玩家3
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢
	}
	else
	{
		addChooseTypeSprite(_currentPlayer, _player3Call, ChooseType::CALL_LANDLORD);
		if (bujiaoTimes == 2)
		{
			removeLabel(_player3, 1.0f);        //1s后删除叫地主
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);

           
			selectLandlord(_player3);         //选择player3 为地主
			addLandlordCard();                //添加地主牌

            _currentPlayer = _player3;
			updateClock(_currentPlayer, 30, 1.0f); // 1s后更新时钟位置 
	
			hint(_player3);                    //游戏开始
			return;
		}

		_callLandlord = _player3;
		wantLandlord.push(_player3);
		changePlayer(_player1);
		updateClock(_currentPlayer, 15); // 更新时钟位置 

		qiangButton->setEnabled(true);   //启用抢地主按钮
		buqiangButton->setEnabled(true);

		qiangButton->setVisible(true);
		buqiangButton->setVisible(true);
	}
}

void GameScene::robLandlord()        //抢地主
{
	if (_currentPlayer == _player1)
	{
		addChooseTypeSprite(_currentPlayer, _player1Rob, ChooseType::ROB_LANDLORD);

		if (wantLandlord.front() == _player1)
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player1);         //选择player1 为地主
			addLandlordCard();                //添加地主牌

			this->runAction(Sequence::create(DelayTime::create(1.0f),
				CallFunc::create([&]() {

				qiangButton->setEnabled(false);      //禁用抢地主按钮
				buqiangButton->setEnabled(false);

				qiangButton->setVisible(false);
				buqiangButton->setVisible(false);

				chuButton->setEnabled(true);         //启用出牌按钮
				passButton->setEnabled(true);
				hintButton->setEnabled(true);

				chuButton->setVisible(true);
				passButton->setVisible(true);
				hintButton->setVisible(true);
			}), NULL));

			_currentPlayer = _player1;
			updateClock(_currentPlayer, 30, 1.0f);      //更新时钟位置
			return;
		}
		wantLandlord.push(_player1);

		if (_player2->getIsWantLandlord() == false)//player2没叫，player3叫了，
		{

			changePlayer(_player3);
			updateClock(_currentPlayer, 15);
			removeLabel(_player3);
		}
		else
		{
			changePlayer(_player2);
			updateClock(_currentPlayer, 15);
			removeLabel(_player2);
		}

		qiangButton->setEnabled(false);     //禁用抢地主按钮
		buqiangButton->setEnabled(false);

		qiangButton->setVisible(false);
		buqiangButton->setVisible(false);

		if (rand() % 10 > 5)                //玩家2或3
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢

	}
	else if (_currentPlayer == _player2)
	{
		addChooseTypeSprite(_currentPlayer, _player2Rob, ChooseType::ROB_LANDLORD);

		if (wantLandlord.front() == _player2)
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player2);          //选择player2为地主
			addLandlordCard();                //添加地主牌

			_currentPlayer = _player2;
			updateClock(_currentPlayer, 30, 1.0f);

			hint(_player2);   //提示出牌
			return;
		}
		wantLandlord.push(_player2);
		if (_player3->getIsWantLandlord() == false)//player3没叫，player1叫了，
		{
			changePlayer(_player1);
			updateClock(_currentPlayer, 15);
			removeLabel(_player1);

			qiangButton->setEnabled(true);      //启用抢地主按钮
			buqiangButton->setEnabled(true);

			qiangButton->setVisible(true);
			buqiangButton->setVisible(true);
		}
		else
		{
			changePlayer(_player3);
			updateClock(_currentPlayer, 15);
			removeLabel(_player3);

			if (rand() % 10 > 5)                //玩家3
				this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
			else
				this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢
		}
	}
	else
	{
		addChooseTypeSprite(_currentPlayer, _player3Rob, ChooseType::ROB_LANDLORD);
		if (wantLandlord.front() == _player3)
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player3);          //选择player3为地主
			addLandlordCard();                //添加地主牌

			_currentPlayer = _player3;
			updateClock(_currentPlayer, 30, 1.0f);

			hint(_player3);   //提示出牌
			return;
		}

		wantLandlord.push(_player3);

		if (_player1->getIsWantLandlord() == false)//player1没叫，player2叫了，
		{
			changePlayer(_player2);
			updateClock(_currentPlayer, 15);
			removeLabel(_player2);

			if (rand() % 10 > 5)                //玩家2
				this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
			else
				this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢
		}
		else                      //玩家1
		{
			changePlayer(_player1);
			updateClock(_currentPlayer, 15);
			removeLabel(_player1);

			qiangButton->setEnabled(true);          //启用抢地主
			buqiangButton->setEnabled(true);

			qiangButton->setVisible(true);
			buqiangButton->setVisible(true);
		}
	}
}

void GameScene::notCallLandlord()   //不叫
{
	
	
	if (_currentPlayer == _player1)
	{
		addChooseTypeSprite(_currentPlayer, _player1NotCall, ChooseType::NOTCALL_LANDLORD);

		//_player1->setIsWantLandlord(false);//设为不要地主
		bujiaoTimes++;
		if (bujiaoTimes == 3)
		{
			restartGame();          //重新开始
			return;
		}                 

		changePlayer(_player2);
		updateClock(_currentPlayer, 15);

		jiaoButton->setEnabled(false);     //禁用叫地主
		bujiaoButton->setEnabled(false);

		jiaoButton->setVisible(false);
		bujiaoButton->setVisible(false);

		if (rand() % 10 > 5)                //玩家2
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::callLandlord, this)), NULL));       //叫地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notCallLandlord, this)), NULL));   //不叫

	}
	else if (_currentPlayer == _player2)
	{
		addChooseTypeSprite(_currentPlayer, _player2NotCall, ChooseType::NOTCALL_LANDLORD);

		//_player2->setIsWantLandlord(false);//设为不要地主
		bujiaoTimes++;
		if (bujiaoTimes == 3)
		{
			restartGame();//重新开始
			return;
		}
		
		changePlayer(_player3);
		updateClock(_currentPlayer, 15);

		if (rand() % 10 > 5)                //玩家3
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::callLandlord, this)), NULL));       //叫地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notCallLandlord, this)), NULL));   //不叫
	}
	else
	{
		addChooseTypeSprite(_currentPlayer, _player3NotCall, ChooseType::NOTCALL_LANDLORD);

		//_player3->setIsWantLandlord(false);//设为不要地主
		bujiaoTimes++;

		if (bujiaoTimes == 3)
		{
			restartGame();//重新开始
			return;
		}

        changePlayer(_player1);
		updateClock(_currentPlayer, 15);

		jiaoButton->setEnabled(true);           //启用叫地主
		bujiaoButton->setEnabled(true);

		jiaoButton->setVisible(true);
		bujiaoButton->setVisible(true);
	}
}

void GameScene::notRobLandlord()  //不抢
{
	
	if (_currentPlayer == _player1)
	{
		addChooseTypeSprite(_currentPlayer, _player1NotRob, ChooseType::NOTROB_LANDLORD);

		qiangButton->setEnabled(false);                  //禁用抢地主按钮
		buqiangButton->setEnabled(false);

		qiangButton->setVisible(false);
		buqiangButton->setVisible(false);

		notWantLandlordTimes++;

		if (_player2->getIsWantLandlord() == false)//第一个人player2没叫地主，第二个人叫了
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player3);          //选择player3为地主
			addLandlordCard();                //添加地主牌

			changePlayer(_player3);
			updateClock(_currentPlayer, 30, 1.0f);
			hint(_player3);   //提示出牌
			return;
		}
		if (wantLandlord.front() == _player1 || notWantLandlordTimes == 2)//再次轮到player1不抢，或有两个人不抢
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(wantLandlord.back());          //选择最后一个抢地主的为地主
			addLandlordCard();                //添加地主牌

			if (wantLandlord.back() == _player2)
			{
				changePlayer(_player2);
				hint(_player2);
			}
			else
			{
				changePlayer(_player3);
				hint(_player3);
			}
			updateClock(_currentPlayer, 30, 1.0f);
			return;
		}

		changePlayer(_player2);
		updateClock(_currentPlayer, 15);
		removeLabel(_player2);

		if (rand() % 10 > 5)                //玩家2
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢

	}
	else if (_currentPlayer == _player2)
	{
		addChooseTypeSprite(_currentPlayer, _player2NotRob, ChooseType::NOTROB_LANDLORD);

		notWantLandlordTimes++;
		if (_player3->getIsWantLandlord() == false)//第一个player3人没叫地主，player1人叫了
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player1);          //选择player1为地主
			addLandlordCard();                //添加地主牌

			changePlayer(_player1);
			updateClock(_currentPlayer, 30, 1.0f);

			this->runAction(Sequence::create(DelayTime::create(1.0f),
				CallFunc::create([&]() {
				chuButton->setEnabled(true);         //启用出牌按钮
				passButton->setEnabled(true);
				hintButton->setEnabled(true);

				chuButton->setVisible(true);
				passButton->setVisible(true);
				hintButton->setVisible(true);
			}), NULL));

			return;
		}
		if (wantLandlord.front() == _player2 || notWantLandlordTimes == 2)//再次轮到player2不抢，或有两个人不抢
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(wantLandlord.back());          //选择最后一个抢地主的为地主
			addLandlordCard();                //添加地主牌

			if (wantLandlord.back() == _player3)
			{
				changePlayer(_player3);
				hint(_player3);
			}
			else
			{
				changePlayer(_player1);

				this->runAction(Sequence::create(DelayTime::create(1.0f),
					CallFunc::create([&]() {
					chuButton->setEnabled(true);         //启用出牌按钮
					passButton->setEnabled(true);
					hintButton->setEnabled(true);

					chuButton->setVisible(true);
					passButton->setVisible(true);
					hintButton->setVisible(true);
				}), NULL));
			}
			updateClock(_currentPlayer, 30, 1.0f);
			return;
		}
		
		changePlayer(_player3);
		updateClock(_currentPlayer, 15);
		removeLabel(_player3);

		if (rand() % 10 > 5)                //玩家3
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::robLandlord, this)), NULL));       //抢地主
		else
			this->runAction(Sequence::create(DelayTime::create(2.0f), CallFunc::create(CC_CALLBACK_0(GameScene::notRobLandlord, this)), NULL));   //不抢
	}
	else
	{
		addChooseTypeSprite(_currentPlayer, _player3NotRob, ChooseType::NOTROB_LANDLORD);
		notWantLandlordTimes++;

		if (_player1->getIsWantLandlord() == false)//第一个player1人没叫地主，player2叫了
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(_player2);          //选择player2为地主
			addLandlordCard();                //添加地主牌


			changePlayer(_player2);
			updateClock(_currentPlayer, 30, 1.0f);
			hint(_player2);   //提示出牌
			return;
		}
		if (wantLandlord.front() == _player3 || notWantLandlordTimes == 2)//再次轮到player3不抢，或有两个人不抢
		{
			removeLabel(_player1, 1.0f);
			removeLabel(_player2, 1.0f);
			removeLabel(_player3, 1.0f);

			selectLandlord(wantLandlord.back());          //选择最后一个抢地主的为地主
			addLandlordCard();                //添加地主牌

			if (wantLandlord.back() == _player2)
			{
				changePlayer(_player2);
				hint(_player2);
			}
			else
			{
				changePlayer(_player1);

				this->runAction(Sequence::create(DelayTime::create(1.0f),
					CallFunc::create([&]() {
					chuButton->setEnabled(true);         //启用出牌按钮
					passButton->setEnabled(true);
					hintButton->setEnabled(true);

					chuButton->setVisible(true);
					passButton->setVisible(true);
					hintButton->setVisible(true);
				}), NULL));
			}
			updateClock(_currentPlayer, 30, 1.0f);
			return;
		}
		changePlayer(_player1);
		updateClock(_currentPlayer, 15);
		removeLabel(_player1);

		qiangButton->setEnabled(true);       //启用抢地主按钮
		buqiangButton->setEnabled(true);

		qiangButton->setVisible(true);
		buqiangButton->setVisible(true);

	}
}


void GameScene::addLandlordCard()
{
	if (_player1->getLandlord())
	{
		for (int i = 0; i < _player1->getVCard().size(); ++i)
		{
			_player1->getVCard().at(i)->removeFromParent();
		}
		_player1->getCard(_vCard.at(51));
		_player1->getCard(_vCard.at(52));
		_player1->getCard(_vCard.at(53));
		_player1->arrangeCard();
		_player1->showCard();

		_vCard.at(51)->setPosition(_vCard.at(51)->getPosition() + Vec2(0, 20));
		_vCard.at(51)->runAction(MoveBy::create(0.5, Vec2(0, -20)));
		_vCard.at(52)->setPosition(_vCard.at(52)->getPosition() + Vec2(0, 20));
		_vCard.at(52)->runAction(MoveBy::create(0.5, Vec2(0, -20)));
		_vCard.at(53)->setPosition(_vCard.at(53)->getPosition() + Vec2(0, 20));
		_vCard.at(53)->runAction(MoveBy::create(0.5, Vec2(0, -20)));
	}
	else if (_player2->getLandlord())
	{
		for (int i = 0; i < _player2->getVCard().size(); ++i)
		{
			_player2->getVCard().at(i)->removeFromParent();
		}
		_player2->getCard(_vCard.at(51));
		_player2->getCard(_vCard.at(52));
		_player2->getCard(_vCard.at(53));
		_player2->arrangeCard();
		_player2->showCard();
		_player2CardNumber->setString(StringUtils::format("%d", _player2->getVCard().size()));
	}
	else
	{
		for (int i = 0; i < _player3->getVCard().size(); ++i)
		{
			_player3->getVCard().at(i)->removeFromParent();
		}
		_player3->getCard(_vCard.at(51));
		_player3->getCard(_vCard.at(52));
		_player3->getCard(_vCard.at(53));
		_player3->arrangeCard();
		_player3->showCard();
		_player3CardNumber->setString(StringUtils::format("%d", _player3->getVCard().size()));
	}
}

bool GameScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unusedEvent)
{
	/*if(_player1->getCurrentCard().size()>0)*/
	//log("0 player1 current size %d,%d", _player1->getCurrentCard().size(),_player1->getCurrentCard().at(0)->getCardNumber());
	_startTouchedID = -1;
	auto pos = touch->getLocation();
	for (int i = (int)_player1->getVCard().size() - 1; i >= 0; i--)
	{
		auto card = _player1->getVCard().at(i);
		auto cardPos = card->getPosition() - pos;
		
			if (cardPos.x >(-1.0 / 2 * card->getContentSize().width) && cardPos.x < (1.0 / 2 * card->getContentSize().width))
			{
				if (cardPos.y<(1.0 / 2 * card->getContentSize().height) && cardPos.y>(-1.0 / 2 * card->getContentSize().height))
				{
					_startTouchedID = i;
					_endTouchedID = i;
					card->setColor(Color3B(196, 196, 196));
					break;
				}
			}
		
	}
	if (_startTouchedID == -1)
		return false;
	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unusedEvent)
{
	auto pos = touch->getLocation();
	for (int i = (int)_player1->getVCard().size()-1; i >= 0 ; i--)
	{
		auto cardi = _player1->getVCard().at(i);
		auto cardPos = cardi->getPosition() - pos;
		
		if (cardPos.x > (-1.0 / 2 * cardi->getContentSize().width) && cardPos.x < (1.0 / 2 * cardi->getContentSize().width))
		{
			if (cardPos.y<(1.0 / 2 * cardi->getContentSize().height) && cardPos.y>(-1.0 / 2 * cardi->getContentSize().height))
			{

				_endTouchedID = i;
				if (_endTouchedID > _startTouchedID)
				{
					for (auto j = _startTouchedID; j <= _endTouchedID; j++)
					{
						auto card = _player1->getVCard().at(j);
						card->setColor(Color3B(196, 196, 196));
					}
					for (auto j = 0; j < _startTouchedID; j++)
					{
						auto card = _player1->getVCard().at(j);
						card->setColor(Color3B(255, 255, 255));
					}
					for (auto j = _endTouchedID + 1; j < _player1->getVCard().size(); j++)
					{
						auto card = _player1->getVCard().at(j);
						card->setColor(Color3B(255, 255, 255));
					}
				}
				else
				{
					for (auto j = _endTouchedID; j <= _startTouchedID; j++)
					{
						auto card = _player1->getVCard().at(j);
						card->setColor(Color3B(196, 196, 196));
					}
					for (auto j = 0; j < _endTouchedID; j++)
					{
						auto card = _player1->getVCard().at(j);
						card->setColor(Color3B(255, 255, 255));
					}
					for (auto j = _startTouchedID + 1; j < _player1->getVCard().size(); j++)
					{
						auto card = _player1->getVCard().at(j);
						card->setColor(Color3B(255, 255, 255));
					}
				}
				break;

			}
		}
	}
}

void GameScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unusedEvent)
{
	/*log("1 player1 current size %d", _player1->getCurrentCard().size());
	log("startTouchedID = %d,endTouchedID = %d", _startTouchedID, _endTouchedID);*/
	/*log("%d  %d", touch->getLocation().x, touch->getLocation().y);*/
	auto pos = touch->getLocation();
	if (_endTouchedID > _startTouchedID)
	{
		for (auto i = _startTouchedID; i <= _endTouchedID; i++)
		{
			auto card = _player1->getVCard().at(i);
			card->setColor(Color3B(255, 255, 255));
			if (card->getCardTouched())
			{
				/*log("s-%d", card->getCardNumber());*/
				card->setPosition(card->getPosition() + Vec2(0, -20));
				card->setCardTouched(false);

				_player1->getCurrentCard().eraseObject(card);
			}
			else
			{
				card->setPosition(card->getPosition() + Vec2(0, 20));
				card->setCardTouched(true);
				_player1->getCurrentCard().pushBack(card);
			}
		}
	}
	else
	{
		/*log("2 player1 current size %d", _player1->getCurrentCard().size());*/
		for (auto i = _endTouchedID; i <= _startTouchedID; i++)
		{
			auto card = _player1->getVCard().at(i);
			card->setColor(Color3B(255, 255, 255));
			if (card->getCardTouched())
			{
				/*log("s-%d", card->getCardNumber());*/
				card->setPosition(card->getPosition() + Vec2(0, -20));
				card->setCardTouched(false);

				_player1->getCurrentCard().eraseObject(card);
				/*log("%d", _player1->getCurrentCard().size());*/
			}
			else
			{
				/*log("d-%d", card->getCardNumber());*/
				card->setPosition(card->getPosition() + Vec2(0, 20));
				card->setCardTouched(true);
				_player1->getCurrentCard().pushBack(card);
				/*log("%d", _player1->getCurrentCard().size());*/
			}
		}
		/*log("3 player1 current size %d", _player1->getCurrentCard().size());*/
	}

}

void GameScene::testTime(float t)
{
	if (_clock->getTime() == 0)
	{
		if (_player1->getLandlord() == false&&_player2->getLandlord() == false && _player3->getLandlord() == false)
		{
			if (wantLandlord.empty())
				notCallLandlord();
			else
				notRobLandlord();
		}
		else
		{
			pass(_currentPlayer);
		}
	}
}

void GameScene::removeLabel(Player * player, float delayTime)
{
	if (player == _player1)
	{
		removeLabel(_player1NotCall, delayTime);
		removeLabel(_player1NotRob, delayTime);
		removeLabel(_player1Rob, delayTime);
		removeLabel(_player1Call, delayTime);
	}
	else if (player == _player2)
	{
		removeLabel(_player2NotCall, delayTime);
		removeLabel(_player2NotRob, delayTime);
		removeLabel(_player2Rob, delayTime);
		removeLabel(_player2Call, delayTime);
	}
	else
	{
		removeLabel(_player3NotCall, delayTime);
		removeLabel(_player3NotRob, delayTime);
		removeLabel(_player3Rob, delayTime);
		removeLabel(_player3Call, delayTime);
	}
}
void GameScene::removeLabel(cocos2d::Sprite*& sprite, float delayTime)
{
	if (sprite != NULL)                     
	{
		sprite->runAction(Sequence::create(DelayTime::create(delayTime), CallFunc::create([&]() {
			sprite->removeFromParentAndCleanup(true);
		}), NULL));
	}
}
//更新时钟位置
void GameScene::updateClock(Player * player, int time, float delayTime)
{
	
	this->getChildByTag(CLOCKSPRITE)->runAction(Sequence::create(DelayTime::create(delayTime),
		FadeOut::create(0.1f),
		CallFunc::create([=]() {
		if (player == _player2)
		{
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER2X, PLAYER2Y));
		}
		else if (player == _player3)
		{
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER3X, PLAYER3Y));
		}
		else if (_player1->getLandlord() == false && _player2->getLandlord() == false && _player3->getLandlord() == false)
		{
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER1X, PLAYER1Y));
		}
		else
		{
			this->getChildByTag(CLOCKSPRITE)->setPosition(Vec2(PLAYER1X2, PLAYER1Y2));
		}
		((Clock*)this->getChildByTag(CLOCKSPRITE))->setTime(time);
	}),
		FadeIn::create(0.1f),
		NULL));
}

void GameScene::addChooseTypeSprite(Player * player, cocos2d::Sprite *& sprite, ChooseType type)
{
	Sprite* temp1;
	Sprite* temp2;
	if (type == ChooseType::CALL_LANDLORD)
	{
		sprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
		temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
		temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
		temp1->setPosition(Vec2(sprite->getContentSize().width * 3 / 2, sprite->getContentSize().height / 2));
		temp2->setPosition(Vec2(sprite->getContentSize().width * 5 / 2, sprite->getContentSize().height / 2));
		sprite->addChild(temp1);
		sprite->addChild(temp2);
		sprite->setScale(0.7);
		if (player == _player1)
			sprite->setPosition(Vec2(400, 250));
		else if (player == _player2)
			sprite->setPosition(Vec2(540, 300));
		else
			sprite->setPosition(Vec2(230, 300));
		this->addChild(sprite, 1);
	}
	else if (type == ChooseType::NOTCALL_LANDLORD)
	{
		sprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
		temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_04.png");//叫
		temp1->setPosition(Vec2(sprite->getContentSize().width * 3 / 2, sprite->getContentSize().height / 2));
		sprite->addChild(temp1);
		sprite->setScale(0.7);
		if (player == _player1)
			sprite->setPosition(Vec2(400, 250));
		else if (player == _player2)
			sprite->setPosition(Vec2(540, 300));
		else
			sprite->setPosition(Vec2(230, 300));
		this->addChild(sprite, 1);
	}
	else if (type == ChooseType::ROB_LANDLORD)
	{
		sprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
		temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_07.png");//地
		temp2 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_08.png");//主
		temp1->setPosition(Vec2(sprite->getContentSize().width * 3 / 2, sprite->getContentSize().height / 2));
		temp2->setPosition(Vec2(sprite->getContentSize().width * 5 / 2, sprite->getContentSize().height / 2));
		sprite->addChild(temp1);
		sprite->addChild(temp2);
		sprite->setScale(0.7);
		if (player == _player1)
			sprite->setPosition(Vec2(400, 250));
		else if (player == _player2)
			sprite->setPosition(Vec2(540, 300));
		else
			sprite->setPosition(Vec2(230, 300));
		this->addChild(sprite, 1);
	}
	else
	{
		sprite = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_01.png");//不
		temp1 = Sprite::createWithSpriteFrameName("HLDDZ_MainGame0_2x_42_03.png");//抢
		temp1->setPosition(Vec2(sprite->getContentSize().width * 3 / 2, sprite->getContentSize().height / 2));
		sprite->addChild(temp1);
		sprite->setScale(0.7);
		if (player == _player1)
			sprite->setPosition(Vec2(400, 250));
		else if (player == _player2)
			sprite->setPosition(Vec2(540, 300));
		else
			sprite->setPosition(Vec2(230, 300));
		this->addChild(sprite, 1);
	}
}
