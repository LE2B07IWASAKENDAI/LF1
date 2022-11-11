#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

float Collision::Found(float player, float enemy,int flont)
{
	if (flont == 1) {
		if (player > enemy - range && player < enemy + character_Size)
		{
			found = 1;
		}
		else
		{
			found = 0;
		}
	}
	else if(flont ==0)
	{
		if (player + character_Size > enemy  && player < enemy + character_Size + range)
		{
			found = 1;
		}
		else
		{
			found = 0;
		}
	}

	return found;
}
