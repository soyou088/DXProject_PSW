#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/DefaultSceneComponent.h>


FVector APlayer::PlayerPos = FVector::Zero;

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	MouseRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MouseRenderer->SetScale(FVector(100.0f, 100.0f, 100.0f));
	MouseRenderer->SetupAttachment(Root);

	SetRoot(Root);

	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

		Renderer->CreateAnimation("KroniiIdle", "Kronii", 0.1f, true, 6, 9);
		Renderer->CreateAnimation("KroniiRun", "Kronii", 0.1f, true, 0 , 3);
		Renderer->SetAutoSize(1.0f, true);
		Renderer->SetOrder(ERenderOrder::Player);
		//Renderer->CreateAnimation("Die", "Die");
		if (true == IsDown(VK_LBUTTON))
		{
			MouseRenderer->SetSprite("spr_GameCursor1_0.png");
		}



		StateInit();
}


void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	


}




