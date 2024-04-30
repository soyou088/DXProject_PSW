#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class ACharacterSelection : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ACharacterSelection();
	~ACharacterSelection();

	// delete Function
	ACharacterSelection(const ACharacterSelection& _Other) = delete;
	ACharacterSelection(ACharacterSelection&& _Other) noexcept = delete;
	ACharacterSelection& operator=(const ACharacterSelection& _Other) = delete;
	ACharacterSelection& operator=(ACharacterSelection&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	

private:
	USpriteRenderer* CharacterSelection0;
	USpriteRenderer* CharacterSelection1;
	USpriteRenderer* CharacterSelection2;
};

