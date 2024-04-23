#include "PreCompile.h"
#include "TitleCh.h"

TitleCh::TitleCh()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Ame = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Ame->SetupAttachment(Root);
	Ame->SetPivot(EPivot::BOT);
	//Bae;
	//Gura;
	//Mumei;
	//Fauna;
	//Suisei;
	//Sana;
	//Shion;
	//Sora;
	//Subaru;
	//Mio;
	//Okayu;
	//Roboco;
	//Kronii;
	//Matsuri;
	//Mel;
	//Miko;
	//Ina;
	//Irys;
	//Kiara;
	//Korone;
	//Fubuki;
	//Haato;
	//Azki;
	//Calli;
	//Choco;
	//Aki;
	//Ayame;
	//Aqua;
	SetRoot(Root);
}

TitleCh::~TitleCh()
{
}

void TitleCh::BeginPlay()
{
	Super::BeginPlay();
}

void TitleCh::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

