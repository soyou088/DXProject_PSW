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
	SelectBack.push_back

	FVector TPos = InitialSelectBack->GetActorLocation();
	for (int i = 1; i < 47; i++)
	{
		std::shared_ptr<ASelectGametMode> NewTitleBack = GetWorld()->SpawnActor<ASelectGametMode>("TitleBack");
		NewTitleBack->SetActorLocation({ TPos.X - 38 * i, TPos.Y });
		SelectBack.push_back(NewTitleBack);

	}

}

void ASelectGametMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
