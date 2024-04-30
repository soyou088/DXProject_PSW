#pragma once
#include "SelectBack.h"
#include "SelectMenu.h"
#include "CharacterSelection.h"
#include "Mouse.h"
#include <EngineCore/GameMode.h>

// Ό³Έν :
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
	void SpawnSelectBack(float _DeltaTime);

private:

	std::list<std::shared_ptr<ASelectBack>> SelectBack;
	std::shared_ptr< ASelectMenu> SelectMenu;
	std::vector<std::shared_ptr<ACharacterSelection>> CharacterSelection;
	std::shared_ptr<AMouse> Mouse;
	float AttackTime = 0;
};
