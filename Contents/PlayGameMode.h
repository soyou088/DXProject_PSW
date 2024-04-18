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

	float4 RandomLocation();
	void SpawnMonster(std::string _Name, float4 _Location);
	void MeleeAttack(float _DeltaTime);

	FVector AttackDir();

	FIntPoint PosToIndex(float4 _Pos);
	FVector MousePosi;
	void InfinityGroundCheck();

private:
	FIntPoint CurIndex;

	float SpawnTerm = 0;

	void CursorOFf();

	float AttackTime = 0;
};

