#include"GameRule.h"
#include"algorithm"

USING_NS_CC;

GameRule::GameRule()
{

}

GameRule::~GameRule()
{

}

bool  GameRule::lessCard(Card* first, Card* second)
{
	return  card[first->getCardNumber()] < card[second->getCardNumber()];
}

bool GameRule::largerCard(Card * first, Card * second)
{
	return card[first->getCardNumber()] > card[second->getCardNumber()];
}

bool GameRule::isLegal(Vector<Card*>& vCard)
{
	if (vCard.size() == 0)
		return false;
	sort(vCard.begin(), vCard.end(), lessCard);
	if (isSingle(vCard))
	{
		_cardType = CardType::SINGLE;
		_cardArrayNumber = (*vCard.begin())->getCardNumber();
		_cardLength = vCard.size();
		sort(vCard.begin(), vCard.end(), largerCard);
		return true;
	}
		if (isPair(vCard))
		{
			_cardType = CardType::PAIR;
			_cardArrayNumber = (*vCard.begin())->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isRocket(vCard))
		{
			_cardType = CardType::ROCKET;
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
			
		if (isTriplet(vCard))
		{
			_cardType = CardType::TRIPLET;
			_cardArrayNumber = (*vCard.begin())->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isBomb(vCard))
		{
			_cardType = CardType::BOMB;
			_cardArrayNumber = (*vCard.begin())->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isTripletWithAnAttachedCard(vCard))
		{
			_cardType = CardType::TRIPLET_WITH_ATTACHED_CARDS;
			_cardArrayNumber = (*(vCard.begin()+1))->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isTripletWithAnAttachedPair(vCard))
		{
			_cardType = CardType::TRIPLET_WITH_ATTACHED_PAIRS;
			_cardArrayNumber = (*(vCard.begin() + 2))->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isQuadWithAttachedCards(vCard))
		{
			_cardType = CardType::QUAD_WITH_ATTACHED_CARDS;
			_cardArrayNumber = (*(vCard.begin() + 2))->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isQuadWithAttachedPairs(vCard))
		{
			_cardType = CardType::QUAD_WITH_ATTACHED_PAIRS;
			_cardLength = vCard.size();
			if (isBomb(vCard.begin() + 4, vCard.begin() + 8) && isPair(vCard.begin(), vCard.begin() + 2) && isPair(vCard.begin() + 2, vCard.begin() + 4))
				_cardArrayNumber = (*(vCard.begin() + 6))->getCardNumber();
			else
				_cardArrayNumber = (*(vCard.begin() + 4))->getCardNumber();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isSequence(vCard))
		{
			_cardType = CardType::SEQUENCE;
			_cardArrayNumber = (*vCard.begin())->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isSequenceOfPairs(vCard))
		{
			_cardType = CardType::SEQUENCE_OF_PAIRS;
			_cardArrayNumber = (*vCard.begin())->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isSequenceOfTriplets(vCard))
		{
			_cardType = CardType::SEQUENCE_OF_TRIPLETS;
			_cardArrayNumber = (*vCard.begin())->getCardNumber();
			_cardLength = vCard.size();
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isSequenceOfTripletsWithAttachedCards(vCard))
		{
			_cardType = CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS;
			for (int i = 0; i <= vCard.size() / 4; i++)
			{
				if (isTriplet(vCard.begin() + i, (vCard.begin() + 3 + i)))
				{
					_cardArrayNumber = (*vCard.begin()+i)->getCardNumber();
					_cardLength = vCard.size();
					break;
				}
			}
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		if (isSequenceOfTripletsWithAttachedPairs(vCard))
		{
			_cardType = CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_PAIRS;
			for (int i = 0; i <= vCard.size() / 5; i++)
			{
				if (isTriplet(vCard.begin() + i * 2, vCard.begin() + 3 + i * 2))
				{
					_cardArrayNumber = (*vCard.begin() + i * 2)->getCardNumber();
					_cardLength = vCard.size();
					break;
				}
			}
			sort(vCard.begin(), vCard.end(), largerCard);
			return true;
		}
		sort(vCard.begin(), vCard.end(), largerCard);
	return false;
}

bool GameRule::isLargerCard(int lengthCardLast, CardType lastCardType, int lastCardNumber, cocos2d::Vector<Card*>& vCardCurrent, CardType currentCardType, int currentCardNumber)
{
	if (lastCardType == CardType::NOTYPE)
		return  true;
	if(lastCardType == currentCardType && card[currentCardNumber] > card[lastCardNumber] && lengthCardLast ==vCardCurrent.size())
	{
		return true;
	}
	if (currentCardType == CardType::BOMB || currentCardType == CardType::ROCKET)
		return true;
	return false;
}

bool GameRule::isSingle(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() == 1)
		return true;
	return false;
}

bool GameRule::isPair(cocos2d::Vector<Card*>&vCard) //    two cards of the same rank, from 3 (low)up to 2 (high), for example 3 - 3, A - A.
{
	if (vCard.size() == 2)
	{
		if (vCard.at(0)->getCardNumber() == vCard.at(1)->getCardNumber())
			return true;
	}
	return false;
}

bool GameRule::isPair(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd)
{
	if (vEnd - vBegin == 2)
	{
		if ((*vBegin)->getCardNumber() == (*(vBegin + 1))->getCardNumber())
			return true;
	}
	return false;
}

bool GameRule::isRocket(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() == 2)
	{
		if (vCard.at(0)->getCardNumber() == 14 && vCard.at(1)->getCardNumber() == 15)
			return true;
	}
	return false;
}

