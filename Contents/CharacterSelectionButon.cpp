#include "PreCompile.h"
#include "CharacterSelectionButon.h"
#include "CharacterSelection.h"

ACharacterSelectionButon::ACharacterSelectionButon()
{
}

ACharacterSelectionButon::~ACharacterSelectionButon()
{
}

void ACharacterSelectionButon::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 10; i++)
	{
		CharacterSelection = GetWorld()->SpawnActor<ACharacterSelection>("CharacterSelection");
		CharacterSelection->SetActorLocation({ -425.0f - (i*-95), 0.0f });
	}

}

void ACharacterSelectionButon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

