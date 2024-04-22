#include "PreCompile.h"
#include "Player.h"
#include "ContentsEnum.h"
#include "Mouse.h"
#include <EngineCore/Camera.h>


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
	Renderer->ChangeAnimation(Name + "_Idle");
}

void APlayer::RunStart()
{
	Renderer->ChangeAnimation(Name + "_Run");
}

void APlayer::Run(float _DeltaTime)
{

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();

	

	if (true == IsPress('W') && true == IsPress('A'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Up * _DeltaTime * LineSpeed);
		Renderer->SetDir(EEngineDir::Left);
		AddActorLocation(FVector::Left * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Left * _DeltaTime * LineSpeed);
		DirState = EActorDir::NW;
	}
	else if (true == IsPress('W') && true == IsPress('D'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Up * _DeltaTime * LineSpeed);
		Renderer->SetDir(EEngineDir::Right);
		AddActorLocation(FVector::Right * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Right * _DeltaTime * LineSpeed);
		DirState = EActorDir::NE;
	}
	else if (true == IsPress('S') && true == IsPress('A'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Down * _DeltaTime * LineSpeed);
		Renderer->SetDir(EEngineDir::Left);
		AddActorLocation(FVector::Left * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Left * _DeltaTime * LineSpeed);
		DirState = EActorDir::SW;
	}
	else if (true == IsPress('S') && true == IsPress('D'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Down * _DeltaTime * LineSpeed);
		Renderer->SetDir(EEngineDir::Right);
		AddActorLocation(FVector::Right * _DeltaTime * LineSpeed);
		Camera->AddActorLocation(FVector::Right * _DeltaTime * LineSpeed);
		DirState = EActorDir::SE;
	}

	else if (true == IsPress('A'))
	{
		Renderer->SetDir(EEngineDir::Left);
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Left * _DeltaTime * Speed);
		DirState = EActorDir::W;
		
	}
	else if (true == IsUp('A'))
	{
		Renderer->SetDir(EEngineDir::Left);
		State.ChangeState("Idle");
	}

	else if (true == IsPress('D'))
	{
		Renderer->SetDir(EEngineDir::Right);
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Right * _DeltaTime * Speed);
		DirState = EActorDir::E;
	}
	else if (true == IsUp('D'))
	{
		Renderer->SetDir(EEngineDir::Right);
		State.ChangeState("Idle");
	}

	else if (true == IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Up * _DeltaTime * Speed);
		DirState = EActorDir::N;
	}
	else if (true == IsUp('W'))
	{
		State.ChangeState("Idle");
	}

	else if (true == IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
		Camera->AddActorLocation(FVector::Down * _DeltaTime * Speed);
		DirState = EActorDir::S;
	}
	else if (true == IsUp('S'))
	{
		State.ChangeState("Idle");
	}

}
