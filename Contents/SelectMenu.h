#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class ASelectMenu : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ASelectMenu();
	~ASelectMenu();

	// delete Function
	ASelectMenu(const ASelectMenu& _Other) = delete;
	ASelectMenu(ASelectMenu&& _Other) noexcept = delete;
	ASelectMenu& operator=(const ASelectMenu& _Other) = delete;
	ASelectMenu& operator=(ASelectMenu&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	USpriteRenderer* TopGround;
	USpriteRenderer* BackChaGround;
};

