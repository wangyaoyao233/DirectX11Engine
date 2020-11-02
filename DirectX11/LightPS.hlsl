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
    
    // 初始化为0
    float4 ambient = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 spec = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 A = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 D = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 S = float4(0.0f, 0.0f, 0.0f, 0.0f);
    
    int i;
    
    // 计算方向光
    for (i = 0; i < numDirLight; ++i)
    {
        ComputeDirectionalLight(Material, dirLight[i], In.Normal.xyz, toEyeW, A, D, S);
        ambient += A;
        diffuse += D;
        spec += S;
    }
    
         
    // 计算点光
    for (i = 0; i < numPointLight; ++i)
    {
        ComputePointLight(Material, pointLight[i], In.WorldPosition.xyz, In.Normal.xyz, toEyeW, A, D, S);
        ambient += A;
        diffuse += D;
        spec += S;
    }
        
    
    // 计算聚光灯
    for (i = 0; i < numSpotLight; ++i)
    {
        ComputeSpotLight(Material, spotLight[i], In.WorldPosition.xyz, In.Normal.xyz, toEyeW, A, D, S);
        ambient += A;
        diffuse += D;
        spec += S;
    }          
    
    float4 litColor = texColor * (ambient + diffuse) + spec;
    litColor.a = Material.Diffuse.a * In.Diffuse.a;
    
    outDiffuse = litColor;
}