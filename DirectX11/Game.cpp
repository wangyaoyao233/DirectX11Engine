/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
#include "Text.h"
/*scenes header*/
/*gameobjects header*/
#include "Light.h"
#include "Camera.h"
#include "Polygon.h"
#include "Player.h"
/*self header*/
#include "Game.h"

void CGame::Init()
{
	AddGameObject<CCamera>(0);
	AddGameObject<CPolygon>(2);
	AddGameObject<CPlayer>(1);

	CLight::InitResource();
}

void CGame::Uninit()
{
	CScene::Uninit();
}

void CGame::Update()
{
	CScene::Update();
}

void CGame::Draw()
{
	// 更新光线
	CLight::UpdateLightConstantBuffer();
	CScene::Draw();
	CText::Draw2DText(L"english, 中文, 日本語");
}