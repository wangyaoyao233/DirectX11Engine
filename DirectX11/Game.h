#pragma once
#include "Scene.h"
class CGame :public CScene
{
public:
	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:
	float m_Pos[3]{ 0,0,0 };
};

