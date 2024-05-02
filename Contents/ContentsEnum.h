#pragma once

enum class ERenderOrder
{
	Back,
	Title,
	Menu,
	TitleF,
	MonsterUp,
	MonsterUIUp,
	MonsterDown,
	MonsterUIDown,
	Player,
	Attack,
	Mouse,
	UI,
};

enum class ECollisionOrder
{
	Player,
	Menu,
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