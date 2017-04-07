#include"Card.h"

USING_NS_CC;

Card::Card()
{
	
}

Card* Card::createCard( int number, CardColor color,CardFlower flower, CardOwner owner)
{
	auto card = new Card();
	if (card && card->initWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_0card_f.png")))//³õÊ¼»¯±³¾°
	{
		card->autorelease();
		card->initData(  number,  color, flower,  owner);
		return card;
	}
	CC_SAFE_DELETE(card);
	return nullptr;
}

bool Card::init()
{
	if (Node::init())
		return true;
	
	return false;
}

bool Card::initData( int number, CardColor color,CardFlower flower, CardOwner owner)
{
     _number = Sprite::createWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_0%d_%02d.png",(int)color,number));
	 _number->setAnchorPoint(Vec2(0, 1));
	 _number->setPosition(Vec2(5, this->getContentSize().height-5));
	 this->addChild(_number,1,CardBody::NUMBER);

	 if (number <= 13)
	 {
		 _flower = Sprite::createWithSpriteFrameName(StringUtils::format("HLDDZ_MainGame0_2x_0%d.png",(int) flower));
		 _flower->setAnchorPoint(Vec2(0, 1));
		 _flower->setPosition(Vec2(10, this->getContentSize().height-5 - _number->getContentSize().height));
		this->addChild(_flower,1,CardBody::FLOWER);
	 }
	 this->setScale(cardScale);
	 this->setContentSize(this->getContentSize()*cardScale);

	 _cardNumber = number;
	 _cardFlower = flower;
	 _cardColor = color;
	 _cardOwner = owner;
	 _touched = false;
	return true;
}


int Card::getCardNumber() const
{
	return _cardNumber;
}



bool Card::getCardTouched() const
{
	return _touched;
}

void Card::setCardTouched(bool touched)
{
	_touched = touched;
}



