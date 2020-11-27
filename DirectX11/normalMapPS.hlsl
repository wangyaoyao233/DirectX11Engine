#include "LightHelper.hlsli"

Texture2D g_Texture : register(t0);
Texture2D g_TextureNormal : register(t1);
Texture2D g_TextureDisplacement : register(t2);

SamplerState g_SamplerState : register(s0);

void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{ 
    // 眼睛指向顶点的向量
    float3 fromEyeW = normalize(In.WorldPosition.xyz - Camera.xyz);
    // 顶点指向眼睛的向量
    float3 toEyeW = normalize(Camera.xyz - In.WorldPosition.xyz);
    
    
    float2 tex = In.TexCoord;

    float4 normalMap = g_TextureNormal.Sample(g_SamplerState, tex) * 2.0 - 1.0;
    float4 normal = (-normalMap.x * In.Tangent) + (-normalMap.y * In.Binormal) + (normalMap.z * In.Normal);

    
    
    float4 texColor = g_Texture.Sample(g_SamplerState, tex);
    outDiffuse = ComputeCommonLights(In, texColor, normal.xyz, toEyeW);
}


/*
    float2 tex = In.TexCoord;

    float4 normalMap = g_TextureNormal.Sample(g_SamplerState, tex) * 2.0 - 1.0;
    float4 normal = (-normalMap.x * In.Tangent) + (-normalMap.y * In.Binormal) + (normalMap.z * In.Normal);
*/



/*
    float heightMax = 0.1;
    float step = 64;
    float heightScale = heightMax / step;
    
    float2 offset = fromEyeW.xy * heightScale;
    offset.x = -fromEyeW.x * heightScale / fromEyeW.y;
    offset.y = fromEyeW.z * heightScale / fromEyeW.y;
    
    float4 normalMap;
    float heightMap;
    float currentHeight = 0.0;
    
    float2 tex = In.TexCoord;
    tex.x = In.TexCoord.x + fromEyeW.x * heightMax / fromEyeW.y;
    tex.y = In.TexCoord.y - fromEyeW.z * heightMax / fromEyeW.y;
    
    for (int i = 0; i < step; ++i)
    {
        heightMap = 1 - g_TextureDisplacement.Sample(g_SamplerState, tex).r;
        
        if (currentHeight >= (heightMap) * heightMax)
        {
            break;
        }
        tex += offset;
        currentHeight += heightScale;
    }

    normalMap = g_TextureNormal.Sample(g_SamplerState, tex) * 2.0 - 1.0;
    float4 normal = (-normalMap.x * In.Tangent) + (-normalMap.y * In.Binormal) + (normalMap.z * In.Normal);

*/