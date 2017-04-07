#include"Player.h"
USING_NS_CC;


Player::Player(playerType type)
	:_numberCard(0), _isLandlord(false), _isAI(false), _spriteCardNumber ( NULL),_playerType(type),_isWantLandlord(true)
{
}

Player::~Player()
{
	delete _gameRule;
	_gameRule = nullptr;
}

Player * Player::create(playerType type)
{
	auto player = new Player(type);
	if (player && player->init())
	{
		player->autorelease();
		return player;
	}
	CC_SAFE_DELETE(player);
	return nullptr;
}

void Player::showCard()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto cardContentSize = _vCard.at(0)->getContentSize();
	if (_playerType ==playerType::PLAYER_1)
	{
		for (int i = 0; i < (int)_vCard.size(); i++)
		{
			_vCard.at(i)->setPosition(visibleSize.width / 10 + i*(_vCard.at(i)->getContentSize().width / 3), visibleSize.height / 6);
			this->addChild(_vCard.at(i));
		}
	}
	else if(_playerType == playerType::PLAYER_2)
	{
		
		for (int i = 0; i < (int)_vCard.size(); i++)
		{
			_vCard.at(i)->setPosition(visibleSize.width + cardContentSize.width / 2, visibleSize.height * 3 / 4);
			this->addChild(_vCard.at(i));
			_vCard.at(i)->setVisible(false);
		}
	}
	else   //PLAYER_3
	{
		for (int i = 0; i < (int)_vCard.size(); i++)
		{
			_vCard.at(i)->setPosition( -cardContentSize.width / 2, visibleSize.height * 3 / 4);
			_vCard.at(i)->setVisible(false);
			this->addChild(_vCard.at(i));
		}
	}
}

bool Player::init()
{
	if(!Node::init())
		return false;
	 _gameRule = new GameRule();
	 if (_gameRule == nullptr)
	 {
		 CC_SAFE_DELETE(_gameRule);
		 return false;
	 }
	return true;
}
//����
void Player::pushCard()
{      
	for (auto card : _currentCard)
		{
			_vCard.eraseObject(card);
			--_numberCard;
		}
	_currentCard.clear();
	if(!_isAI)         //�����Լ�
	   fillEmptyCard();
}
//�����
void Player::getCard(Card* card)
{
	_vCard.pushBack(card);
	_numberCard++;
}

void Player::arrangeCard()
{
	sort(_vCard.begin(), _vCard.end(),GameRule::largerCard);
}

void Player::fillEmptyCard()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = 0; i<(int)_vCard.size(); i++)
	{
		if(_isLandlord)
		_vCard.at(i)->setPosition(visibleSize.width / 10 + 
			( ( 20 - (int)_vCard.size() )/2)*( _vCard.at(i)->getContentSize().width / 3 ) +
			i*(_vCard.at(i)->getContentSize().width / 3), visibleSize.height / 8);
		else
			_vCard.at(i)->setPosition(visibleSize.width / 10 +
			((17 - (int)_vCard.size()) / 2)*(_vCard.at(i)->getContentSize().width / 3) +
				i*(_vCard.at(i)->getContentSize().width / 3), visibleSize.height / 8);
	}
}



