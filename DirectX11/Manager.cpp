/*system header*/
#include "Main.h"
#include "Renderer.h"
/*tools header*/
#include "CGUI.h"
/*scenes header*/
#include "Game.h"
/*gameobjects header*/
/*self header*/
#include "Manager.h"

CScene* CManager::m_Scene = nullptr;

bool flag = false;
float f = 0.0f;
ImVec4 clear_color{ 0.45f, 0.55f, 0.6f,1.0f };
int counter = 0;
bool show_another_window = true;
float f3[3]{ 0,0,0 };

void CManager::Init()
{
	CRenderer::Init();
	CGUI::Init();

	SetScene<CGame>();
}

void CManager::Uninit()
{
	m_Scene->Uninit();
	delete m_Scene;
	m_Scene = nullptr;


	CGUI::Uninit();
	CRenderer::Uninit();
}

void CManager::Update()
{
	{
		// Start the Dear ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	m_Scene->Update();




	//ImGui::Begin("Hello, world!");
	//ImGui::Text("This is some useful text.");
	//ImGui::Checkbox("Demo Window", &flag);
	//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
	//ImGui::ColorEdit3("clear color", (float*)&clear_color);
	//if (ImGui::Button("Button"))
	//	counter++;
	//ImGui::SameLine();
	//ImGui::Text("counter = %d", counter);

	//ImGui::DragFloat3("Drag float3", f3, 0.0f, 1.0f);
	//ImGui::SliderFloat3("Slider float3", f3, 0.0f, 1.0f);
	//ImGui::InputFloat3("Input float3", f3);


	//ImGui::End();

	//ImGui::Begin("Another window", &show_another_window);
	//ImGui::Text("Hello from another window!");
	//if (ImGui::Button("Close Me"))
	//	show_another_window = false;
	//ImGui::End();
	
}

void CManager::Draw()
{
	CRenderer::Begin();
	m_Scene->Draw();

	{
		//ImGui Rendering
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
	CRenderer::End();
}
