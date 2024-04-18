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

	void AttackDir();
	void AttackAimDir();
	void RangedMove(float _DeltaTime);
	void RangedAttack(float _DeltaTime);

	void CursorOFf();
private:
	USpriteRenderer* Renderer;
	UCollision* Collision;

	std::string Name = "Ame";
	void CreatePlayerAnimation(std::string _Name);

	float AttackAngle;
	float AttackTime = 0;
	float Speed = 300.0f;
	float RangedSpeed = Speed * 0.75f;
};

