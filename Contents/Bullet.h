#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// Ό³Έν :
class USpriteRenderer;
class ABullet : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABullet();
	~ABullet();

	// delete Function
	ABullet(const ABullet& _Other) = delete;
	ABullet(ABullet&& _Other) noexcept = delete;
	ABullet& operator=(const ABullet& _Other) = delete;
	ABullet& operator=(ABullet&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	UCollision* Collision;


};

