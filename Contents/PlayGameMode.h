#pragma once
#include <EngineCore/GameMode.h>
#include "PlayBack.h"
#include "Player.h"
#include "Monster.h"
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

// 	std::map<__int64, std::shared_ptr<APlayBack>> Grounds;
	std::vector<std::shared_ptr<APlayBack>> Grounds;

	std::shared_ptr<APlayer> Player;
	std::shared_ptr<AMonster> Monster;
	std::shared_ptr<AUI> UI;
	float4 IndexToCenterPos(FIntPoint _Index);

	FIntPoint PosToIndex(float4 _Pos);


	void InfinityGroundCheck();
	void SpawnMonsterRandomLocation();

private:
	FIntPoint CurIndex;

};

