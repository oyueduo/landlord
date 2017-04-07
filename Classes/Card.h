#ifndef __CARD_H__
#define __CARD_H__

#include "cocos2d.h"
const double cardScale = 0.75;
const double cardSizeX = 129;
const double cardSizeY = 167;
////0代表大牌，1代表小牌
//enum CardSize
//{
//	BIG_CARD,
//	SMALL_CARD
//};
//颜色0黑1红2金
enum CardColor
{
	BLACK,
	RED,
	GOLD
};
//牌的拥有者
enum CardOwner
{
	FARM,
	LANDLORD
};
//花色 0红心，1方块 2黑桃 3梅花 4空
enum CardFlower
{
	HEART,
	DIAMOND,
	SPADE,
	CLUB,
	NONE
};
enum CardBody
{
	BACKGROUND,
	NUMBER,
	FLOWER
};
class Card :public cocos2d::Sprite
{
public:
	Card();
	static Card* createCard( int number, CardColor color,CardFlower flower, CardOwner owner);
	virtual bool init();
	bool initData( int number, CardColor color,CardFlower flower, CardOwner owner);
	
	int getCardNumber()const;
	bool getCardTouched() const;
	void setCardTouched(bool touched);
private:

	cocos2d::Sprite* _flower;//花色
	cocos2d::Sprite* _number;//数字

	CardColor _cardColor;//数字和joker颜色
	CardFlower _cardFlower;//花色
	CardOwner _cardOwner;//y拥有者
	int _cardNumber;//牌的大小
	bool _touched;//是否被点击

};
#endif