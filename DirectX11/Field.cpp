/*system header*/
#include "Main.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
/*scenes header*/
/*gameobjects header*/
/*self header*/
#include "Field.h"

void CField::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = XMFLOAT3(-10.0f, 0.0f, 10.0f);
	vertex[0].Normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = XMFLOAT2(0.0f, 0.0f);

	vertex[1].Position = XMFLOAT3(10.0f, 0.0f, 10.0f);
	vertex[1].Normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = XMFLOAT2(2.0f, 0.0f);

	vertex[2].Position = XMFLOAT3(-10.0f, 0.0f, -10.0f);
	vertex[2].Normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = XMFLOAT2(0.0f, 2.0f);

	vertex[3].Position = XMFLOAT3(10.0f, 0.0f, -10.0f);
	vertex[3].Normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = XMFLOAT2(2.0f, 2.0f);

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	CRenderer::GetDevice()->CreateBuffer(&bd, &sd, m_VertexBuffer.GetAddressOf());

	// m_VertexShader
	CRenderer::CreateVertexShader(m_VertexShader.GetAddressOf(), m_VertexLayout.GetAddressOf(), "normalMapVS.cso");
	// m_PixelShader
	CRenderer::CreatePixelShader(m_PixelShader.GetAddressOf(), "normalMapPS.cso");

	// m_Texture
	CreateDDSTextureFromFile(CRenderer::GetDevice().Get(), L"../Asset/Texture/rocktexture.dds", nullptr, m_Texture.GetAddressOf());
	assert(m_Texture);

	// m_TextureNormal
	CreateDDSTextureFromFile(CRenderer::GetDevice().Get(), L"../Asset/Texture/rocknormal.dds", nullptr, m_TextureNormal.GetAddressOf());
	assert(m_TextureNormal);

	// m_TextureHeight
	CreateDDSTextureFromFile(CRenderer::GetDevice().Get(), L"../Asset/Texture/rockdisplacement.dds", nullptr, m_TextureHeight.GetAddressOf());
	assert(m_TextureHeight);


	m_Position = XMFLOAT3(0.0f, 0.5f, 0.0f);
	m_RotationEuler = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_Scale = XMFLOAT3(1.0f, 1.0f, 1.0f);
	m_Rotation = XMQuaternionIdentity();
}

void CField::Uninit()
{
}

void CField::Update()
{
}

void CField::Draw()
{
	// Set InputLayout
	CRenderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout.Get());
	// Set Shader
	CRenderer::GetDeviceContext()->VSSetShader(m_VertexShader.Get(), nullptr, 0);
	CRenderer::GetDeviceContext()->PSSetShader(m_PixelShader.Get(), nullptr, 0);

	// Set MVP
	// W = SRT
	XMMATRIX world, scale, rot, trans;
	scale = XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
	/*rot = XMMatrixRotationRollPitchYaw(m_RotationEuler.z, m_RotationEuler.x, m_RotationEuler.y);*/
	rot = XMMatrixRotationQuaternion(m_Rotation);
	XMQuaternionNormalize(m_Rotation);
	trans = XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	CRenderer::SetWorldMatrix(world);

	// Set VertexBuffer
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);

	// Set Material
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	material.Specular = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	material.Shininess = 60;
	CRenderer::SetMaterial(material);

	// Set ShaderResource
	CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, m_Texture.GetAddressOf());
	CRenderer::GetDeviceContext()->PSSetShaderResources(1, 1, m_TextureNormal.GetAddressOf());
	CRenderer::GetDeviceContext()->PSSetShaderResources(2, 1, m_TextureHeight.GetAddressOf());

	// Set PrimitiveTopology
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// Draw
	CRenderer::GetDeviceContext()->Draw(4, 0);
}
