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
	FVector AttackAimDir();

	void CursorOFf();
private:

	float4 AtkDir = float4::Right;

	std::string Name = "Ame";
	void CreatePlayerAnimation(std::string _Name);

	float AttackAngle;
	float AttackTime = 0;
	float Speed = 700.0f;
	float RangedSpeed = Speed * 0.75f;
};

