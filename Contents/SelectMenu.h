#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// ���� :
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

	void Chanimation();

private:
	USpriteRenderer* TopGround;
	USpriteRenderer* BackChaGroundL;
	USpriteRenderer* BackChaGroundR;

	USpriteRenderer* ChAnimation;

	USpriteRenderer* Explanation0;
	USpriteRenderer* Explanation1;
	USpriteRenderer* Explanation2;

	USpriteRenderer* ExplanationFrame;

	int Count = 0;
};
