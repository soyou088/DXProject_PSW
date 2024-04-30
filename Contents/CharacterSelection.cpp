#include "PreCompile.h"
#include "CharacterSelection.h"

ACharacterSelection::ACharacterSelection()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	CharacterSelection = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CharacterSelection->SetupAttachment(Root);

	SetRoot(Root);
}

ACharacterSelection::~ACharacterSelection()
{
}

void ACharacterSelection::BeginPlay()
{
	Super::BeginPlay();

		CharacterSelection->SetSprite("menu_charselecLocked_0.png");
		CharacterSelection->SetAutoSize(2.0f, true);
		CharacterSelection->SetPosition({-200.0f, 10.0f});

}

void ACharacterSelection::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

