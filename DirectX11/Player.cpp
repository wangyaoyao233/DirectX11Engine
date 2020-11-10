/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
/*scenes header*/
/*gameobjects header*/
/*self header*/
#include "Player.h"

void CPlayer::Init()
{
	m_Model = new CAnimationModel();
	m_Model->Load("../Asset/Model/Akai_Idle.fbx");
	m_Model->LoadAnimation("../Asset/Model/Akai_Idle.fbx", "Idle");

	m_Model->SetInitAnimation("Idle");

	// shader
	CRenderer::CreateVertexShader(m_VertexShader.GetAddressOf(), m_VertexLayout.GetAddressOf(), "LightVS.cso");
	CRenderer::CreatePixelShader(m_PixelShader.GetAddressOf(), "LightPS.cso");

	m_Position = XMFLOAT3(0.0f, 0.5f, 0.0f);
	m_RotationEuler = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_Scale = XMFLOAT3(0.02f, 0.02f, 0.02f);
	m_Rotation = XMQuaternionIdentity();

	m_Frame = 0;
}

void CPlayer::Uninit()
{
	m_Model->UnLoad();
	delete m_Model;
}

void CPlayer::Update()
{
	m_Model->Update("Idle", m_Frame);
	m_Frame++;
}

void CPlayer::Draw()
{
	//Set InputLayout
	CRenderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout.Get());
	//Set Shader
	CRenderer::GetDeviceContext()->VSSetShader(m_VertexShader.Get(), nullptr, 0);
	CRenderer::GetDeviceContext()->PSSetShader(m_PixelShader.Get(), nullptr, 0);

	//W = SRT
	XMMATRIX world, scale, rot, trans;
	scale = XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
	/*rot = XMMatrixRotationRollPitchYaw(m_RotationEuler.z, m_RotationEuler.x, m_RotationEuler.y);*/
	rot = XMMatrixRotationQuaternion(m_Rotation);
	XMQuaternionNormalize(m_Rotation);
	trans = XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	CRenderer::SetWorldMatrix(world);

	m_Model->Draw();
}