bool GameRule::isTriplet(cocos2d::Vector<Card*>& vCard)  // - three cards of the same rank, for example 9 - 9 - 9.
{
	if (vCard.size() == 3)
	{
		if (vCard.at(0)->getCardNumber() == vCard.at(1)->getCardNumber()&& vCard.at(1)->getCardNumber()==vCard.at(2)->getCardNumber())
		{
			return true;
		}
	}
	return false;
}

bool GameRule::isTriplet(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd)  // - three cards of the same rank, for example 9 - 9 - 9.
{
	if (vEnd - vBegin == 3)
	{
		if ((*vBegin)->getCardNumber() == (*(vBegin + 1))->getCardNumber() && (*vBegin)->getCardNumber() == (*(vBegin + 2))->getCardNumber())
		{
			return true;
		}
	}
	return false;
}

bool GameRule::isBomb(cocos2d::Vector<Card*>& vCard)// - four cards of the same rank.A bomb can beat everything except a rocket or a bomb with higher rank.
{
	if (vCard.size() == 4)
	{
		if (vCard.at(0)->getCardNumber() == vCard.at(1)->getCardNumber() && 
			vCard.at(0)->getCardNumber() == vCard.at(2)->getCardNumber() &&
			vCard.at(0)->getCardNumber()==vCard.at(3)->getCardNumber())
		{
			return true;
		}
	}
	return false;
}
//四带二
bool GameRule::isQuadWithAttachedCards(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() == 6)
	{
		if ((*(vCard.end() - 2))->getCardNumber() == 14 && (*(vCard.end() - 1))->getCardNumber() == 15)  //不能有两个Joker
			return false;
		if (isBomb(vCard.begin(), vCard.begin() + 4) && !isPair(vCard.begin() + 4, vCard.begin() + 6))
			return true;
		if (isBomb(vCard.begin() + 1, vCard.begin() + 5))
			return true;
		if (isBomb(vCard.begin() + 2, vCard.begin() + 6) && !isPair(vCard.begin(), vCard.begin() + 2))
			return true;
	}
	return false;
}
//四带两对
bool GameRule::isQuadWithAttachedPairs(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() == 8)
	{
		if ((*(vCard.end() - 2))->getCardNumber() == 14 && (*(vCard.end() - 1))->getCardNumber() == 15)  //不能有两个Joker
			return false;
		if (isBomb(vCard.begin(), vCard.begin() + 4) && isBomb(vCard.begin() + 4, vCard.begin() + 8))
			return false;
		if (isBomb(vCard.begin(), vCard.begin() + 4) && isPair(vCard.begin() + 4, vCard.begin() + 6) && isPair(vCard.begin() + 6, vCard.begin() + 8))
			return  true;
		if (isBomb(vCard.begin() + 2, vCard.begin() + 6) && isPair(vCard.begin(), vCard.begin() + 2) && isPair(vCard.begin() + 6, vCard.begin() + 8))
			return true;
		if (isBomb(vCard.begin() + 4, vCard.begin() + 8) && isPair(vCard.begin(), vCard.begin() + 2) && isPair(vCard.begin() + 2, vCard.begin() + 4))
			return true;
	}
	return false;
}

