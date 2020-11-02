/*system header*/
#include "Main.h"
#include "Renderer.h"
/*tools header*/
/*scenes header*/
#include "Game.h"
/*gameobjects header*/
/*self header*/
#include "Manager.h"

CScene* CManager::m_Scene = nullptr;


void CManager::Init()
{
	CRenderer::Init();

	SetScene<CGame>();
}

void CManager::Uninit()
{
	m_Scene->Uninit();
	delete m_Scene;
	m_Scene = nullptr;

	CRenderer::Uninit();
}

void CManager::Update()
{
	m_Scene->Update();
}

void CManager::Draw()
{
	CRenderer::Begin();
	m_Scene->Draw();

	CRenderer::End();
}
