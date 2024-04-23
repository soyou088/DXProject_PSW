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
	TitleBack = GetWorld()->SpawnActor<ATitleBack>("TitleBack");

	FVector TPos = TitleBack->GetActorLocation();
	for (int i = 1; i < 47 ;i++)
	{
		TitleBack = GetWorld()->SpawnActor<ATitleBack>("TitleBack");
		TitleBack->SetActorLocation({ TPos.X - 38 * i, TPos.Y });

	}
}


void ATitleGameMode::SpawnTitleBack(float _DeltaTime)
{
	if (0.1f <= AttackTime)
	{
		TitleBack = GetWorld()->SpawnActor<ATitleBack>("TitleBack");
		AttackTime = 0.0f;
		TitleBack->DelayCallBack(0.5f, [this]()
			{
				TitleBack->Destroy();
			});
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

	SpawnTitleBack(_DeltaTime);
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}