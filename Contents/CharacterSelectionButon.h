#pragma once
#include "CharacterSelection.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class ACharacterSelectionButon : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ACharacterSelectionButon();
	~ACharacterSelectionButon();

	// delete Function
	ACharacterSelectionButon(const ACharacterSelectionButon& _Other) = delete;
	ACharacterSelectionButon(ACharacterSelectionButon&& _Other) noexcept = delete;
	ACharacterSelectionButon& operator=(const ACharacterSelectionButon& _Other) = delete;
	ACharacterSelectionButon& operator=(ACharacterSelectionButon&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::shared_ptr<ACharacterSelection> CharacterSelection;
private:

};

