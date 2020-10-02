/*system header*/
#include "Main.h"
#include "Renderer.h"
/*tools header*/
#include "Text.h"
/*scenes header*/

/*gameobjects header*/
#include "Polygon.h"
/*self header*/
#include "Manager.h"

CPolygon* g_Polygon;

void CManager::Init()
{
	CRenderer::Init();

	g_Polygon = new CPolygon();
	g_Polygon->Init();
}

void CManager::Uninit()
{
	CRenderer::Uninit();
}

void CManager::Update()
{
}

void CManager::Draw()
{
	CRenderer::Begin();

	g_Polygon->Draw();

	CText::Draw2DText(L"english, 中文, 日本語");

	CRenderer::End();
}
