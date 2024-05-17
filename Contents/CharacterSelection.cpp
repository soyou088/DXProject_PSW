#include "PreCompile.h"
#include "CharacterSelection.h"
#include "CharacterSelectionButon.h"
#include "PlayGameMode.h"

ACharacterSelection::ACharacterSelection()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	CharacterSelection0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CharacterSelection0->SetupAttachment(Root);


	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetScale({ 85.0f, 80.0f });
	Collision->SetPosition({ 0.0f,230.0f });
	Collision->SetCollisionGroup(ECollisionOrder::Menu);
	Collision->SetCollisionType(ECollisionType::Rect);
	Collision->SetupAttachment(Root);


	SetRoot(Root);
	InputOn();
}

ACharacterSelection::~ACharacterSelection()
{
}

void ACharacterSelection::BeginPlay()
{
	Super::BeginPlay();


	//CharacterSelection = GetWorld()->SpawnActor<ACharacterSelection>("CharacterSelection");

	CharacterSelection0->SetSprite("menu_charselecLocked2_0.png");
	CharacterSelection0->SetAutoSize(2.0f, true);
	CharacterSelection0->SetPosition({ 0.0f,230.0f });
	CharacterSelection0->SetOrder(ERenderOrder::Player);
	
}

void ACharacterSelection::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Collision->CollisionEnter(ECollisionOrder::Mouse, [=](std::shared_ptr<UCollision> _Collison)
		{
			CharacterSelection0->SetSprite("menu_charselecLocked_0.png");
			ColChack = true;
		}
	);
	Collision->CollisionExit(ECollisionOrder::Mouse, [=](std::shared_ptr<UCollision> _Collison)
		{
			CharacterSelection0->SetSprite("menu_charselecLocked2_0.png");
			ColChack = false;
		}
	);

	if (true == IsDown(VK_LBUTTON) && true == ColChack)
	{
		GEngine->CreateLevel<APlayGameMode>("PlayLevel");
		GEngine->ChangeLevel("PlayLevel");
	}
}