bool GameRule::isBomb(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd)  // - three cards of the same rank, for example 9 - 9 - 9.
{
	if (vEnd - vBegin == 4)
	{
		int number = (*vBegin)->getCardNumber();
		if (number == (*(vBegin + 1))->getCardNumber() && number == (*(vBegin + 2))->getCardNumber() && number == (*(vBegin + 3))->getCardNumber())
		{
			return true;
		}
	}
	return false;
}
//Triplet with an attached card- a triplet with a single card added,so for example 9-9-9-3 beats 8-8-8-A.
bool GameRule::isTripletWithAnAttachedCard(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() == 4)
	{
		if (isBomb(vCard))
			return false;
		if (isTriplet(vCard.begin(), vCard.begin() + 3))
			return true;
		if (isTriplet(vCard.begin() + 1, vCard.begin() + 4))
			return true;
	}
	return false;
}

bool GameRule::isTripletWithAnAttachedPair(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() == 5)
	{
		if (isTriplet(vCard.begin(), vCard.begin() + 3) && isPair(vCard.begin() + 3, vCard.begin() + 5))
			return true;
		if (isTriplet(vCard.begin() + 2, vCard.begin() + 5) && isPair(vCard.begin(), vCard.begin() + 2))
			return true;
	}
	return false;
}
//顺子
bool GameRule::isSequence(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() >= 5)
	{
		if ((*(vCard.end() - 1))->getCardNumber() == 2 || (*(vCard.end() - 1))->getCardNumber() == 14 || (*(vCard.end() - 1))->getCardNumber() == 15)  //没有2和Joker
			return false;
		for (auto it = vCard.begin(); it != vCard.end() - 1; it++)
		{
			if (card[(*(it + 1))->getCardNumber()] - card[(*(it))->getCardNumber()] != 1)
				return false;
		}
		return true;
	}
	return false;
}

bool GameRule::isSequenceOfPairs(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() >= 6 && vCard.size() % 2 == 0)
	{
		if ((*(vCard.end() - 1))->getCardNumber() == 2 || (*(vCard.end() - 1))->getCardNumber() == 14 || (*(vCard.end() - 1))->getCardNumber() == 15)  //没有2和Joker
			return false;

		for (auto it = vCard.begin(); it != vCard.end() - 2; it += 2)
		{
			if (!isPair(it, it + 2))
				return false;
			if (card[(*(it + 2))->getCardNumber()] - card[(*it)->getCardNumber()] != 1)
				return false;
		}
		if (!isPair(vCard.end() - 2, vCard.end()))
			return false;
		return true;
	}
	return false;
}

bool GameRule::isSequenceOfTriplets(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() >= 6 && vCard.size() % 3 == 0)
	{
		if ((*(vCard.end() - 1))->getCardNumber() == 2 || (*(vCard.end() - 1))->getCardNumber() == 14 || (*(vCard.end() - 1))->getCardNumber() == 15)  //没有2和Joker
			return false;
		for (auto it = vCard.begin(); it != vCard.end() - 3; it += 3)
		{
			if (!isTriplet(it, it + 3))
				return false;
			if (card[(*(it + 3))->getCardNumber()] - card[(*it)->getCardNumber()] != 1)
				return false;
		}
		if (!isTriplet(vCard.end() - 3, vCard.end()))
			return false;
		return true;
	}
	return false;
}

