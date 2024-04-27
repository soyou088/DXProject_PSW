#pragma once
#include "SelectBack.h"
#include "Mouse.h"
#include <EngineCore/GameMode.h>

// ���� :
class ASelectGametMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	ASelectGametMode();
	~ASelectGametMode();

	// delete Function
	ASelectGametMode(const ASelectGametMode& _Other) = delete;
	ASelectGametMode(ASelectGametMode&& _Other) noexcept = delete;
	ASelectGametMode& operator=(const ASelectGametMode& _Other) = delete;
	ASelectGametMode& operator=(ASelectGametMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
	void SpawnTitleBack(float _DeltaTime);

private:

	std::list<std::shared_ptr<ASelectBack>> SelectBack;
	float AttackTime = 0;
};
