#include "PreCompile.h"
#include "Player.h"


FVector APlayer::PlayerPos = FVector::Zero;

APlayer::APlayer()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

		Renderer->CreateAnimation("AmeIdle", "Ame",0.1f, true,0,3);
		Renderer->CreateAnimation("AmeRun", "Ame", 0.1f, true, 5,10);
		//Renderer->CreateAnimation("Die", "Die");

		StateInit();
		Renderer->SetOrder(ERenderOrder::Player);


}


void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	
	PlayerPos = GetActorLocation();
}




