#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include "Menu.h"
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
	Menu = GetWorld()->SpawnActor<AMenu>("Menu");


	std::shared_ptr<ATitleBack> InitialTitleBack = GetWorld()->SpawnActor<ATitleBack>("TitleBack");
	TitleBack.push_back(InitialTitleBack);

	FVector TPos = InitialTitleBack->GetActorLocation();
	for (int i = 1; i < 47; i++)
	{
		std::shared_ptr<ATitleBack> NewTitleBack = GetWorld()->SpawnActor<ATitleBack>("TitleBack");
		NewTitleBack->SetActorLocation({ TPos.X - 38 * i, TPos.Y });
		TitleBack.push_back(NewTitleBack);

	}

	Ame = GetWorld()->SpawnActor<ATitleCh>("Ame");
	Bae = GetWorld()->SpawnActor<ATitleCh>("Bae");
	Mumei = GetWorld()->SpawnActor<ATitleCh>("Mumei");
	Fauna = GetWorld()->SpawnActor<ATitleCh>("Fauna");
	Gura = GetWorld()->SpawnActor<ATitleCh>("Gura");
	Ina = GetWorld()->SpawnActor<ATitleCh>("Ina");
	Kiara = GetWorld()->SpawnActor<ATitleCh>("Kiara");
	Kronii = GetWorld()->SpawnActor<ATitleCh>("Kiara");


	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");


}


void ATitleGameMode::SpawnTitleBack(float _DeltaTime)
{
	if (0.1f <= AttackTime)
	{
		std::shared_ptr<ATitleBack> NewTitleBack = GetWorld()->SpawnActor<ATitleBack>("TitleBack");
		TitleBack.push_back(NewTitleBack);
		AttackTime = 0.0f;
	}
	AttackTime += _DeltaTime;
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsDown('P'))
	{
		GEngine->ChangeLevel("SelectLevel");
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