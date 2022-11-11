#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

float Collision::Found(float player, float enemy)
{
	if (player > enemy - range && player < enemy + character_Size)
	{
		found = 1;
	}
	else
	{
		found = 0;
	}

	return found;
}
