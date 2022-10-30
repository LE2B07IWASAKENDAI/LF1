#pragma once
#include"Scene.h"
class Play:public Scene
{
public:
	Play();
	~Play();

public:
	void Initialize()override;
	void Update()override;
	void Draw()override;
};

