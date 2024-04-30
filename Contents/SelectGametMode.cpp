#include "PreCompile.h"
#include "SelectGametMode.h"

#include <EngineCore/Camera.h>


ASelectGametMode::ASelectGametMode()
{
	InputOn();
}

ASelectGametMode::~ASelectGametMode()
{
}

void ASelectGametMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<ASelectGametMode> InitialSelectBack = GetWorld()->SpawnActor<ASelectGametMode>("SelectBack");
	SelectBack.push_back(InitialSelectBack);

	FVector TPos = InitialSelectBack->GetActorLocation();
	for (int i = 1; i < 47; i++)
	{
		std::shared_ptr<ASelectGametMode> NewTitleBack = GetWorld()->SpawnActor<ASelectGametMode>("SelectBack");
		NewTitleBack->SetActorLocation({ TPos.X - 38 * i, TPos.Y });
		SelectBack.push_back(NewTitleBack);

	}

}


void ASelectGametMode::SpawnSelectBack(float _DeltaTime)
{
	if (0.1f <= AttackTime)
	{
		std::shared_ptr<ASelectGametMode> NewTitleBack = GetWorld()->SpawnActor<ASelectGametMode>("SelectBack");
		SelectBack.push_back(NewTitleBack);
		AttackTime = 0.0f;
	}
	AttackTime += _DeltaTime;
}


void ASelectGametMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == IsAnykeyDown())
	{
		GEngine->ChangeLevel("PlayLevel");
	}

	SpawnSelectBack(_DeltaTime);
}

void ASelectGametMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);

}

void ASelectGametMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