bool Player::findFitCard(CardType cardType, int cardArrayNumber, int cardLength)
{
	bool isFind = false;
	_currentCard.clear();
	std::vector<int> bombNum;//���ը�������֣��ͻ������
	for (int i = _vCard.size()-1; i >= 3; --i)
	{
		if (
			_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
			_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber() &&
			_vCard.at(i - 2)->getCardNumber() == _vCard.at(i - 3)->getCardNumber())
		{
			bombNum.push_back(_vCard.at(i)->getCardNumber());
			i = i - 3;
		}	
	}
	for (int i = _vCard.size()-1; i >= 1; --i)
	{
		if (_vCard.at(i)->getCardNumber() == 14 && _vCard.at(i - 1)->getCardNumber() == 15)
		{
			bombNum.push_back(_vCard.at(i)->getCardNumber());
			bombNum.push_back(_vCard.at(i-1)->getCardNumber());
			break;
		}
	}
	switch (cardType)
	{
	case CardType::SINGLE:
		if (_vCard.size() >= 1)
		{
			for (int i = _vCard.size() - 1; i >= 0; i--)
			{
				if (card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber]&&
					find(bombNum.begin(),bombNum.end(),_vCard.at(i)->getCardNumber()) == bombNum.end())
				{
					_currentCard.pushBack(_vCard.at(i));
					_gameRule->getCardType() = CardType::SINGLE;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	case CardType::PAIR:
		if (_vCard.size() >= 2)
		{
			for (int i = _vCard.size() - 1; i >= 1; i--)
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end()&&
					card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_gameRule->getCardType() = CardType::PAIR;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	case CardType::ROCKET:
		return false;
		break;
	case CardType::TRIPLET:
		if (_vCard.size() >= 3)
		{
			for (int i = _vCard.size() - 1; i >= 2; i--)
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end()&&
					card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber()
					&& _vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_currentCard.pushBack(_vCard.at(i - 2));

					_gameRule->getCardType() = CardType::TRIPLET;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	case CardType::BOMB:
	{
		if (_vCard.size() >= 4)
		{
			for (int i = _vCard.size() - 1; i >= 3; i--)
			{
				if (card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
					_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber() &&
					_vCard.at(i - 2)->getCardNumber() == _vCard.at(i - 3)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_currentCard.pushBack(_vCard.at(i - 2));
					_currentCard.pushBack(_vCard.at(i - 3));

					_gameRule->getCardType() = CardType::BOMB;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	}
	case CardType::QUAD_WITH_ATTACHED_CARDS:
	{
		if (_vCard.size() >= 6)
		{
			for (int i = _vCard.size() - 1; i >= 3; i--)
			{
				if (card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
					_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber() &&
					_vCard.at(i - 2)->getCardNumber() == _vCard.at(i - 3)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_currentCard.pushBack(_vCard.at(i - 2));
					_currentCard.pushBack(_vCard.at(i - 3));
					isFind = true;
					break;
				}
			}
			if (!isFind)
				break;
			int tempNum = 0;
			int tempCardNum = 0;
			for (int i = _vCard.size() - 1; i >= 0; i--)
			{
				if (tempNum == 0 &&
					find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end() )
				{
					_currentCard.pushBack(_vCard.at(i));
					tempNum++;
					tempCardNum = _vCard.at(i)->getCardNumber();
				}
				else if(tempNum == 1 &&
					find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end() && 
					_vCard.at(i)->getCardNumber() != tempCardNum)
				{
					_currentCard.pushBack(_vCard.at(i));
					_gameRule->getCardType() = CardType::QUAD_WITH_ATTACHED_CARDS;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	}
	case CardType::QUAD_WITH_ATTACHED_PAIRS:
	{
		if (_vCard.size() >= 8)
		{
			for (int i = _vCard.size()-1; i >= 3; i--)
			{
				if (card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
					_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber() &&
					_vCard.at(i - 2)->getCardNumber() == _vCard.at(i - 3)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_currentCard.pushBack(_vCard.at(i - 2));
					_currentCard.pushBack(_vCard.at(i - 3));
					isFind = true;
					break;
				}
			}
			if (!isFind)
				break;
			int tempNum = 0;
			int tempCardNum = 0;
			for (int i = _vCard.size() - 1; i >= 1; i--)
			{
				if (tempNum == 0 &&
					find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end() && //���ĸ������ֲ�ͬ
					_vCard.at(i)->getCardNumber() == _currentCard.at(i - 1)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					tempNum++;
					tempCardNum = _vCard.at(i)->getCardNumber();
				}
				else if (tempNum == 1 &&
					find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end() && //���ĸ������ֲ�ͬ
					_vCard.at(i)->getCardNumber() == _currentCard.at(i - 1)->getCardNumber() &&
					_vCard.at(i)->getCardNumber() != tempCardNum)
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));

					_gameRule->getCardType() = CardType::QUAD_WITH_ATTACHED_PAIRS;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	}
	case CardType::TRIPLET_WITH_ATTACHED_CARDS:
	{
		if (_vCard.size() >= 4)
		{
			for (int i = _vCard.size() - 1; i >= 2; i--)
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end()&&
					card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
					_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_currentCard.pushBack(_vCard.at(i - 2));
					isFind = true;
					break;
				}
			}
			if (!isFind)
				break;
			for (int i = _vCard.size() - 1; i >= 0; i--)
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end() )
				{
					_currentCard.pushBack(_vCard.at(i));

					_gameRule->getCardType() = CardType::TRIPLET_WITH_ATTACHED_CARDS;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	}
	case CardType::TRIPLET_WITH_ATTACHED_PAIRS:
	{
		if (_vCard.size() >= 5)
		{
			for (int i = _vCard.size() - 1; i >= 2; i--)
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end()&&
					card[_vCard.at(i)->getCardNumber()] > card[cardArrayNumber] &&            //����Ǳ�֮ǰ�������
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
					_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));
					_currentCard.pushBack(_vCard.at(i - 2));
					isFind = true;
					break;
				}
			}
			if (!isFind)
				break;
			for (int i = _vCard.size() - 1; i >= 0; i--)
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) == bombNum.end()&&
					_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber())
				{
					_currentCard.pushBack(_vCard.at(i));
					_currentCard.pushBack(_vCard.at(i - 1));

					_gameRule->getCardType() = CardType::TRIPLET_WITH_ATTACHED_PAIRS;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		break;
	}
	case CardType::SEQUENCE:
	{
		int length = 0;
		bool isFindFirst = false;
		int currentNumber = 0;
		if (_vCard.size() >= cardLength)
		{
			for (int i = _vCard.size() - 1; i >= 0; i--)//��ʼ��
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())
					continue;
				length = 0;
				_currentCard.clear();
				isFindFirst = false;//�ҵ���һ���ƣ�
				for (int j = i; j >= 0; j--)
				{
					if (_vCard.at(j)->getCardNumber() == 14 || _vCard.at(j)->getCardNumber() == 15 ||
						_vCard.at(j)->getCardNumber() == 2||
						find(bombNum.begin(), bombNum.end(), _vCard.at(j)->getCardNumber()) != bombNum.end())
						break;
					if (card[_vCard.at(j)->getCardNumber()] <= card[cardArrayNumber])
					{
						break;
					}
					else
					{
						if (!isFindFirst)
						{
							_currentCard.pushBack(_vCard.at(j));
							currentNumber = _vCard.at(j)->getCardNumber();
							length++;
							isFindFirst = true;
						}
						else
						{
							if (card[_vCard.at(j)->getCardNumber()] < (card[currentNumber] + 1))
								continue;
							else if (card[_vCard.at(j)->getCardNumber()] > (card[currentNumber] + 1))  //������
								break;
							else    //����
							{
								_currentCard.pushBack(_vCard.at(j));
								currentNumber++;
								if (_currentCard.size() == cardLength)   //�ﵽָ������
								{
									sort(_currentCard.begin(), _currentCard.end(), _gameRule->largerCard);//��������

									_gameRule->getCardType() = CardType::SEQUENCE;
									_gameRule->getCardArrayNumber() = (*(_currentCard.end() - 1))->getCardNumber();
									_gameRule->getCardLength() = _currentCard.size();
									return true;
								}
							}
						}
					}
				}
			}
		}
		break;
	}
	case CardType::SEQUENCE_OF_PAIRS:
	{
		int length = 0;
		bool isFindFirst = false;
		int currentNumber = 0;
		if (_vCard.size() >= cardLength)
		{
			for (int i = _vCard.size() - 1; i >= 5; i--)//��ʼ��
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())//��ը��
					continue;
				length = 0;
				_currentCard.clear();
				isFindFirst = false;//�ҵ���һ���ԣ�
				for (int j = i; j >= 1; j--)
				{
					if (_vCard.at(j)->getCardNumber() == 14 || _vCard.at(j)->getCardNumber() == 15 ||
						_vCard.at(j)->getCardNumber() == 2||
						find(bombNum.begin(), bombNum.end(), _vCard.at(j)->getCardNumber()) != bombNum.end())//����2�������ԣ�����ը��
						break;
					if (card[_vCard.at(j)->getCardNumber()] <= card[cardArrayNumber])//�ȱ��˵���С
						break;
					else
					{
						if (!isFindFirst)
						{
							if (_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber())//�Ƕ�
							{
								_currentCard.pushBack(_vCard.at(j));
								_currentCard.pushBack(_vCard.at(j - 1));
								currentNumber = _vCard.at(j)->getCardNumber();
								j--;
								length = length + 2;
								isFindFirst = true;
							}
							else
								break;
						}
						else
						{
							if (_vCard.at(j)->getCardNumber() != _vCard.at(j - 1)->getCardNumber())  //�����Ʋ�ͬ
							{

								if (card[_vCard.at(j)->getCardNumber()] <= (card[currentNumber] + 1) &&
									card[_vCard.at(j - 1)->getCardNumber()] <= (card[currentNumber] + 1))  //����������
									continue;
								else
									break;
							}
							else
							{
								if (card[_vCard.at(j)->getCardNumber()] > (card[currentNumber] + 1))   //�Բ�����
									break;
								else if (card[_vCard.at(j)->getCardNumber()] < (card[currentNumber] + 1))  //����һ�εĶ���ͬ
									continue;
								else                //������
								{
									_currentCard.pushBack(_vCard.at(j));
									_currentCard.pushBack(_vCard.at(j - 1));
									currentNumber++;
									length = length + 2;
									j--;
									if (_currentCard.size() == cardLength)
									{
										sort(_currentCard.begin(), _currentCard.end(), _gameRule->largerCard);//��������

										_gameRule->getCardType() = CardType::SEQUENCE_OF_PAIRS;
										_gameRule->getCardArrayNumber() = (*(_currentCard.end() - 1))->getCardNumber();
										_gameRule->getCardLength() = _currentCard.size();
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
		break;
	}
	case CardType::SEQUENCE_OF_TRIPLETS:
	{
		int length = 0;
		bool isFindFirst = false;
		int currentNumber = 0;
		if (_vCard.size() >= cardLength)
		{
			for (int i = _vCard.size() - 1; i >= 5; i--)//��ʼ��
			{
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())//��ը��
					continue;
				length = 0;
				_currentCard.clear();
				isFindFirst = false;//�ҵ���һ���ƣ�
				for (int j = i; j >= 2; j--)
				{
					if (_vCard.at(j)->getCardNumber() == 14 || _vCard.at(j)->getCardNumber() == 15 ||
						_vCard.at(j)->getCardNumber() == 2||
						find(bombNum.begin(), bombNum.end(), _vCard.at(j)->getCardNumber()) != bombNum.end())//����2���ǣ�����ը��
						break;
					if (card[_vCard.at(j)->getCardNumber()] <= card[cardArrayNumber])//��С
						break;
					else
					{
						if (!isFindFirst)
						{
							if (_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber() &&
								_vCard.at(j)->getCardNumber() == _vCard.at(j - 2)->getCardNumber())
							{
								_currentCard.pushBack(_vCard.at(j));
								_currentCard.pushBack(_vCard.at(j - 1));
								_currentCard.pushBack(_vCard.at(j - 2));
								currentNumber = _vCard.at(j)->getCardNumber();
								j = j - 2;
								length = length + 3;
								isFindFirst = true;
							}
							else
								break;
						}
						else
						{
							if (!(_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber() &&
								_vCard.at(j)->getCardNumber() == _vCard.at(j - 2)->getCardNumber()))
							{

								if (card[_vCard.at(j)->getCardNumber()] <= (card[currentNumber] + 1) &&
									card[_vCard.at(j - 1)->getCardNumber()] <= (card[currentNumber] + 1) &&
									card[_vCard.at(j - 2)->getCardNumber()] <= (card[currentNumber] + 1))
									continue;
								else
									break;
							}
							else
							{
								if (card[_vCard.at(j)->getCardNumber()] > (card[currentNumber] + 1))
									break;
								else
								{
									_currentCard.pushBack(_vCard.at(j));
									_currentCard.pushBack(_vCard.at(j - 1));
									_currentCard.pushBack(_vCard.at(j - 2));
									currentNumber++;
									length = length + 3;
									j = j - 2;
									if (_currentCard.size() == cardLength)
									{
										sort(_currentCard.begin(), _currentCard.end(), _gameRule->largerCard);//��������

										_gameRule->getCardType() = CardType::SEQUENCE_OF_TRIPLETS;
										_gameRule->getCardArrayNumber() = (*(_currentCard.end() - 1))->getCardNumber();
										_gameRule->getCardLength() = _currentCard.size();
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
		break;
	}
	case CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS:
	{
		int length = 0;
		bool isFindFirst = false;
		bool isFindTriplet = false;
		int currentNumber = 0;
		//���triplet��currentCard
		if (_vCard.size() >= cardLength)
		{
			for (int i = _vCard.size() - 1; i >= 5; i--)//��ʼ��
			{
				if (isFindTriplet)
					break;
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())//��ը��
					continue;
				isFindTriplet = false;
				length = 0;
				_currentCard.clear();
				isFindFirst = false;//�ҵ���һ���ƣ�
				for (int j = i; j >= 2; j--)
				{
					if (isFindTriplet)
						break;
					if (_vCard.at(j)->getCardNumber() == 14 || _vCard.at(j)->getCardNumber() == 15 || _vCard.at(j)->getCardNumber() == 2||
						find(bombNum.begin(), bombNum.end(), _vCard.at(j)->getCardNumber()) != bombNum.end())
						break;
					if (_vCard.at(j)->getCardNumber() <= cardArrayNumber)
						break;
					else
					{
						if (!isFindFirst)
						{
							if (_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber() &&//�ҵ�3��һ����
								_vCard.at(j)->getCardNumber() == _vCard.at(j - 2)->getCardNumber())
							{
								_currentCard.pushBack(_vCard.at(j));
								_currentCard.pushBack(_vCard.at(j - 1));
								_currentCard.pushBack(_vCard.at(j - 2));
								currentNumber = _vCard.at(j)->getCardNumber();
								j = j - 2;
								length = length + 3;
								isFindFirst = true;
							}
							else
								break;
						}
						else
						{
							if (!(_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber() &&//���Ų�ȫ���
								_vCard.at(j)->getCardNumber() == _vCard.at(j - 2)->getCardNumber()))
							{

								if (_vCard.at(j)->getCardNumber() <= (currentNumber + 1) &&    //�Ƿ���������
									_vCard.at(j - 1)->getCardNumber() <= (currentNumber + 1) &&
									_vCard.at(j - 2)->getCardNumber() <= (currentNumber + 1))
									continue;
								else
									break;
							}
							else                      //�������
							{
								if (_vCard.at(j)->getCardNumber() > (currentNumber + 1))//������
									break;
								else  //����
								{
									_currentCard.pushBack(_vCard.at(j));
									_currentCard.pushBack(_vCard.at(j - 1));
									_currentCard.pushBack(_vCard.at(j - 2));
									currentNumber++;
									length = length + 3;
									j = j - 2;
									if (_currentCard.size() / 3 == (cardLength / 4))// ��������Ŀ���
									{
										isFindTriplet = true;
										break;
									}
								}
							}
						}
					}
				}
			}
			currentNumber = 0;
			if (isFindTriplet)
			{
				sort(_currentCard.begin(), _currentCard.end(), _gameRule->largerCard);//��������

				int num = _currentCard.size() / 3;       //triplet����Ŀ
				for (int i = _vCard.size() - 1; i >= 0; i--)
				{
					if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())//��ը��
						continue;
					bool isSame = false;  //�Ƿ��triplet�е�����ͬ
					for (int j = 0; j < num; j++)
					{
						if (_vCard.at(i)->getCardNumber() == _currentCard.at(3 * j)->getCardNumber())
							isSame = true;
					}
					if (!isSame)  //��triplet�е��Ʋ�ͬ
					{
						if (currentNumber == _vCard.at(i)->getCardNumber())//��������ͬ
							continue;
						_currentCard.pushBack(_vCard.at(i));
						currentNumber = _vCard.at(i)->getCardNumber();

						if (_currentCard.size() == cardLength)
						{
								_gameRule->getCardType() = CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS;
								_gameRule->getCardArrayNumber() = (*(_currentCard.begin() + (num - 1) * 3))->getCardNumber();
								_gameRule->getCardLength() = _currentCard.size();
								return true;
						}
					}
				}
			}
		}
		break;
	}
	case CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_PAIRS:
	{
		int length = 0;
		bool isFindFirst = false;
		bool isFindTriplet = false;
		int currentNumber = 0;
		//���triplet��currentCard
		if (_vCard.size() >= cardLength)
		{
			for (int i = _vCard.size() - 1; i >= 5; i--)//��ʼ��
			{
				if (isFindTriplet)
					break;
				if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())//��ը��
					continue;
				isFindTriplet = false;
				length = 0;
				_currentCard.clear();
				isFindFirst = false;//�ҵ���һ���ƣ�
				for (int j = i; j >= 2; j--)
				{
					if (isFindTriplet)
						break;
					if (_vCard.at(j)->getCardNumber() == 14 || _vCard.at(j)->getCardNumber() == 15 || _vCard.at(j)->getCardNumber() == 2 ||
						find(bombNum.begin(), bombNum.end(), _vCard.at(j)->getCardNumber()) != bombNum.end())
						break;
					if (_vCard.at(j)->getCardNumber() <= cardArrayNumber)
						break;
					else
					{
						if (!isFindFirst)
						{
							if (_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber() &&//�ҵ�3��һ����
								_vCard.at(j)->getCardNumber() == _vCard.at(j - 2)->getCardNumber())
							{
								_currentCard.pushBack(_vCard.at(j));
								_currentCard.pushBack(_vCard.at(j - 1));
								_currentCard.pushBack(_vCard.at(j - 2));
								currentNumber = _vCard.at(j)->getCardNumber();
								j = j - 2;
								length = length + 3;
								isFindFirst = true;
							}
							else
								break;
						}
						else
						{
							if (!(_vCard.at(j)->getCardNumber() == _vCard.at(j - 1)->getCardNumber() &&//���Ų�ȫ���
								_vCard.at(j)->getCardNumber() == _vCard.at(j - 2)->getCardNumber()))
							{

								if (_vCard.at(j)->getCardNumber() <= (currentNumber + 1) &&    //�Ƿ���������
									_vCard.at(j - 1)->getCardNumber() <= (currentNumber + 1) &&
									_vCard.at(j - 2)->getCardNumber() <= (currentNumber + 1))
									continue;
								else
									break;
							}
							else                      //�������
							{
								if (_vCard.at(j)->getCardNumber() > (currentNumber + 1))//������
									break;
								else  //����
								{
									_currentCard.pushBack(_vCard.at(j));
									_currentCard.pushBack(_vCard.at(j - 1));
									_currentCard.pushBack(_vCard.at(j - 2));
									currentNumber++;
									length = length + 3;
									j = j - 2;
									if (_currentCard.size() / 3 == (cardLength / 4))// ��������Ŀ���
									{
										isFindTriplet = true;
										break;
									}
								}
							}
						}
					}
				}
			}
			currentNumber = 0;
			if (isFindTriplet)
			{
				sort(_currentCard.begin(), _currentCard.end(), _gameRule->largerCard);//��������

				int num = _currentCard.size() / 3;       //triplet����Ŀ
				for (int i = _vCard.size() - 1; i >= 1; i--)
				{
					if (find(bombNum.begin(), bombNum.end(), _vCard.at(i)->getCardNumber()) != bombNum.end())//��ը��
						continue;
					if (_vCard.at(i)->getCardNumber() != _vCard.at(i - 1)->getCardNumber()) //���Ƕ�
						continue;
					bool isSame = false;  //�Ƿ��triplet�е�����ͬ
					for (int j = 0; j < num; j++)
					{
						if (_vCard.at(i)->getCardNumber() == _currentCard.at(3 * j)->getCardNumber())
							isSame = true;
					}
					if (!isSame)  //��triplet�е��Ʋ�ͬ
					{
						if (currentNumber == _vCard.at(i)->getCardNumber())//��������ͬ
							continue;
						_currentCard.pushBack(_vCard.at(i));
						_currentCard.pushBack(_vCard.at(i - 1));
						i--;
						currentNumber = _vCard.at(i)->getCardNumber();

						if (_currentCard.size() == cardLength)
						{
							_gameRule->getCardType() = CardType::SEQUENCE_OF_TRIPLETS_WITH_ATTACHED_CARDS;
							_gameRule->getCardArrayNumber() = (*(_currentCard.begin() + (num - 1) * 3))->getCardNumber();
							_gameRule->getCardLength() = _currentCard.size();
							return true;
						}
					}
				}
			}
		}
		break;
	}
	}

	_currentCard.clear();
	if (cardArrayNumber != 0)
	{
		if (cardType != CardType::BOMB) //����ը����
		{
			if (_vCard.size() >= 4)
			{
				for (int i = _vCard.size() - 1; i >= 3; i--)
				{
					if (
						_vCard.at(i)->getCardNumber() == _vCard.at(i - 1)->getCardNumber() &&
						_vCard.at(i - 1)->getCardNumber() == _vCard.at(i - 2)->getCardNumber() &&
						_vCard.at(i - 2)->getCardNumber() == _vCard.at(i - 3)->getCardNumber())
					{
						_currentCard.pushBack(_vCard.at(i));
						_currentCard.pushBack(_vCard.at(i - 1));
						_currentCard.pushBack(_vCard.at(i - 2));
						_currentCard.pushBack(_vCard.at(i - 3));

						_gameRule->getCardType() = CardType::BOMB;
						_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
						_gameRule->getCardLength() = _currentCard.size();
						return true;
					}
				}
			}
			if (_vCard.size() >= 2)            //������ը
			{
				if (_vCard.at(0)->getCardNumber() == 15 && _vCard.at(1)->getCardNumber() == 14)
				{
					_currentCard.pushBack(_vCard.at(0));
					_currentCard.pushBack(_vCard.at(1));
					_gameRule->getCardType() = CardType::ROCKET;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		else
		{
			if (_vCard.size() >= 2)
			{
				if (_vCard.at(0)->getCardNumber() == 15 && _vCard.at(1)->getCardNumber() == 14)
				{
					_currentCard.pushBack(_vCard.at(0));
					_currentCard.pushBack(_vCard.at(1));
					_gameRule->getCardType() = CardType::ROCKET;
					_gameRule->getCardArrayNumber() = (*_currentCard.begin())->getCardNumber();
					_gameRule->getCardLength() = _currentCard.size();
					return true;
				}
			}
		}
		_currentCard.clear();
	}
	return  false;
}
