#pragma once

enum class ERenderOrder
{
	Title,
	Back,
	Player,
	Monster,
	Weapons,
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
