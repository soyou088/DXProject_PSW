#pragma once
#include <EngineCore/GameMode.h>
#include "PlayBack.h"
#include "Player.h"
// ���� :
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

//	std::vector<std::shared_ptr<APlayer>> BackList;
	std::vector<std::shared_ptr<APlayBack>> BackList;
private:
	

};

