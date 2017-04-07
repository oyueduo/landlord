#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include"Card.h"
#include"GameRule.h"

enum playerType
{
	PLAYER_1,
	PLAYER_2,
	PLAYER_3
};
class Player: public cocos2d::Node
{
public:
	Player(playerType type);
	~Player();
	static Player* create(playerType type);
	//展示牌
	void showCard();
	bool init();
     //出牌
	void pushCard();     
    //获得牌
	void getCard(Card* card);
	//整理牌
	void arrangeCard();
	//讲牌空位补齐
	void fillEmptyCard();
	
	cocos2d::Vector<Card*>& getVCard() { return _vCard; }
	cocos2d::Vector<Card*>& getCurrentCard() { return _currentCard; }
	int getCardNumber() const
	{
		return _numberCard;
	}
	//找到合适的牌
	bool findFitCard(CardType cardType, int cardArrayNumber ,int cardLength);
	void setLandlord(bool isLandlord)
	{
		_isLandlord = isLandlord;
	}
	bool getLandlord()const
	{
		return _isLandlord;
	}
	void setAI(bool isAI)
	{
		_isAI = isAI;
	}
	bool getAI()
	{
		return _isAI;
	}
	void setPlayerType(playerType type)
	{
		_playerType = type;
	}
	playerType getPlayerType()const
	{
		return _playerType;
	}
	bool getIsWantLandlord() const
	{
		return _isWantLandlord;
	}
	void setIsWantLandlord(bool isWantLandlord)
	{
		_isWantLandlord = isWantLandlord;
	}
	GameRule* getGameRule() const
	{
		return _gameRule;
	}
private:
    //手牌
	cocos2d::Vector<Card*> _vCard;  
	//要出的牌
	cocos2d::Vector<Card*> _currentCard;
	//显示牌数目的图片
	cocos2d::Sprite* _spriteCardNumber;
	//手牌数
	int _numberCard;// ???????
	GameRule* _gameRule;
	//是否是地主
	bool _isLandlord;
	//是否是AI
	bool _isAI;
	playerType _playerType;
	//不想要地主,true 想要，false不想要，初始化为true
	bool _isWantLandlord; 
};

#endif
