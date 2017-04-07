#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"
#include "Card.h"
#include"Player.h"
#include"GameRule.h"
#include"Clock.h"

#define CLOCKSPRITE 20

#define PLAYER1X 390
#define PLAYER1Y 200
#define PLAYER2X 550
#define PLAYER2Y 300
#define PLAYER3X 220
#define PLAYER3Y 300
#define PLAYER1X2 425
#define PLAYER1Y2 192
const int fitTime = 20;
enum ChooseType
{
	CALL_LANDLORD,    //叫地主
    NOTCALL_LANDLORD,//不叫
	ROB_LANDLORD,    //抢地主
	NOTROB_LANDLORD  // 不抢
};
class GameScene :public cocos2d::Layer
{
public:
	GameScene();
	~GameScene();
	static cocos2d::Scene* createScene();
    virtual bool init();
	bool initData();
	CREATE_FUNC(GameScene);
	void menuCallback(cocos2d::Ref * sender);
	void showCard();
    //发牌
	void sendCard(); 
    //洗牌
	void  shuffleCard();
    //创建一副牌
	void createCard();  
	//新游戏
	void newGame();
	//重新开始
	void restartGame();
	//出牌
	void pushCard();
	
	//不出
	void pass(Player* currentPlayer);
	void hint(Player* currentPlayer);
	//换出牌的玩家
	void changePlayer(Player* player);
	//选地主
    void selectLandlord(Player*player);
	//叫地主回调
	void callLandlord();
	//抢地主回调
	void robLandlord();
	//不叫
	void notCallLandlord();
	//不抢
	void notRobLandlord();
	//地主添加牌
	void addLandlordCard();
	//移除抢地主，叫地主，不叫，不抢等
	void removeLabel(Player* player,float delayTime=0.0f);
	
	void removeLabel(cocos2d::Sprite*& sprite, float delayTime=0.0f);
	//更新时钟位置
	void updateClock(Player* player, int time,float delayTime=0.0f);
	//添加抢地主，叫地主，不叫，不抢等
    //type是四种类型之一
	void addChooseTypeSprite(Player* player, cocos2d::Sprite*& sprite, ChooseType type );

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);
	//检测时间是否到零
	void testTime(float t);
private:
	cocos2d::Vector<Card*> _vCard;
	Player* _player1;
	Player* _player2;
	Player* _player3;
	//上一轮出的牌
	cocos2d::Vector<Card*> _prePlayer1Card;
	cocos2d::Vector<Card*> _prePlayer2Card;
	cocos2d::Vector<Card*> _prePlayer3Card;
	//上一轮的不出
	cocos2d::Sprite* _prePlayer1BuChu;
	cocos2d::Sprite* _prePlayer2BuChu;
	cocos2d::Sprite* _prePlayer3BuChu;
	//不抢
	cocos2d::Sprite* _player1NotRob;
	cocos2d::Sprite* _player2NotRob;
	cocos2d::Sprite* _player3NotRob;
	//抢地主
	cocos2d::Sprite* _player1Rob;
	cocos2d::Sprite* _player2Rob;
	cocos2d::Sprite* _player3Rob;
	//不叫
	cocos2d::Sprite* _player1NotCall;
	cocos2d::Sprite* _player2NotCall;
	cocos2d::Sprite* _player3NotCall;
	//叫地主
	cocos2d::Sprite* _player1Call; 
	cocos2d::Sprite* _player2Call;
	cocos2d::Sprite* _player3Call;
	//时钟
	Clock* _clock;
	////当前出的牌
	cocos2d::Vector<Card*> _currentCard;
	//当前出牌的人
	Player* _currentPlayer;
	GameRule* _gameRule;
	//当前出牌的类型
	//CardTypeArray* _cardTypeArray;
	//CardType _currentCardType;
	//触摸的牌
	int _startTouchedID;
	int _endTouchedID;
	//当前出牌类型
	CardType _cardType;
	//出的牌数字大小
	int _cardArrayNumber;
	//出的牌长
	int _cardLength;
	//pass的次数
	int _passTimes;
	//是否不出
	bool _isPass;
	//23玩家牌数
	cocos2d::Label* _player2CardNumber;
	cocos2d::Label* _player3CardNumber;

	cocos2d::MenuItem*  chuButton;
	cocos2d::MenuItem* passButton;
	cocos2d::MenuItem* hintButton;
	cocos2d::MenuItem* jiaoButton;
	cocos2d::MenuItem* qiangButton;
	cocos2d::MenuItem* buqiangButton;
	cocos2d::MenuItem* bujiaoButton;

	std::queue<Player*> wantLandlord;

	Player* _callLandlord;//叫地主玩家
	int bujiaoTimes;//不叫次数
	int notWantLandlordTimes;//不抢次数
};
#endif

