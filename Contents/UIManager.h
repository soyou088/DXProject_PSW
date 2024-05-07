#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

// ���� :
class UIManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void UISpawn();
	void TimeUpdate(float _DeltaTime);
	void KillCountUpdate();
	void HPUpdate();
	void PauseChack();
	void CollisionChack();

	UImage* Character = nullptr;
	UImage* CharacterFrame = nullptr;
	UImage* HPBar = nullptr;
	UImage* HPBarBack = nullptr;
	UImage* EXPBar = nullptr;
	UImage* EXPBarBack = nullptr;
	UImage* HUDHP = nullptr;
	UImage* HUDFrame = nullptr;

	UImage* Weapon = nullptr;
	UImage* Item = nullptr;

	UImage* StageText = nullptr;
	UImage* Gold = nullptr;
	UImage* KillCount = nullptr;

	UImage* PuaseBack = nullptr;
	UImage* SetBack = nullptr;
	UImage* CharacterBack = nullptr;
	UImage* HP = nullptr;
	UImage* ATK = nullptr;
	UImage* SPD = nullptr;
	UImage* CRT = nullptr;
	UImage* PickUP = nullptr;
	UImage* Haste = nullptr;

	UImage* Charge = nullptr;

	UTextWidget* HPText = nullptr;
	UTextWidget* HPTextBack = nullptr;
	UTextWidget* TimeUI = nullptr;
	UTextWidget* GoldText = nullptr;
	UTextWidget* KillCountText = nullptr;
	UTextWidget* StateText = nullptr;
	UTextWidget* CharacterName = nullptr;

	// Stat Text
	UTextWidget* StatHPText = nullptr;
	UTextWidget* StatATKText = nullptr;
	UTextWidget* StatSPDText = nullptr;
	UTextWidget* StatCRTText = nullptr;
	UTextWidget* StatPickUPText = nullptr;
	UTextWidget* StatHasteText = nullptr;
	
	UTextWidget* PuaseSkillText = nullptr;
	UTextWidget* PuaseStampText = nullptr;
	UTextWidget* PuaseCollaborationText = nullptr;
	UTextWidget* PuaseContinueText = nullptr;
	UTextWidget* PuaseSettingText = nullptr;
	UTextWidget* PuaseExitText = nullptr;



	std::vector<UImage*> WeaponIconBack;
	std::vector<std::vector<UImage*>> WeaponIcon;

	std::vector<UImage*> ITemIconBack;
	std::vector<std::vector<UImage*>> ITemIcon;

	std::vector<UImage*> SetBurtonVector;
	std::vector<UImage*>::iterator SetBurtonIter = SetBurtonVector.begin();
	UCollision* SetBurtonCollision;

	std::vector<UImage*> StatLineVector;
	std::vector<UImage*>::iterator StatLineIter = StatLineVector.begin();

private:

};

