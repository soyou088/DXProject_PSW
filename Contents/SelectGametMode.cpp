#include "PreCompile.h"
#include "SelectGametMode.h"
#include "SelectMenu.h"
#include "CharacterSelection.h"
#include "CharacterSelectionButon.h"
#include "TitleGameMode.h"

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
	SelectMenu = GetWorld()->SpawnActor<ASelectMenu>("SelectMenu");
	CharacterSelectionButon = GetWorld()->SpawnActor<ACharacterSelectionButon>("CharacterSelectionButon");

	std::shared_ptr<ASelectBack> InitialSelectBack = GetWorld()->SpawnActor<ASelectBack>("SelectBack");
	SelectBack.push_back(InitialSelectBack);

	FVector TPos = InitialSelectBack->GetActorLocation();
	for (int i = 1; i < 47; i++)
	{
		std::shared_ptr<ASelectBack> NewSelectBack = GetWorld()->SpawnActor<ASelectBack>("SelectBack");
		NewSelectBack->SetActorLocation({ TPos.X - 38 * i, TPos.Y });
		SelectBack.push_back(NewSelectBack);

	}
	

	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");

}


void ASelectGametMode::SpawnSelectBack(float _DeltaTime)
{
	if (0.1f <= BackSpawnTime)
	{
		std::shared_ptr<ASelectBack> NewSelectBack = GetWorld()->SpawnActor<ASelectBack>("SelectBack");
		SelectBack.push_back(NewSelectBack);
		BackSpawnTime = 0.0f;
	}
	BackSpawnTime += _DeltaTime;
}


void ASelectGametMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AMouse::MouseCursorON = false;

	if (true == IsDown('P'))
	{
		GEngine->ChangeLevel("PlayLevel");
	}
	SpawnSelectBack(_DeltaTime);

	CursorOFF();
}

void ASelectGametMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);

}

void ASelectGametMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void ASelectGametMode::CursorOFF()
{
	ShowCursor(FALSE);
}