bool GameRule::isSequenceOfTriplets(cocos2d::Vector<Card*>::iterator vBegin, cocos2d::Vector<Card*>::iterator vEnd)
{
	if (vEnd-vBegin >= 6 && (vEnd-vBegin) % 3 == 0)
	{
		if ((*(vEnd - 1))->getCardNumber() == 2 || (*(vEnd - 1))->getCardNumber() == 14 || (*(vEnd - 1))->getCardNumber() == 15)  //没有2和Joker
			return false;
		for (auto it = vBegin; it != vEnd - 3; it += 3)
		{
			if (!isTriplet(it, it + 3))
				return false;
			if (card[(*(it + 3))->getCardNumber()] - card[(*it)->getCardNumber()] != 1)
				return false;
		}
		if (!isTriplet(vEnd - 3, vEnd))
			return false;
		return true;
	}
	return false;
}

bool GameRule::isSequenceOfTripletsWithAttachedCards(cocos2d::Vector<Card*>& vCard)
{
	if (vCard.size() >= 8 && vCard.size()%4==0)
	{
		if ((*(vCard.end() - 2))->getCardNumber() == 14 && (*(vCard.end() - 1))->getCardNumber() == 15)  //不能有两个Joker
			return false;
		for (auto it = vCard.begin(); it != vCard.end() - 3; it++)
		{
			if (isBomb(it, it + 4))
				return false;
		}
		int single = vCard.size() / 4;
		
		for (auto it = vCard.begin(); it != vCard.begin()+single+1; it++)
		{
			if (isSequenceOfTriplets(it, it + single * 3))
			{
				if (it - vCard.begin() >= 2)
				{
					for (auto i = vCard.begin(); i != it - 1; i++)
					{
						if (isPair(i, i + 2))
							return false;
					}
				}
				if (vCard.end() - (it + single * 3) >= 2)
				{
					for (auto i = it + single * 3; i != vCard.end() - 1; i++)
					{
						if (isPair(i, i + 2))
							return false;
					}
				}
				return true;
				
			}
		}
	}
	return false;
}

bool GameRule::isSequenceOfTripletsWithAttachedPairs(cocos2d::Vector<Card*>& vCard)
{

	if (vCard.size() >= 10 && vCard.size() % 5 == 0)
	{
		if ((*(vCard.end() - 1))->getCardNumber() == 14 || (*(vCard.end() - 1))->getCardNumber() == 15)  //不能有Joker
			return false;
		for (auto it = vCard.begin(); it != vCard.end() - 3; it++)   //不能有炸弹
		{
			if (isBomb(it, it + 4))
				return false;
		}
		int single = vCard.size() / 5;          

		for (auto it = vCard.begin(); it != vCard.begin() + single*2 +2; it+=2)
		{
			if (isSequenceOfTriplets(it, it + single * 3))
			{
				if ((it - vCard.begin()) % 2 != 0)
					return false;
				for (auto i = vCard.begin(); i < it - 1; i += 2)
				{
					if (!isPair(i, i + 2))
						return false;
				}

				if ((vCard.end() - (it + single * 3)) % 2 != 0)
					return false;
				for (auto i = it + single * 3; i < vCard.end() - 1; i += 2)
				{
					if (!isPair(i, i + 2))
						return false;
				}
				return true;
			}
		}
	}
	return false;
}

CardType& GameRule::getCardType()
{
	return _cardType;
}

int& GameRule::getCardArrayNumber()
{
	return _cardArrayNumber;
}

int & GameRule::getCardLength()
{
	return _cardLength;	// TODO: 在此处插入 return 语句
}

