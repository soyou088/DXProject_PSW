#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// Ό³Έν :
class APlayer;
class USpriteRenderer;
class AMelee : public AActor
{
	GENERATED_BODY(AActor)
public:
	static EActorDir PlayerDir;
	// constrcuter destructer
	AMelee();
	~AMelee();

	// delete Function
	AMelee(const AMelee& _Other) = delete;
	AMelee(AMelee&& _Other) noexcept = delete;
	AMelee& operator=(const AMelee& _Other) = delete;
	AMelee& operator=(AMelee&& _Other) noexcept = delete;

	std::shared_ptr<AMelee> Melee;
	std::shared_ptr<APlayer> Player;

protected:
	void BeginPlay() override;
	
	void Tick(float _DeltaTime) override;
	void CursorOFF();



private:
	USpriteRenderer* Renderer;
	UCollision* Collision;


	void AttackDir();
	void AttackAimDir();
	void MeleeAttack(float _DeltaTime);
	float AttackAngle;
	float Angle = 0.0f;
	float Delay = 1.0f;

	float AttackTime = 0;
};

