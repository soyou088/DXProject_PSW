#include "PreCompile.h"
#include "Kiara.h"
#include "Monster.h"

AKiara::AKiara()
{
	CollisionR0 = CreateDefaultSubObject<UCollision>("Collision");
	CollisionR0->SetScale({ 50.0f * ContentsValue::MultipleSize, 50.f * ContentsValue::MultipleSize });
	CollisionR0->SetCollisionGroup(ECollisionOrder::Weapon);
	CollisionR0->SetCollisionType(ECollisionType::RotRect);

	CollisionR1 = CreateDefaultSubObject<UCollision>("Collision");
	CollisionR1->SetScale({ 50.0f * ContentsValue::MultipleSize, 50.f * ContentsValue::MultipleSize });
	CollisionR1->SetCollisionGroup(ECollisionOrder::Weapon);

}

AKiara::~AKiara()
{
}

void AKiara::BeginPlay()
{
	Super::BeginPlay();

	Name = "KiaraWeapon";

	Renderer->CreateAnimation("KiaraAttack", "KiaraAttack", 0.05f);
	Renderer->SetAutoSize(ContentsValue::MultipleSize, true);
	Renderer->ChangeAnimation("KiaraAttack");

	SetKnifeTypeMeleeLocation(35.0f);
	CollisionR0->SetActive(false);
	CollisionR1->SetActive(false);
}

void AKiara::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SetKnifeTypeMeleeLocation(35.0f);

	if (true == Renderer->IsActive())
	{

		CollisionR0->SetActive(true);
		CollisionR0->SetPosition(Root->GetLocalPosition());
		CollisionR0->AddPosition(Dir * 50.0f * ContentsValue::MultipleSize);

		CollisionR1->SetActive(true);
		CollisionR1->SetRotationDeg(FVector(Root->GetLocalRotation().X, Root->GetLocalRotation().Y, Root->GetLocalRotation().Z + 45.f));
		CollisionR1->SetPosition(FVector(Root->GetLocalPosition().X,Root->GetLocalPosition().Y, Root->GetLocalPosition().Z));
		CollisionR1->AddPosition(Dir * 50.0f * ContentsValue::MultipleSize);
		CheckHit();
	}
	else
	{
		CollisionR0->SetActive(false);
		CollisionR1->SetActive(false);
	}

	{

		FVector Pos = Root->GetLocalPosition() * Dir;
		UEngineDebugMsgWindow::PushMsg(std::format("RootPos : {}", Pos.ToString()));
	}
}

void AKiara::CheckHit()
{
	CollisionR0->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			AMonster* Monster = dynamic_cast<AMonster*>(_Collison->GetActor());

			float Hp = Monster->GetHp();
			Hp -= Atk;
			Monster->SetHp(Hp);
		}
	);
}