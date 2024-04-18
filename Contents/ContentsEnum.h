#pragma once

enum class ERenderOrder
{
	Title,
	Back,
	Player,
	Monster,
	MonsterUp,
	MonsterDown,
	Attack,
	UI,
};

enum class ECollisionOrder
{
	Player,
	Monster,
};

enum class EActorDir
{
	None,
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW,
};

enum class EMonsterMoveType
{
	Follow,
	StraightToPlayer,
	StraightToUp,
	StraightToDown,
	StraightToRight,
	StraightToLeft,
	Stop,
};