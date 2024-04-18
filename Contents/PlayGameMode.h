#pragma once
#include <EngineCore/GameMode.h>
#include "PlayBack.h"
#include "Player.h"
#include "Monster.h"
#include "Mouse.h"
#include "Ranged.h"
#include "UI.h"

struct FIntPoint
{
	union 
	{
		struct 
		{
			int X;
			int Y;
		};

		__int64 Key;
	};
};

// Ό³Έν :
class APlayGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	APlayGameMode();
	~APlayGameMode();

	// delete Function
	APlayGameMode(const APlayGameMode& _Other) = delete;
	APlayGameMode(APlayGameMode&& _Other) noexcept = delete;
	APlayGameMode& operator=(const APlayGameMode& _Other) = delete;
	APlayGameMode& operator=(APlayGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::vector<std::shared_ptr<APlayBack>> Grounds;

	std::shared_ptr<AMouse> Mouse;
	std::shared_ptr<APlayer> Player;

	std::shared_ptr<AUI> UI;

	std::shared_ptr<AMelee> Melee;
	
	float4 IndexToCenterPos(FIntPoint _Index);

	float4 RandomLocation(bool _Group);
	void SpawnMonster(std::string _Name, float4 _Location);
	void MeleeAttack(float _DeltaTime);
	void AttackDir();
	void AttackAimDir();
	float AttackAngle;


	FIntPoint PosToIndex(float4 _Pos);
	FVector MousePosi;
	void InfinityGroundCheck();
	void SpawnMonsterTimeSet(float _DeltaTime, float _SpawnBegin, float _SpawnEnd, float _Term, std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType, bool _Group = false, int _Quantity = 1);
	void RandomSpawnMonster(std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType, bool _Group, int _Quantity);




	void PlayDebugText();

private:
	FIntPoint CurIndex;
	float PlayTime = 0;
	float SpawnTerm = 0;
	float4 GroupMonsterPos;
	bool GroupSpawn = false;

	void CursorOFf();

	float AttackTime = 0;
}
;

