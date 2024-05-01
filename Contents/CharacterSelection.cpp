#include "PreCompile.h"
#include "CharacterSelection.h"

ACharacterSelection::ACharacterSelection()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	CharacterSelection0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CharacterSelection0->SetupAttachment(Root);
	
	CharacterSelection1 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CharacterSelection1->SetupAttachment(Root);

	CharacterSelection2 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CharacterSelection2->SetupAttachment(Root);



	SetRoot(Root);
}

ACharacterSelection::~ACharacterSelection()
{
}

void ACharacterSelection::BeginPlay()
{
	Super::BeginPlay();


	//CharacterSelection = GetWorld()->SpawnActor<ACharacterSelection>("CharacterSelection");

	// 첫번쨰줄
	CharacterSelection0->SetSprite("menu_charselecLocked2_0.png");
	CharacterSelection0->SetAutoSize(2.0f, true);
	CharacterSelection0->SetPosition({ 0.0f,230.0f });
	CharacterSelection0->SetOrder(ERenderOrder::Player);
	

	//// 두번째줄
	//CharacterSelection1->SetSprite("menu_charselecLocked2_0.png");
	//CharacterSelection1->SetAutoSize(2.0f, true);
	//CharacterSelection1->SetPosition({ 0.0f,145.0f });
	//CharacterSelection1->SetOrder(ERenderOrder::Player);

	//// 세번쨰줄
	//CharacterSelection2->SetSprite("menu_charselecLocked2_0.png");
	//CharacterSelection2->SetAutoSize(2.0f, true);
	//CharacterSelection2->SetPosition({ 0.0f, 0.0f });
	//CharacterSelection2->SetOrder(ERenderOrder::Player);

		


		//for (int i = 0; i < 8; i++)
		//{
		//	Burton = GetWorld()->SpawnActor<ABurton>("Burton");
		//	Burton->SetActorLocation({ 430.0f, 220.0f - (i * 70.0f) });
		//}


}

void ACharacterSelection::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

