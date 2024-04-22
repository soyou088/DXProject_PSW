#include "PreCompile.h"
#include "Ranged.h"
#include "Player.h"


ARanged::ARanged()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);

	SetRoot(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale({ 10.0f,10.f });

	Collision->SetCollisionGroup(ECollisionOrder::Weapon);
	Collision->SetCollisionType(ECollisionType::Rect);



}

ARanged::~ARanged()
{
}

void ARanged::BeginPlay()
{
	Super::BeginPlay();
	//CreatePlayerAnimation("Ame");
	Renderer->CreateAnimation("AmeAttack", "AmeAttack", 0.1f, true);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->ChangeAnimation("AmeAttack");
	Renderer->SetOrder(ERenderOrder::Attack);


	SetActorLocation(AttackDir());

	if (false == AMouse::MouseCursorON)
	{
		AttackDir();
	}
	else if (true == AMouse::MouseCursorON)
	{
		AttackAimDir();
	}

}

void ARanged::CreatePlayerAnimation(std::string _Name)
{
	//Renderer->CreateAnimation(_Name + "Attack", _Name + "Attack", 0.1f, true, 0, 3);
}


FVector ARanged::AttackDir()
{

	if (AMelee::PlayerDir == EActorDir::E)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,0.0f });
		AtkDir = { 1,0,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::N)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
		AtkDir = { 0,1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::S)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
		AtkDir = {0,-1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::W)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
		AtkDir = { -1,0,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::NE)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
		AtkDir = { 1,1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::NW)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
		AtkDir = { -1,1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::SE)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
		AtkDir = { 1,-1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::SW)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
		AtkDir = { -1,-1,0,0 };
	}
	AtkDir = AtkDir.Normalize3DReturn();
	return FVector::Zero;
}

FVector ARanged::AttackAimDir()
{
	FVector MPos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WorldMPos = GetWorld()->GetMainCamera()->ScreenPosToWorldPos(MPos);

	AttackAngle = atan2f((ContentsValue::PlayLevelMousePos.Y - APlayer::PlayerPos.Y), (ContentsValue::PlayLevelMousePos.X - APlayer::PlayerPos.X)) * 180.0f / UEngineMath::PI;

	AtkDir = WorldMPos - APlayer::PlayerPos;
	SetActorRotation(FVector{ 0.0f,0.0f, AttackAngle });
	AtkDir = AtkDir.Normalize2DReturn();

	return FVector::Zero;
}

void ARanged::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == AMouse::MouseCursorON)
	{
		AddActorLocation(AtkDir * _DeltaTime  * RangedSpeed );
	}
	else
	{
		AddActorLocation(AtkDir * _DeltaTime * RangedSpeed );
	}

	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			_Collison->GetActor()->Destroy();
		}
	);

	



	CursorOFf();
}

void ARanged::CursorOFf()
{
	ShowCursor(FALSE);
}
