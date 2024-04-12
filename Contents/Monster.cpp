#include "PreCompile.h"
#include "Monster.h"
#include "Player.h"



AMonster::AMonster()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

AMonster::~AMonster()
{
}

void AMonster::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Bubba", "Bubba", 0.1f, true, 0, 2);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->ChangeAnimation("Bubba");
}


void AMonster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector MonsterPos = GetActorLocation();


	FVector MonsterDir = APlayer::PlayerPos - MonsterPos;
	FVector MonsterDirNormal = MonsterDir.Normalize2DReturn();
	AddActorLocation(MonsterDirNormal * _DeltaTime * MoveSpeed);
	if (MonsterPos.X > APlayer::PlayerPos.X)
	{
		Renderer->SetDir(EEngineDir::Left);
	}
	else
	{
		Renderer->SetDir(EEngineDir::Right);
	}


}



