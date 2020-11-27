#include "LightHelper.hlsli"

Texture2D g_Texture : register(t0);
SamplerState g_SamplerState : register(s0);

void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{
    // 提前进行裁剪, 对不符合要求的像素可以避免后续运算
    float4 texColor = g_Texture.Sample(g_SamplerState, In.TexCoord);
    clip(texColor.a - 0.1f);
    
    // 再次标准化法向量
    In.Normal = normalize(In.Normal);
    
    // 顶点指向眼睛的向量
    float3 toEyeW = normalize(Camera.xyz - In.WorldPosition.xyz);
    
    outDiffuse = ComputeCommonLights(In, texColor, In.Normal.xyz, toEyeW);
}