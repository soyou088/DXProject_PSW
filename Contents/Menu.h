#pragma once
#include "Burtton.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>


// Ό³Έν :
class AMenu : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMenu();
	~AMenu();

	// delete Function
	AMenu(const AMenu& _Other) = delete;
	AMenu(AMenu&& _Other) noexcept = delete;
	AMenu& operator=(const AMenu& _Other) = delete;
	AMenu& operator=(AMenu&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	bool CurCollision = false;
	
	std::shared_ptr<ABurtton> Burton;

private:


};

