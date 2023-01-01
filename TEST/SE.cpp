#include "SE.h"

void SE::Initialize()
{
	soundHandle[0] = LoadSoundMem("Resources/SE/SE01.mp3");
	soundHandle[1] = LoadSoundMem("Resources/SE/EnemyVoice/DisVoice_SE.mp3");
	soundHandle[2] = LoadSoundMem("Resources/SE/EnemyVoice/Dvoice_SE06.mp3");
}

void SE::CrackSE()
{
	PlaySoundMem(soundHandle[0], DX_PLAYTYPE_BACK);
}

void SE::DiscoverSE_voice()
{
	PlaySoundMem(soundHandle[1], DX_PLAYTYPE_BACK);
}

void SE::KillSE_voice()
{
	PlaySoundMem(soundHandle[2], DX_PLAYTYPE_BACK);
}
