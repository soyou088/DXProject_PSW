#include "PreCompile.h"
#include "HoloCore.h"
#include "PlayGameMode.h"

UHoloCore::UHoloCore()
{
}

UHoloCore::~UHoloCore()
{
}

void UHoloCore::Initialize()
{
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	//{
	//	UEngineDirectory Dir;
	//	Dir.MoveToSearchChild("ContentsResources");
	//	Dir.Move("Sound");
	//	std::list<UEngineFile> Files = Dir.AllFile({ ".wav" });
	//	for (UEngineFile& File : Files)
	//	{
	//		UEngineSound::Load(File.GetFullPath());
	//	}
	//	UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	//}

}