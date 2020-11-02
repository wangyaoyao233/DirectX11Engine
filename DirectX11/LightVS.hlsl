#include "Common.hlsli"

void main(in VS_IN In, out PS_IN Out)
{
    matrix wvp;
    wvp = mul(World, View);
    wvp = mul(wvp, Projection);
    
    // wvp变换后的位置
    Out.Position = mul(In.Position, wvp);
    // 在世界中的位置
    Out.WorldPosition = mul(In.Position, World);
    // 在世界中的法向量   
    Out.Normal = normalize(mul(float4(In.Normal.xyz, 0.0f), World));
    
    Out.TexCoord = In.TexCoord;
    Out.Diffuse = In.Diffuse;
}