#pragma once
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

private:
	USpriteRenderer* MenuRenderer0;
	USpriteRenderer* MenuRenderer1;
	USpriteRenderer* MenuRenderer2;
	USpriteRenderer* MenuRenderer3;
	USpriteRenderer* MenuRenderer4;
	USpriteRenderer* MenuRenderer5;
	USpriteRenderer* MenuRenderer6;
	USpriteRenderer* MenuRenderer7;


	UCollision* Collision0;
	UCollision* Collision1;
	UCollision* Collision2;
	UCollision* Collision3;
	UCollision* Collision4;
	UCollision* Collision5;
	UCollision* Collision6;
	UCollision* Collision7;

};

