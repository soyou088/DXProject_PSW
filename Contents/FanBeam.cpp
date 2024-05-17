#include "PreCompile.h"
#include "FanBeam.h"
#include "Monster.h"


AFanBeam::AFanBeam()
{
	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetScale({ 450.0f * ContentsValue::MultipleSize, 5 * ContentsValue::MultipleSize });
	Collision->SetCollisionGroup(ECollisionOrder::Weapon);
	Collision->SetCollisionType(ECollisionType::Rect);


}

AFanBeam::~AFanBeam()
{
}

void AFanBeam::BeginPlay()
{
	Super::BeginPlay();
	Name = "FanBeam";

	Renderer->CreateAnimation("FanBeam", "FanBeam", 0.05f);
	Renderer->SetAutoSize(ContentsValue::MultipleSize, true);
	Renderer->SetPosition(APlayer::PlayerPos);
	Renderer->ChangeAnimation("FanBeam");


	Collision->SetActive(false);

	SetKnifeTypeMeleeLocation(35.0f);


}
void AFanBeam::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetKnifeTypeMeleeLocation(250.0f);
	DirChack(Renderer->GetDir());



	if (true == Renderer->IsActive())
	{

		Collision->SetActive(true);
		Collision->SetPosition(Root->GetLocalPosition());
		Collision->AddPosition(Dir * ContentsValue::MultipleSize);


		CheckHit();
	}
	else
	{
		Collision->SetActive(false);
	}

	{
		FVector Pos = Root->GetLocalPosition() * Dir;
		UEngineDebugMsgWindow::PushMsg(std::format("RootPos : {}", Pos.ToString()));

	}

}
void AFanBeam::CheckHit()
{
	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			AMonster* Monster = dynamic_cast<AMonster*>(_Collison->GetActor());

			float Hp = Monster->GetHp();
			Hp -= Atk;
			Monster->SetHp(Hp);
		}
	);
}

void AFanBeam::DirChack(EEngineDir _Dir)
{
	Renderer->SetActive(true);
	Renderer->SetDir(_Dir);
	if (EEngineDir::Right == _Dir)
	{
		Renderer->SetPosition({ (1200.0f * ContentsValue::MultipleSize), (80.0f * ContentsValue::MultipleSize) });
		Collision->SetPosition({ (1200.0f * ContentsValue::MultipleSize), (80.0f * ContentsValue::MultipleSize) });
	}
	else if (EEngineDir::Left == _Dir)
	{
		Renderer->SetPosition({ (-1200.0f * ContentsValue::MultipleSize), (80.0f * ContentsValue::MultipleSize) });
		Collision->SetPosition({ (-1200.0f * ContentsValue::MultipleSize), (80.0f * ContentsValue::MultipleSize) });
	}
}
