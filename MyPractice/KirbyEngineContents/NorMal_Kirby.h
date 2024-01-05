//#pragma once
//#include <GameEngineCore/GameEngineActor.h>
//#include <GameEngineCore/GameEngineObject.h>
//#include "ContentsEnum.h"
//
//enum class PlayerState
//{
//	Stand,
//	Down,
//	Walk,
//	Run,
//	JumpUp,
//	JumpDown,
//	Fly,
//	FlyEnd,
//	DrainReady,
//	DrainING,
//	DamageUp,
//	DamageDown,
//	Attack,
//	Eat,
//	Dead,
//	Dance,
//	DanceReady,
//	Max
//
//};
//
//enum class DirectionState
//{
//	LEFT,
//	RIGHT,
//};
//
//class GameEngineSoundPlayer;
//class Normal_Kirby : public GameEngineActor
//{
//public:
//	int HP;
//
//
//private:
//	float Speed;
//
//	DirectionState dirstate_;
//	std::string AbilityStateName_;
//	std::string StateName_;
//
//	std::string DrainedMonsterState_;
//	//����� ���Ͱ� ���� �������� string���� ����
//
//	float4 PlayerPivot_;
//private:
//	DebugMode DebugState_;
//
//public:
//
//	DirectionState GetDirState()
//	{
//		return dirstate_;
//	}
//
//public: //����Ʈ ���� ������
//
//	//�⺻ Ŀ���� �ִϸ��̼ǿ� ��������
//	GameEngineRenderer* MainRender_;
//
//	//������ ���� Ŀ�� ���� ����
//	GameEngineRenderer* DanceRender_;
//	GameEngineRenderer* DanceRendertwo_;
//	GameEngineRenderer* DanceRenderthree_;
//
//	//����� �� ���¿����� �⺻Ŀ���� �ִϸ��̼ǿ� ��������
//	GameEngineRenderer* DrainAfterRender_;
//	//���Ƶ��϶��� ����Ʈ��
//	GameEngineRenderer* DrainEffectRender_;
//
//	//Ŀ�ͻ��¿����� �ִϸ��̼ǿ� ���� ����
//	GameEngineRenderer* CutterRender_;
//
//	//�����¿����� �ִϸ��̼ǿ� ���� ����
//	GameEngineRenderer* BeamRender_;
//	//�� ä�� ������ ����Ʈ��
//	GameEngineRenderer* BeamEffectRender_;
//	//��ų�� ����Ʈ��
//	GameEngineRenderer* EatEffectRender_;
//
//	GameEngineCollision* MiddleGroundCheckCollision;
//	GameEngineCollision* LeftGroundCheckCollision;
//	GameEngineCollision* RightGroundCheckCollision;
//	GameEngineCollision* TopGroundCheckCollision;
//
//
//	GameEngineCollision* BodyCheckCollision;
//	GameEngineCollision* DrainAttackCollision; //Ŀ���� ��������� ����
//	GameEngineCollision* DrainCheckCollision; //���������� ������ �ޱ����� ����
//	GameEngineCollision* BeamAttackCollision; //��ä�� ������ ���� ����
//
//	//ȿ���� ����� ���� �÷��̾�
//	GameEngineSoundPlayer* EffectPlayer;
//
//private:
//	static int BackGroundSizeforCamX;
//	//ī�޶� �̵� ������ ���ؼ�
//	//�޹���� �� �̹����� Xũ�⸦ �޾ƿ��� ���� int
//
//	static float DamageTime;
//	//������ ���¿��� �ִϸ��̼��� �Ѿ�� �ð��� ��� ���� float
//
//	static bool DrainMonsterActive;
//	//���͸� ����ϱ� ���������� �߰������� �������� bool
//
//	static bool ShootMoveActive;
//	//���� �ִϸ��̼� ����߿� �߰������� �������� bool
//
//public:
//	Normal_Kirby& operator=(const Normal_Kirby& _Other) = delete; //����Ʈ ���Կ�����
//	Normal_Kirby& operator=(Normal_Kirby&& _Other) = delete; //����Ʈ RValue ���Կ�����
//public:
//	Normal_Kirby(); //����Ʈ ������
//	~Normal_Kirby(); //����Ʈ �Ҹ���
//	Normal_Kirby(const Normal_Kirby& _Other) = delete; //����Ʈ ���� ������
//	Normal_Kirby(Normal_Kirby&& _Other) noexcept; //����Ʈ RValue ���������
//
//
//public:
//	void Update(float _Delta) override;
//	void Render(float _Delta) override;
//	void Start() override;
//
//public:
//	//���� ���� Ŀ����¸� üũ�ϴ� enum����
//	KirbyAbilityState AbilityType_;
//
//	//DrainAfter���¿��� �Կ� ���� �ִ� �� �������� üũ�ϴ� enum����
//	KirbyAbilityState HoldingAbilityStarType_;
//
//	//���� Ŀ���� �ൿ ���¸� ��Ÿ���� ����
//	PlayerState stateType_;
//
//	//������ �ڿ������� �ϰ� ������ִ� float4
//	//�����Ӹ��� DOWN -= �� �ؼ�, ��� �������� �ö󰡴°� ���߰� ����� �ִ�
//	float4 JumpDir_;
//	float4 FlyDir_;
//
//public:
//	void StartStand();
//	void StartDown();
//	void StartWalk();
//	void StartDrainReady();
//	void StartDrainING();
//	void StartJumpUp();
//	void StartJumpDown();
//	void StartDamageUp();
//	void StartDamageDown();
//	void StartFly();
//	void StartFlyEnd();
//	void StartAttack();
//	void StartEat();
//	void StartDead();
//	void StartDanceReady();
//	void StartDance();
//
//	void Stand();
//	void Down();
//	void Walk();
//	void DrainReady();
//	void DrainING();
//	void JumpUp();
//	void JumpDown();
//	void DamageUp();
//	void DamageDown();
//	void Fly();
//	void FlyEnd();
//	void Attack();
//	void Eat();
//	void Dead();
//	void DanceReady();
//	void Dance();
//
//	void LeftRightCheck();
//	void MonsterCollisionCheck();
//	void DrainCollisionCheck();
//	void MonsterAttackCollisionCheck();
//	void BeamCollisionCheck();
//	void DoorCollisionCheck();
//
//	void MakeBreath();
//
//	std::string GetDirString();
//	std::string GetAbilityString();
//
//
//
//
//public:
//	void ChangeState(KirbyAbilityState _AbilityType, PlayerState _StateType);
//};