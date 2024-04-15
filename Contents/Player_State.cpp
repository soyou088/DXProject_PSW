#include "PreCompile.h"
#include "Player.h"
#include "ContentsEnum.h"
#include "Mouse.h"
#include <EngineCore/Camera.h>

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlayer::StateInit()
{
	// 스테이트 만들고
	State.CreateState("Die");
	State.CreateState("Idle");
	State.CreateState("Run");

	// 함수들 세팅하고
	State.SetUpdateFunction("Idle", std::bind(&APlayer::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", std::bind(&APlayer::IdleStart, this));


	State.SetUpdateFunction("Run", std::bind(&APlayer::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", std::bind(&APlayer::RunStart, this));
	// 체인지
	Renderer->SetAutoSize(1.0f, true);
	State.ChangeState("Idle");




	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();

}


void APlayer::Die(float _Update)
{

}

void APlayer::Idle(float _Update)
{
	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		State.ChangeState("Run");
		return;
	}

	if (true)
	{

	}
}

void APlayer::IdleStart()
{
	Renderer->ChangeAnimation("KroniiIdle");
}

void APlayer::RunStart()
{
	Renderer->ChangeAnimation("KroniiRun");
}

void APlayer::Run(float _DeltaTime)
{

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	float Speed = 500.0f;
	

	if (true == IsPress('A'))
	{
		Renderer->SetDir(EEngineDir::Left);
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Left * _DeltaTime * Speed);
		
	}
	if (true == IsUp('A'))
	{
		Renderer->SetDir(EEngineDir::Left);
		State.ChangeState("Idle");
	}

	if (true == IsPress('D'))
	{
		Renderer->SetDir(EEngineDir::Right);
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}
	if (true == IsUp('D'))
	{
		Renderer->SetDir(EEngineDir::Right);
		State.ChangeState("Idle");
	}

	if (true == IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}
	if (true == IsUp('W'))
	{
		State.ChangeState("Idle");
	}

	if (true == IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}
	if (true == IsUp('S'))
	{
		State.ChangeState("Idle");
	}

	if (true == IsPress(VK_NUMPAD1))
	{
		 //AddActorRotation(float4{0.0f, 0.0f, 1.0f} * 360.0f * _DeltaTime);
		 //Color.X += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD2))
	{
		Color.X -= _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD4))
	{
		Color.Y += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD5))
	{
		Color.Y -= _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD7))
	{
		Color.Z += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD8))
	{
		Color.Z -= _DeltaTime;
	}





}
