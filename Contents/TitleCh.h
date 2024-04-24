#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class ATitleCh : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ATitleCh();
	~ATitleCh();

	// delete Function
	ATitleCh(const ATitleCh& _Other) = delete;
	ATitleCh(ATitleCh&& _Other) noexcept = delete;
	ATitleCh& operator=(const ATitleCh& _Other) = delete;
	ATitleCh& operator=(ATitleCh&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:
	std::shared_ptr<ATitleCh> Ame;
	USpriteRenderer* Ame;
	USpriteRenderer* Bae;
	USpriteRenderer* Gura;
	USpriteRenderer* Mumei;
	USpriteRenderer* Fauna;
	USpriteRenderer* Suisei;
	USpriteRenderer* Sana;
	USpriteRenderer* Shion;
	USpriteRenderer* Sora;
	USpriteRenderer* Subaru;
	USpriteRenderer* Mio;
	USpriteRenderer* Okayu;
	USpriteRenderer* Roboco;
	USpriteRenderer* Kronii;
	USpriteRenderer* Matsuri;
	USpriteRenderer* Mel;
	USpriteRenderer* Miko;
	USpriteRenderer* Ina;
	USpriteRenderer* Irys;
	USpriteRenderer* Kiara;
	USpriteRenderer* Korone;
	USpriteRenderer* Fubuki;
	USpriteRenderer* Haato;
	USpriteRenderer* Azki;
	USpriteRenderer* Calli;
	USpriteRenderer* Choco;
	USpriteRenderer* Aki;
	USpriteRenderer* Ayame;
	USpriteRenderer* Aqua;
	USpriteRenderer* Melpitsa;
	USpriteRenderer* Olri;
	USpriteRenderer* Rice;
	USpriteRenderer* Eopiputin;

};

