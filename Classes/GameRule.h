#ifndef __GAMERULE_H__
#define __GAMERULE_H__

#include"cocos2d.h"
#include"Card.h"

enum CardType
{
	NOTYPE,
    ILLEGAL,
	SINGLE,
	PAIR,
	ROCKET,
	TRIPLET,
	BOMB,
	TRIPLET_WITH_ATTACHED_CARDS,
	TRIPLET_WITH_ATTACHED_PAIRS,
	QUAD_WITH_ATTACHED_CARDS,
	QUAD_WITH_ATTACHED_PAIRS,
	SEQUENCE,
	SEQUENCE_OF_PAIRS,
	SEQUENCE_OF_TRIPLETS,
	SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS,
	SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_PAIRS
};

const int card[] = { 0,12,13,1,2,3,4,5,6,7,8,9,10,11,14,15 };

class GameRule
{
public:
	GameRule();
	~GameRule();
	static bool lessCard(Card* first, Card* second);
	static bool largerCard(Card* first, Card* second);

	bool isLegal(cocos2d::Vector<Card*>& vCard);
	bool isLargerCard(int lengthCardLast,CardType lastCardType,int lastCardNumber, cocos2d::Vector<Card*>& vCardCurrent,CardType currentCardType,int currentCardNumber);

	bool isSingle(cocos2d::Vector<Card*>& vCard);
	bool isPair(cocos2d::Vector<Card*>&vCard);
	bool isPair(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector < Card* > ::iterator vEnd);
	bool isRocket(cocos2d::Vector<Card*>& vCard);
	bool isTriplet(cocos2d::Vector<Card*>& vCard);
	bool isTriplet(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd);
	bool isBomb(cocos2d::Vector<Card*>& vCard);
	bool isQuadWithAttachedCards(cocos2d::Vector<Card*>& vCard);
	bool isQuadWithAttachedPairs(cocos2d::Vector<Card*>& vCard);
	bool isBomb(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd);
	bool isTripletWithAnAttachedCard(cocos2d::Vector<Card*>& vCard);
	bool isTripletWithAnAttachedPair(cocos2d::Vector<Card*>& vCard);
	bool isSequence(cocos2d::Vector<Card*>& vCard);
	bool isSequenceOfPairs(cocos2d::Vector<Card*>& vCard);
	bool isSequenceOfTriplets(cocos2d::Vector<Card*>& vCard);
	bool isSequenceOfTriplets(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd);
	bool isSequenceOfTripletsWithAttachedCards(cocos2d::Vector<Card*>& vCard);
	bool isSequenceOfTripletsWithAttachedPairs(cocos2d::Vector<Card*>& vCard);
	CardType& getCardType();
	int& getCardArrayNumber();
	int& getCardLength();
private:
	CardType _cardType;
	int _cardArrayNumber;
	int _cardLength;
	
};

#endif 
