#pragma once
#include "CharacterSelection.h"
#include "vector"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class ACharacterSelectionButon : public AActor
{
	GENERATED_BODY(AActor)
public:
	static std::vector<std::shared_ptr<ACharacterSelection>> CharacterSelections;
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

private:

};

