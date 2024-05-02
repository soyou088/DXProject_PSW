#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Image.h>

// Ό³Έν :
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

	UImage* Character = nullptr;
	UImage* CharacterFrame = nullptr;
	UImage* HPBar = nullptr;
	UImage* HPBarBack = nullptr;
	UImage* EXPBar = nullptr;
	UImage* EXPBarBack = nullptr;
	UImage* HUDHP = nullptr;
	UImage* HUDFrame = nullptr;


	UImage* Gold = nullptr;
	UImage* Kill = nullptr;

private:

};

