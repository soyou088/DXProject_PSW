#include "PreCompile.h"
#include "AttackMelee.h"

AttackMelee::AttackMelee()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);

	SetRoot(Root);
}

AttackMelee::~AttackMelee()
{
}

void AttackMelee::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetOrder(ERenderOrder::Attack);
}

void AttackMelee::Tick(float _DeltaTime)
{
	AttackMelee::Tick(_DeltaTime);

	//공격이 보일때
	if (true == Renderer->IsActive())
	{
		//공격 애니메이션이 종료된 직후
		if (true == Renderer->IsCurAnimationEnd())
		{
			Renderer->SetActive(false);
		}
		else
		{
			int a = 0;
		}
	}
	else // 공격이 실행되지 않을 때
	{
		Angle = PlayerAngle;
		if (0 < Delay) // 공격 쿨이 돌기 전
		{
			Renderer->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			Delay -= _DeltaTime;
		}
		else // 공격 시작
		{
			Delay = AtkTime;
			Renderer->SetActive(true);
		}
	}
}

void AttackMelee::SetKnifeTypeMeleeLocation(float _DistanceFromPlayer)
{
	Dir = float4::DegToDir(Angle);
	Dir.Z = 0.0f;

	SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y + (20.0f * ContentsValue::MultipleSize) });
	AddActorLocation(Dir * _DistanceFromPlayer * ContentsValue::MultipleSize);
}