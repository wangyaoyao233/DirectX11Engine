/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
#include "input.h"
/*scenes header*/
/*gameobjects header*/
/*self header*/
#include "Camera.h"

void CCamera::Init()
{
	m_Position = XMFLOAT3(0.0f, 3.0f, -10.0f);
	m_Target = XMFLOAT3(0.0f, 0.0f, 0.0f);
}

void CCamera::Uninit()
{
}

void CCamera::Update()
{
	//载入 XMFLOAT3 的值
	XMVECTOR pos = XMLoadFloat3(&m_Position);

	if (CInput::GetKeyPress('H'))
	{
		pos -= g_XMIdentityR0;
	}
	if (CInput::GetKeyPress('K'))
	{
		pos += g_XMIdentityR0;
	}
	if (CInput::GetKeyPress('U'))
	{
		pos += g_XMIdentityR2;
	}
	if (CInput::GetKeyPress('J'))
	{
		pos -= g_XMIdentityR2;
	}
	if (CInput::GetKeyPress('Y'))
	{
		pos += g_XMIdentityR1;
	}
	if (CInput::GetKeyPress('I'))
	{
		pos -= g_XMIdentityR1;
	}

	XMStoreFloat3(&m_Position, pos);
}

void CCamera::Draw()
{
	//Set View Matrix
	XMMATRIX viewMatrix = XMMatrixLookAtLH(XMLoadFloat3(&m_Position), XMLoadFloat3(&m_Target), XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	XMStoreFloat4x4(&m_View, viewMatrix);
	CRenderer::SetViewMatrix(viewMatrix);

	//Set Projection Matrix
	XMMATRIX projectionMatrix = XMMatrixPerspectiveFovLH(1.0f, (float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);
	XMStoreFloat4x4(&m_Projection, projectionMatrix);
	CRenderer::SetProjectionMatrix(projectionMatrix);

	/*CRenderer::SetCameraPosition(m_Position);*/
}
