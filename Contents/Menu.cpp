#include "PreCompile.h"
#include "Menu.h"
#include "Burtton.h"

AMenu::AMenu()
{



}

AMenu::~AMenu()
{
}

void AMenu::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 8; i++)
	{
		Burton = GetWorld()->SpawnActor<ABurtton>("Burton");
		Burton->SetActorLocation({430.0f, 220.0f - (i*70.0f)});
	}
}





void AMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}


