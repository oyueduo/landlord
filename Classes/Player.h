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
	//չʾ��
	void showCard();
	bool init();
     //����
	void pushCard();     
    //�����
	void getCard(Card* card);
	//������
	void arrangeCard();
	//���ƿ�λ����
	void fillEmptyCard();
	
	cocos2d::Vector<Card*>& getVCard() { return _vCard; }
	cocos2d::Vector<Card*>& getCurrentCard() { return _currentCard; }
	int getCardNumber() const
	{
		return _numberCard;
	}
	//�ҵ����ʵ���
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
    //����
	cocos2d::Vector<Card*> _vCard;  
	//Ҫ������
	cocos2d::Vector<Card*> _currentCard;
	//��ʾ����Ŀ��ͼƬ
	cocos2d::Sprite* _spriteCardNumber;
	//������
	int _numberCard;// ???????
	GameRule* _gameRule;
	//�Ƿ��ǵ���
	bool _isLandlord;
	//�Ƿ���AI
	bool _isAI;
	playerType _playerType;
	//����Ҫ����,true ��Ҫ��false����Ҫ����ʼ��Ϊtrue
	bool _isWantLandlord; 
};

#endif
