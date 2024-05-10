#include "PreCompile.h"
#include "Wamy.h"
#include "Monster.h"

AWamy::AWamy()
{
	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetScale({ 50.0f * ContentsValue::MultipleSize, 50.f * ContentsValue::MultipleSize });
	Collision->SetCollisionGroup(ECollisionOrder::Weapon);
	Collision->SetCollisionType(ECollisionType::Rect);
}

AWamy::~AWamy()
{
}

void AWamy::BeginPlay()
{
	Super::BeginPlay();

	Name = "WamyWeapon";


	Renderer->CreateAnimation("Wamy", "Wamy", 0.05f);
	Renderer->SetAutoSize(ContentsValue::MultipleSize, true);
	Renderer->ChangeAnimation("Wamy");

	SetKnifeTypeMeleeLocation(35.0f);
	

	Collision->SetActive(false);

}

void AWamy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetKnifeTypeMeleeLocation(70.0f);

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

void AWamy::CheckHit()
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

