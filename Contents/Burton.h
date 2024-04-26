#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

// Ό³Έν :
class ABurton : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABurton();
	~ABurton();

	// delete Function
	ABurton(const ABurton& _Other) = delete;
	ABurton(ABurton&& _Other) noexcept = delete;
	ABurton& operator=(const ABurton& _Other) = delete;
	ABurton& operator=(ABurton&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CollisionCheck();
	bool CurCollision = false;


private:
	USpriteRenderer* MenuRenderer;


	UCollision* Collision;
};

