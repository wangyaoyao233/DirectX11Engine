/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
#include "Text.h"
/*scenes header*/
/*gameobjects header*/
#include "Polygon.h"
/*self header*/
#include "Game.h"

void CGame::Init()
{
	AddGameObject<CPolygon>(2);
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
	CScene::Draw();
	CText::Draw2DText(L"english, 中文, 日本語");
}