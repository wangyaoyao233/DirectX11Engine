#pragma once
#include "Scene.h"
class CManager
{
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();

	static CScene* GetScene() { return m_Scene; }

	template<typename T>
	static void SetScene()
	{
		if (m_Scene)//if m_Scene exited
		{
			m_Scene->Uninit();
			delete m_Scene;
			// CResource::UnloadAll();
		}
		//m_Scene pointer to new Scene
		T* scene = new T();
		m_Scene = scene;
		scene->Init();
	}

private:
	static CScene* m_Scene;
};

