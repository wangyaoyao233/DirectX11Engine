/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
/*scenes header*/
/*gameobjects header*/
/*self header*/
#include "Scene.h"

void CScene::Uninit()
{
	for (int i = 0; i < k_LayerNum; i++)
	{
		for (CGameObject* object : m_GameObject[i])
		{
			object->Uninit();
			delete object;
		}
		m_GameObject[i].clear();
	}
}

void CScene::Update()
{
	for (int i = 0; i < k_LayerNum; i++)
	{
		for (CGameObject* object : m_GameObject[i])
		{
			object->Update();
		}

		m_GameObject[i].remove_if(
			[](CGameObject* object)
			{
				return object->Destroy();
			});
	}
}

void CScene::Draw()
{
	for (int i = 0; i < k_LayerNum; i++)
	{
		for (auto object : m_GameObject[i])
		{
			object->Draw();
		}
	}
}
