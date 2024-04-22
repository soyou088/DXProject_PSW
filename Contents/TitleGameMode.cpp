#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include <EngineCore/Camera.h>

ATitleGameMode::ATitleGameMode()
{
	InputOn();
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	TitleLogo = GetWorld()->SpawnActor<ATitleLogo>("TitleLogo");
	TitleBack = GetWorld()->SpawnActor<ATitleBack>("Ranged");


}


void ATitleGameMode::SpawnRanged(float _DeltaTime)
{
	if (0.1f <= AttackTime)
	{
		TitleBack = GetWorld()->SpawnActor<ATitleBack>("Ranged");
		AttackTime = 0.0f;
	}
	AttackTime += _DeltaTime;
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsDown('P'))
	{
		GEngine->ChangeLevel("PlayLevel");
	}
	SpawnRanged(_DeltaTime);
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}