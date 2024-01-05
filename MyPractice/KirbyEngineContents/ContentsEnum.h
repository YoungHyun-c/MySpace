#pragma once

enum class UpdateOrder
{
	Player,
	Monster,
};

enum class RenderOrder
{
	BackGround,
	Play,
	PlayUI,
};

enum class CollisionOrder
{
	Map,
	Player,
	Monster,
	Bullet,
	MonsterAttack,
	//////
	PlayerBody,
	MonsterBody,
	PlayerAttackSize,
};

enum class DebugMode
{
	PLAYMODE,
	DEBUGMODE,
};

enum class MonsterDirectionState
{
	Left,
	Right,
};

enum class MonsterState
{
	Walk,
	Damage,
	Dead,
	GetDrain,
	Attack,
	Jump,
	AttackReady,
	Idle,
	Breath,
};

enum class KirbyAbilityState
{
	Normal,
	DrainAfter,
	Beam,
	Cutter,
};

enum class StageState
{
	OneOne,
	OneTwo,
	//Item,
	Boss,
};