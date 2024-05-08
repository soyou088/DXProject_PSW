#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include <EngineCore/Image.h>

// Ό³Έν :
class UBox : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	UBox();
	~UBox();

	// delete Function
	UBox(const UBox& _Other) = delete;
	UBox(UBox&& _Other) noexcept = delete;
	UBox& operator=(const UBox& _Other) = delete;
	UBox& operator=(UBox&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void ColChack();
private:
	USpriteRenderer* Box;
	USpriteRenderer* BoxAnimation;

	UCollision* Collision;

};

