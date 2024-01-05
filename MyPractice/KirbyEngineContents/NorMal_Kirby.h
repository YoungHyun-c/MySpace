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
//	//흡수한 몬스터가 무슨 몬스터인지 string으로 저장
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
//public: //디폴트 접근 지정자
//
//	//기본 커비의 애니메이션용 렌더변수
//	GameEngineRenderer* MainRender_;
//
//	//엔딩씬 직전 커비 댄스용 변수
//	GameEngineRenderer* DanceRender_;
//	GameEngineRenderer* DanceRendertwo_;
//	GameEngineRenderer* DanceRenderthree_;
//
//	//흡수를 한 상태에서의 기본커비의 애니메이션용 렌더변수
//	GameEngineRenderer* DrainAfterRender_;
//	//빨아들일때의 이펙트용
//	GameEngineRenderer* DrainEffectRender_;
//
//	//커터상태에서의 애니메이션용 렌더 변수
//	GameEngineRenderer* CutterRender_;
//
//	//빔상태에서의 애니메이션용 렌더 변수
//	GameEngineRenderer* BeamRender_;
//	//빔 채찍 공격의 이펙트용
//	GameEngineRenderer* BeamEffectRender_;
//	//삼킬때 이펙트용
//	GameEngineRenderer* EatEffectRender_;
//
//	GameEngineCollision* MiddleGroundCheckCollision;
//	GameEngineCollision* LeftGroundCheckCollision;
//	GameEngineCollision* RightGroundCheckCollision;
//	GameEngineCollision* TopGroundCheckCollision;
//
//
//	GameEngineCollision* BodyCheckCollision;
//	GameEngineCollision* DrainAttackCollision; //커비의 흡수공격의 판정
//	GameEngineCollision* DrainCheckCollision; //끌려들어오는 적들을 받기위한 판정
//	GameEngineCollision* BeamAttackCollision; //빔채찍 공격을 위한 판정
//
//	//효과음 재생용 사운드 플레이어
//	GameEngineSoundPlayer* EffectPlayer;
//
//private:
//	static int BackGroundSizeforCamX;
//	//카메라 이동 제한을 위해서
//	//뒷배경이 될 이미지의 X크기를 받아오기 위한 int
//
//	static float DamageTime;
//	//데미지 상태에서 애니메이션이 넘어가는 시간을 재기 위한 float
//
//	static bool DrainMonsterActive;
//	//몬스터를 흡수하기 시작했을때 추가조작을 막기위한 bool
//
//	static bool ShootMoveActive;
//	//공격 애니메이션 재생중에 추가조작을 막기위한 bool
//
//public:
//	Normal_Kirby& operator=(const Normal_Kirby& _Other) = delete; //디폴트 대입연산자
//	Normal_Kirby& operator=(Normal_Kirby&& _Other) = delete; //디폴트 RValue 대입연산자
//public:
//	Normal_Kirby(); //디폴트 생성자
//	~Normal_Kirby(); //디폴트 소멸자
//	Normal_Kirby(const Normal_Kirby& _Other) = delete; //디폴트 복사 생성자
//	Normal_Kirby(Normal_Kirby&& _Other) noexcept; //디폴트 RValue 복사생성자
//
//
//public:
//	void Update(float _Delta) override;
//	void Render(float _Delta) override;
//	void Start() override;
//
//public:
//	//실제 현재 커비상태를 체크하는 enum변수
//	KirbyAbilityState AbilityType_;
//
//	//DrainAfter상태에서 입에 물고 있는 게 무엇인지 체크하는 enum변수
//	KirbyAbilityState HoldingAbilityStarType_;
//
//	//현재 커비의 행동 상태를 나타내는 변수
//	PlayerState stateType_;
//
//	//점프를 자연스럽게 하게 만들어주는 float4
//	//프레임마다 DOWN -= 를 해서, 어느 지점에서 올라가는게 멈추게 만들수 있다
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