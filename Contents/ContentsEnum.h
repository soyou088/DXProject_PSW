#pragma once

enum class ERenderOrder
{
	Back,
	Title,
	TitleF,
	TitleB,
	Monster,
	MonsterUp,
	MonsterDown,
	Player,
	Attack,
	UI,
};

enum class ECollisionOrder
{
	Player,
	Weapon,
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