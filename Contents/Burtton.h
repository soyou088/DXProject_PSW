#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

// Ό³Έν :
class ABurtton : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABurtton();
	~ABurtton();

	// delete Function
	ABurtton(const ABurtton& _Other) = delete;
	ABurtton(ABurtton&& _Other) noexcept = delete;
	ABurtton& operator=(const ABurtton& _Other) = delete;
	ABurtton& operator=(ABurtton&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CollisionCheck();
	bool CurCollision = false;


private:
	USpriteRenderer* MenuRenderer;

	UEngineSoundPlayer Sound;

	UCollision* Collision;
};

