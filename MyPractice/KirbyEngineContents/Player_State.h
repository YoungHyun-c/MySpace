#pragma once
//#include "StateManager.h"
#include "Player.h"

#include <vector>

class CColider;

class CPlayerState
{
protected:
	PLAYERINFO m_eInfo;
	CPlayer* m_pPlayer;
	PLAYERSTATE m_eState;
	bool m_bIsActive;

public:
	CPlayerState();
	virtual ~CPlayerState();

	CPlayer* GetPlayer();
	bool GetIsActive();


	virtual void Anim() {}
	virtual void render() {}
	virtual void update() = 0;
	virtual void Enter() = 0;
	virtual void Exit(PLAYERSTATE state) = 0;
};

class CPlayerIdle : public CPlayerState
{
private:
	//CCollider* m_pPlayerCollider;

public:
	CPlayerIdle();
	~CPlayerIdle();

	void KeyUpdate();
	virtual void Anim();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerMove : public CPlayerState
{
private:
	enum class COMMANDMOVE
	{
		NONE,
		DASH,
		CHANGEDIR,
		TURNOFF,
		IMPACT,

		END
	};

	COMMANDMOVE m_eCurCommand;
	COMMANDMOVE m_ePrevCommand;
	float m_fAnimStayTime;
	bool m_bIsDash;
	bool m_bIsStop;
	bool m_bStartDir;
	bool m_bIsDirChange;
	int m_dir;


public:
	CPlayerMove();
	~CPlayerMove();

	void Move();
	void Anim();

	void KeyUpdate();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerJump : public CPlayerState
{
private:
	bool isTurn;
	float m_fJumpSpeed;
	float m_fTurnSpeed;
	float m_fTurnKeepSpeed;
	float m_fMaXHeight;

public:
	CPlayerJump();
	~CPlayerJump();

	void Jump();
	void Anim();

	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerFall : public CPlayerState
{
public:
	enum class COLLIONTARGET
	{
		GROUND,
		MON,


		END,
	};

private:

	COLLIONTARGET m_eTarget;


public:
	CPlayerFall();
	~CPlayerFall();

	void SetTarget(COLLIONTARGET target);

	void KeyUpdate();
	virtual void Anim();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerDown : public CPlayerState
{
private:
	float nomalanimtime;
	float nomalanimKeeptime;


	bool m_startDir;

public:
	CPlayerDown();
	~CPlayerDown();

	virtual void Anim();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};


class CAttackObj;

class CPlayerAttack : public CPlayerState
{
private:
	float nomalanimtime;
	float nomalanimKeeptime;
	bool m_startDir;
	float4 m_fAttRange;

	CAttackObj* m_pAttackobj[8];

public:
	CPlayerAttack();
	~CPlayerAttack();

	void NomalAttack();
	void CutterAttack();
	void ThrowAttack();
	void NomalAnim();
	void CutterAnim();
	void ThrowAnim();

	virtual void Anim();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerEat : public CPlayerState
{
private:
	float nomalanimtime;
	float nomalanimKeeptime;

public:
	CPlayerEat();
	~CPlayerEat();

	virtual void Anim();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerFly : public CPlayerState
{
private:
	float m_fAnimSpeed;
	float m_fKeepTimer;

public:
	CPlayerFly();
	~CPlayerFly();

	void Anim();

	void KeyUpdate();
	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};

class CPlayerAnim : public CPlayerState
{
private:
	//vector<PLAYERSTATE> m_arrState;

public:
	CPlayerAnim();
	~CPlayerAnim();

	virtual void update();
	virtual void Enter();
	virtual void Exit(PLAYERSTATE state);
};