#pragma once
#include "PlayActor.h"

enum class PlayerState
{
	Idle,
	Run,
	JUMP,
	Max, // 일반적으로 사용하지 않는 값.
};

enum class PlayerDir
{
	Left,
	Right,
	Max,
};

// 설명 :
class Player : public PlayActor
{
private:
	static Player* MainPlayer;

public:
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

public:
	// constructer destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator = (const Player& _Other) = delete;
	Player& operator = (Player&& _Other) noexcept = delete;

	GameEngineRenderer* MainRenderer = nullptr;

protected:
	void StateUpdate(float _Delta);
	void IdleStart();
	void RunStart();
	void JumpStart();
	//클래스로 만들어도 되고
	void IdleUpdate(float _Delta);
	void RunUpdate(float _Delta);
	void JumpUpdate(float _Delta);

	void ChangeState(PlayerState State);

	PlayerState State = PlayerState::Max;
	PlayerDir Dir = PlayerDir::Right;
	std::string CurState = "";

	int TestValue = 0;

	GameEngineCollision* BodyCollision = nullptr;
	GameEngineCollision* AttackLeftCollision = nullptr;
	GameEngineCollision* AttackRightCollision = nullptr;

	void DirCheck();

	void ChangeAnimationState(const std::string& _StateName);


private:
	void LevelStart() override;
	void Start() override;
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	bool Attack = false;

	const float JumpPower = 100.0f;

	//================================= DebugValue
	float4 LeftCheck = { -100.0f, -25.0f };
	float4 RightCheck = { 100.0f, -25.0f };
};

struct PLAYERINFO
{
	const float g_fAccel = 2.f;
	// 속력
	const float m_fVelocity = 50.f;
	// 감속
	const float m_fMoveInertia = 0.f;
	// 세로 속도
	const float m_fVerticalSpeed = 100.f;

	const float m_fJumpTime = 1.f;


	bool g_bIsRight = false;
	bool g_bIsUp = false;
	bool g_bIsDown = false;
	bool g_bIsLeft = false;

};

//typedef void(*COLLIDER_FUNC) (DWORD_PTR, CCollider*);

struct PLAYERANIM
{
	std::string g_wIDLE = "Idle";
	std::string g_wMOVE = "Move";
	std::string g_wDASH = "Dash";
	std::string g_wDOWN = "Down";
	std::string g_wQUICKSTOP = "QuickStop";
	std::string g_wWALLIMPACT = "WallImpact";
	std::string g_wDOWNSLIDE = "DownSlide";
	std::string g_wJUMP = "Jump";
	std::string g_wTURN = "Turn";
	std::string g_wFALL0 = "Fall0";
	std::string g_wFALL_DOWN = "Fall0_Down";
	std::string g_wFALL_TURN = "Fall_Turn";
	std::string g_wFALL1 = "Fall1";
	std::string g_wFALL1_DOWN = "Fall1_Down";
	std::string g_wUP = "Up";
	std::string g_wUPIDLE = "UpIdle";
	std::string g_wUPMOVE = "UpMove";
};

enum class ATTACK_TYPE
{
	NORMAL,
	CUTTER,
	THROW,

	SIZE,
};

class CPlayer : public GameEngineObject
{
	friend class CStateManager;
private:
	PLAYERINFO info;
	PLAYERANIM anim;
	ATTACK_TYPE m_eAttackType;
	
	//MON_TYPE m_pEatingMon;
	// 플레이어 애니메이션 재생을 위한 이미지들

	//vector<CD2DImage*> m_pImg;
	// 플레이어 애니메이션 이미지의 키값

	//vector<std::string> m_wImgKey;
	// 플레이어 애니메이션 동작의 키값
	//vector<vector<wstring>*> m_wAnimKey;

	//const float m_fCommandTime = 0.2f;
	bool m_bIsRight;
	bool m_bISInhaleObj;

	//list<COLLIDER_FUNC> m_arrFunc;
	DWORD_PTR m_colliderState;
	//list<COLLIDER_FUNC> m_arrEnterFunc;
	DWORD_PTR m_colliderEnterState;
	//list<COLLIDER_FUNC> m_arrExitFunc;
	DWORD_PTR m_colliderExitState;

	// 타일과의 거리체크
	float m_fTileLength;

	//한번에 만나는 타일은 최대 8개임;
	//CCollider* m_pTileCollider[8];

	//한번에 만나는 타일은 최대 4개임;
	//CCollider* m_pTileColliderSlope[4];

	void SetAnim();

public:

	CPlayer();
	~CPlayer();
	virtual CPlayer* Clone();

	virtual void update();
	virtual void render();
	void TileCheckRender();

	ATTACK_TYPE GetAttackType();

	PLAYERINFO& GetPlaeyrInfo();

	const PLAYERANIM& GetAnimString();


	//void AddTileCollider(CCollider* ground);
	//void AddTileColliderSlope(CCollider* ground);
	void TileCheck();

	void SetAttackType(ATTACK_TYPE type);
	//void SetMonType(MON_TYPE type);
	void SetDir(bool dir);
	void SetAnimString();
	void SetIsInhale(bool isInhale);

	//MON_TYPE GetMonType();
	bool GetDir();
	bool GetIsInhale();


	//void SetCollisonCallBack(COLLIDER_FUNC pFunc, DWORD_PTR state);
	//void DeleteColliderCallBack(COLLIDER_FUNC pFunc);
	//void SetCollisonEnterCallBack(COLLIDER_FUNC pFunc, DWORD_PTR state);
	//void DeleteColliderEnterCallBack(COLLIDER_FUNC pFunc);
	//void SetCollisonExitCallBack(COLLIDER_FUNC pFunc, DWORD_PTR state);
	//void DeleteColliderExitCallBack(COLLIDER_FUNC pFunc);

	//virtual void OnCollision(CCollider* Other);
	//virtual void OnCollisionEnter(CCollider* Other);
	//virtual void OnCollisionExit(CCollider* Other);

};


enum class PLAYERSTATE
{
	Anim,
	IDLE,
	MOVE,
	DOWN,
	JUMP,
	Fall,
	FLY,
	EAT,
	TRANSFORM,
	ATTACK,

	END,
};
