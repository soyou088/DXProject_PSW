#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// Ό³Έν :
class USpriteRenderer;
class AMonster : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	FVector PlayerLocation;
	float MoveSpeed = 100.f;
};

