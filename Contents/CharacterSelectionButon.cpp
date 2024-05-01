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
		// CharacterSelectionsº¤ÅÍÀÇ 0 ~ 9±îÁö
		std::shared_ptr<ACharacterSelection> Selection = GetWorld()->SpawnActor<ACharacterSelection>("test");
		Selection->SetActorLocation({ -425.0f - (i * -95.0f) ,0.0f });
	}
	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<ACharacterSelection> Selection = GetWorld()->SpawnActor<ACharacterSelection>("test");
		Selection->SetActorLocation({ -425.0f - (i * -95.0f),-85.0f });
	}
	for (int i = 0; i < 9; i++)
	{
		std::shared_ptr<ACharacterSelection> Selection = GetWorld()->SpawnActor<ACharacterSelection>("test");
		Selection->SetActorLocation({ -380.0f - (i * -95.0f),-170.0f });
	}
	for (int i = 0; i < 9; i++)
	{
		std::shared_ptr<ACharacterSelection> Selection = GetWorld()->SpawnActor<ACharacterSelection>("test");
		Selection->SetActorLocation({ -380.0f - (i * -95.0f),-255.0f });
	}

}

void ACharacterSelectionButon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

