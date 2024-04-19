#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// Ό³Έν :
class USpriteRenderer;
class ARanged : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARanged();
	~ARanged();

	// delete Function
	ARanged(const ARanged& _Other) = delete;
	ARanged(ARanged&& _Other) noexcept = delete;
	ARanged& operator=(const ARanged& _Other) = delete;
	ARanged& operator=(ARanged&& _Other) noexcept = delete;

	std::shared_ptr<ARanged> Ranged;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	float4 AttackDir();
	void AttackDirr(float _DeltaTime);
	FVector AttackAimDir();

	void CursorOFf();
private:
	USpriteRenderer* Renderer;
	UCollision* Collision;
	float4 AtkDir = float4::Zero;
	float4 MAtkDir = float4::Zero;

	std::string Name = "Ame";
	void CreatePlayerAnimation(std::string _Name);

	float AttackAngle;
	float AttackTime = 0;
	float Speed = 300.0f;
	float RangedSpeed = Speed * 0.75f;
};

