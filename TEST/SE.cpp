#include "SE.h"

void SE::CrackSE()
{
	PlaySoundFile("Resources/SE/SE01.mp3", DX_PLAYTYPE_BACK);
}

void SE::DiscoverSE_voice()
{
	PlaySoundFile("Resources/SE/EnemyVoice/DisVoice_SE.mp3", DX_PLAYTYPE_BACK);
}

void SE::KillSE_voice()
{
	PlaySoundFile("Resources/SE/EnemyVoice/Dvoice_SE06.mp3", DX_PLAYTYPE_BACK);
}
