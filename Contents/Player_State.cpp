#include "PreCompile.h"
#include "Player.h"
#include "Mouse.h"
#include <EngineCore/Camera.h>
#include <EngineCore/SpriteRenderer.h>

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
	Camera = GetWorld()->GetMainCamera();

	if (true == IsPress('W') && true == IsPress('A'))
	{
		if (false == AMouse::MouseCursorON)
		{
			Renderer->SetDir(EEngineDir::Left);
		}
		KeyLineMove(_DeltaTime, FVector::Up, FVector::Left);
		PlayerDir = EActorDir::NW;
	}
	else if (true == IsPress('W') && true == IsPress('D'))
	{
		if (false == AMouse::MouseCursorON)
		{
			Renderer->SetDir(EEngineDir::Right);
		}
		KeyLineMove(_DeltaTime, FVector::Up, FVector::Right);
		PlayerDir = EActorDir::NE;
	}
	else if (true == IsPress('S') && true == IsPress('A'))
	{
		if (false == AMouse::MouseCursorON)
		{
			Renderer->SetDir(EEngineDir::Left);
		}
		KeyLineMove(_DeltaTime, FVector::Down, FVector::Left);
		PlayerDir = EActorDir::SW;
	}
	else if (true == IsPress('S') && true == IsPress('D'))
	{
		if (false == AMouse::MouseCursorON)
		{
			Renderer->SetDir(EEngineDir::Right);
		}
		KeyLineMove(_DeltaTime, FVector::Down, FVector::Right);
		PlayerDir = EActorDir::SE;
	}
	else if (true == IsPress('A'))
	{
		if (false == AMouse::MouseCursorON)
		{
			Renderer->SetDir(EEngineDir::Left);
		}
		KeyMove(_DeltaTime, FVector::Left, CalSpeed);
		PlayerDir = EActorDir::W;
	}
	else if (true == IsPress('D'))
	{
		if (false == AMouse::MouseCursorON)
		{
			Renderer->SetDir(EEngineDir::Right);
		}
		KeyMove(_DeltaTime, FVector::Right, CalSpeed);
		PlayerDir = EActorDir::E;
	}
	else if (true == IsPress('W'))
	{
		KeyMove(_DeltaTime, FVector::Up, CalSpeed);
		PlayerDir = EActorDir::N;
	}
	else if (true == IsPress('S'))
	{
		KeyMove(_DeltaTime, FVector::Down, CalSpeed);
		PlayerDir = EActorDir::S;
	}

	if (true == IsUp('A') || true == IsUp('D') || true == IsUp('W') || true == IsUp('S'))
	{
		State.ChangeState("Idle");
	}
}

void APlayer::KeyMove(float _DeltaTime, float4 _Dir, float _Speed)
{
	AddActorLocation(_Dir * _DeltaTime * _Speed);
	Camera->AddActorLocation(_Dir * _DeltaTime * _Speed);
}

void APlayer::KeyLineMove(float _DeltaTime, float4 _Dir1, float4 _Dir2)
{
	KeyMove(_DeltaTime, _Dir1, LineSpeed);
	KeyMove(_DeltaTime, _Dir2, LineSpeed);
}