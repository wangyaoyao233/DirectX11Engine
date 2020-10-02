#pragma once
#include "Main.h"

struct DirectionalLight
{
	XMFLOAT4 Ambient;
	XMFLOAT4 Diffuse;
	XMFLOAT4 Specular;
	XMFLOAT3 Direction;
	float Pad;
};

struct PointLight
{
	PointLight() { memset(this, 0, sizeof(PointLight)); }

	XMFLOAT4 Ambient;
	XMFLOAT4 Diffuse;
	XMFLOAT4 Specular;

	//打包成4D向量: (Position, Range)
	XMFLOAT3 Position;
	float Range;

	//打包成4D向量: (A0, A1, A2, Pad)
	XMFLOAT3 Att;
	float Pad;
};

struct SpotLight
{
	SpotLight() { memset(this, 0, sizeof(SpotLight)); }

	XMFLOAT4 Ambient;
	XMFLOAT4 Diffuse;
	XMFLOAT4 Specular;

	//打包成4D向量: (Position, Range)
	XMFLOAT3 Position;
	float Range;

	//打包成4D向量: (Direction, Spot)
	XMFLOAT3 Direction;
	float Spot;

	//打包成4D向量: (A0, A1, A2, Pad)
	XMFLOAT3 Att;
	float Pad;
};