#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{


	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);


	TitleBack = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleBack->SetupAttachment(Root);
	TitleBack->SetPivot(EPivot::BOT);

	SetRoot(Root);

}

ATitleLogo::~ATitleLogo()
{
}


void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));

	// Renderer->SetSprite("CharWalk1_0.png");

	Renderer->SetSprite("HoloTitle.png");
	Renderer->SetPosition(FVector({0.7f, 0.0f }));
	Renderer->SetOrder(ERenderOrder::Title);


	TitleBack->SetSprite("menu_charselec_bar_0.png");
	TitleBack->SetScale(FVector{1.5f,2.0f});
	TitleBack->SetPosition(FVector{ 0.0f,-0.7f });
	TitleBack->SetOrder(ERenderOrder::Title);
}

void ATitleLogo::BackMove(float _DeltaTime)
{
	TitleBack->AddPosition(FVector::Left * _DeltaTime * MoveSpeed);
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BackMove(_DeltaTime);
	
	int a = 0;
}

