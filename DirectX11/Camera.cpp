/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
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

	//CRenderer::SetCameraPosition(m_Position);
}
