#include "PreCompile.h"
#include "TitleBack.h"

ATitleBack::ATitleBack()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	TitleBack = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleBack->SetupAttachment(Root);
	TitleBack->SetPivot(EPivot::BOT);

	SetRoot(Root);
}

ATitleBack::~ATitleBack()
{
}

void ATitleBack::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));
	TitleBack->SetSprite("menu_charselec_bar_0.png");
	TitleBack->SetScale(FVector{ 1.5f,3.5f });
	TitleBack->SetPosition(FVector{ 1.5f,-0.5f });
	TitleBack->SetOrder(ERenderOrder::Title);
}


void ATitleBack::BackMove(float _DeltaTime)
{
	TitleBack->AddPosition(FVector::Left * _DeltaTime * MoveSpeed);
}


void ATitleBack::Tick(float _DeltaTime)
{
	BackMove(_DeltaTime);
}
