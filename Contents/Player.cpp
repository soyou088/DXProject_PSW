#include "PreCompile.h"
#include "Player.h"


FVector APlayer::PlayerPos = FVector::Zero;

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

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
	Renderer->CreateAnimation("KroniiRun", "Kronii", 0.1f, true, 0, 3);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	//Renderer->CreateAnimation("Die", "Die");
	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");

	Mouse->SetActorLocation(PlayerPos);


	StateInit();
}


void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);

	PlayerPos = GetActorLocation();
	MousePos = GEngine->EngineWindow.GetScreenMousePos();
	MouseCursor = PlayerPos + MousePos;
	FVector MouseLocation = FVector{ PlayerPos.X + MousePos.X - 640, PlayerPos.Y - MousePos.Y + 360 };
	
	Mouse->SetActorLocation(MouseLocation);

	int a = 0;

}




