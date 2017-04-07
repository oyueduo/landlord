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
	CALL_LANDLORD,    //�е���
    NOTCALL_LANDLORD,//����
	ROB_LANDLORD,    //������
	NOTROB_LANDLORD  // ����
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
    //����
	void sendCard(); 
    //ϴ��
	void  shuffleCard();
    //����һ����
	void createCard();  
	//����Ϸ
	void newGame();
	//���¿�ʼ
	void restartGame();
	//����
	void pushCard();
	
	//����
	void pass(Player* currentPlayer);
	void hint(Player* currentPlayer);
	//�����Ƶ����
	void changePlayer(Player* player);
	//ѡ����
    void selectLandlord(Player*player);
	//�е����ص�
	void callLandlord();
	//�������ص�
	void robLandlord();
	//����
	void notCallLandlord();
	//����
	void notRobLandlord();
	//���������
	void addLandlordCard();
	//�Ƴ����������е��������У�������
	void removeLabel(Player* player,float delayTime=0.0f);
	
	void removeLabel(cocos2d::Sprite*& sprite, float delayTime=0.0f);
	//����ʱ��λ��
	void updateClock(Player* player, int time,float delayTime=0.0f);
	//������������е��������У�������
    //type����������֮һ
	void addChooseTypeSprite(Player* player, cocos2d::Sprite*& sprite, ChooseType type );

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);
	//���ʱ���Ƿ���
	void testTime(float t);
private:
	cocos2d::Vector<Card*> _vCard;
	Player* _player1;
	Player* _player2;
	Player* _player3;
	//��һ�ֳ�����
	cocos2d::Vector<Card*> _prePlayer1Card;
	cocos2d::Vector<Card*> _prePlayer2Card;
	cocos2d::Vector<Card*> _prePlayer3Card;
	//��һ�ֵĲ���
	cocos2d::Sprite* _prePlayer1BuChu;
	cocos2d::Sprite* _prePlayer2BuChu;
	cocos2d::Sprite* _prePlayer3BuChu;
	//����
	cocos2d::Sprite* _player1NotRob;
	cocos2d::Sprite* _player2NotRob;
	cocos2d::Sprite* _player3NotRob;
	//������
	cocos2d::Sprite* _player1Rob;
	cocos2d::Sprite* _player2Rob;
	cocos2d::Sprite* _player3Rob;
	//����
	cocos2d::Sprite* _player1NotCall;
	cocos2d::Sprite* _player2NotCall;
	cocos2d::Sprite* _player3NotCall;
	//�е���
	cocos2d::Sprite* _player1Call; 
	cocos2d::Sprite* _player2Call;
	cocos2d::Sprite* _player3Call;
	//ʱ��
	Clock* _clock;
	////��ǰ������
	cocos2d::Vector<Card*> _currentCard;
	//��ǰ���Ƶ���
	Player* _currentPlayer;
	GameRule* _gameRule;
	//��ǰ���Ƶ�����
	//CardTypeArray* _cardTypeArray;
	//CardType _currentCardType;
	//��������
	int _startTouchedID;
	int _endTouchedID;
	//��ǰ��������
	CardType _cardType;
	//���������ִ�С
	int _cardArrayNumber;
	//�����Ƴ�
	int _cardLength;
	//pass�Ĵ���
	int _passTimes;
	//�Ƿ񲻳�
	bool _isPass;
	//23�������
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

	Player* _callLandlord;//�е������
	int bujiaoTimes;//���д���
	int notWantLandlordTimes;//��������
};
#endif

