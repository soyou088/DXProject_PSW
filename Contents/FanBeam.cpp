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
	Renderer->ChangeAnimation("FanBeam");

	SetKnifeTypeMeleeLocation(35.0f);

	Collision->SetActive(false);


}

void AFanBeam::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetKnifeTypeMeleeLocation(250.0f);

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
