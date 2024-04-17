#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// Ό³Έν :
class USpriteRenderer;
class AMelee : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMelee();
	~AMelee();

	// delete Function
	AMelee(const AMelee& _Other) = delete;
	AMelee(AMelee&& _Other) noexcept = delete;
	AMelee& operator=(const AMelee& _Other) = delete;
	AMelee& operator=(AMelee&& _Other) noexcept = delete;

	std::shared_ptr<AMelee> Melee;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer;
	UCollision* Collision;
};

