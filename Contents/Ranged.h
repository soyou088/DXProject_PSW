#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// ���� :
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	UCollision* Collision;

	std::string Name = "Ame";
	void CreatePlayerAnimation(std::string _Name);
};
