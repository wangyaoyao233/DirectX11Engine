#pragma once
struct LightBuffer
{
	DirectionalLight dirLight[10];
	PointLight pointLight[10];
	SpotLight spotLight[10];
	int numDirLight;
	int numPointLight;
	int numSpotLight;
	float pad;
};

class CLight
{
public:
	void InitResource();

	void AddDirLight(DirectionalLight& light);
	void AddPointLight(PointLight& light);
	void AddSpotLight(SpotLight& light);

	void ResetDirLight(DirectionalLight& light, int id);
	void ResetPointLight(PointLight& light, int id);
	void ResetSpotLight(SpotLight& light, int id);

	void UpdateLightConstantBuffer();
private:
	ComPtr<ID3D11Buffer> m_LightBuffer;
	LightBuffer m_Light;
};

