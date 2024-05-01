#pragma once
#include "TitleLogo.h"
#include "TitleBack.h"
#include "Menu.h"
#include "TitleCh.h"
#include "Mouse.h"
#include <EngineCore/GameMode.h>

// 설명 :
class ATitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	ATitleGameMode();
	~ATitleGameMode();

	// delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
	void SpawnTitleBack(float _DeltaTime);


private:
	std::shared_ptr<ATitleLogo> TitleLogo;
	std::list<std::shared_ptr<ATitleBack>> TitleBack;
	std::shared_ptr<AMenu> Menu;
	// 타이틀캐릭터
	std::shared_ptr<ATitleCh> Ame;
	std::shared_ptr<ATitleCh> Bae;
	std::shared_ptr<ATitleCh> Mumei;
	std::shared_ptr<ATitleCh> Fauna;
	std::shared_ptr<ATitleCh> Gura;
	std::shared_ptr<ATitleCh> Kronii;
	std::shared_ptr<ATitleCh> Suisei;
	std::shared_ptr<ATitleCh> Sana;
	std::shared_ptr<ATitleCh> Shion;
	std::shared_ptr<ATitleCh> Sora;
	std::shared_ptr<ATitleCh> Subaru;
	std::shared_ptr<ATitleCh> Mio;
	std::shared_ptr<ATitleCh> Okayu;
	std::shared_ptr<ATitleCh> Roboco;
	std::shared_ptr<ATitleCh> Matsuri;
	std::shared_ptr<ATitleCh> Mel;
	std::shared_ptr<ATitleCh> Miko;
	std::shared_ptr<ATitleCh> Ina;
	std::shared_ptr<ATitleCh> Irys;
	std::shared_ptr<ATitleCh> Kiara;
	std::shared_ptr<ATitleCh> Korone;
	std::shared_ptr<ATitleCh> Fubuki;
	std::shared_ptr<ATitleCh> Haato;
	std::shared_ptr<ATitleCh> Azki;
	std::shared_ptr<ATitleCh> Calli;
	std::shared_ptr<ATitleCh> Choco;
	std::shared_ptr<ATitleCh> Aki;
	std::shared_ptr<ATitleCh> Ayame;
	std::shared_ptr<ATitleCh> Aqua;
	std::shared_ptr<ATitleCh> Melpitsa;
	std::shared_ptr<ATitleCh> Olri;
	std::shared_ptr<ATitleCh> Rice;
	std::shared_ptr<ATitleCh> Eopiputin;
	std::shared_ptr<ATitleCh> Hosinoba;
	std::shared_ptr<ATitleCh> Laine;
	std::shared_ptr<ATitleCh> Kanaeru;
	std::shared_ptr<ATitleCh> Cobalskia;
	std::shared_ptr<ATitleCh> Zeta;

	std::shared_ptr<AMouse> Mouse;

	float AttackTime = 0;
	void CursorOFF();
};

