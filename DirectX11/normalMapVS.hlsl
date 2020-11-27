#include "common.hlsli"


void main(in VS_IN In, out PS_IN Out)
{
    matrix wvp;
    wvp = mul(World, View);
    wvp = mul(wvp, Projection);
    
    // wvp变换后的位置
    Out.Position = mul(In.Position, wvp);
    // 在世界中的位置
    Out.WorldPosition = mul(In.Position, World);
    
    // normal
    float4 worldNormal, normal;
    normal = float4(In.Normal.xyz, 0.0);
    worldNormal = mul(normal, World);
    worldNormal = normalize(worldNormal);   
    Out.Normal = worldNormal;
    
    Out.Diffuse = In.Diffuse;
    Out.TexCoord = In.TexCoord;
    
    // Tangent Binormal  
    Out.Tangent = normalize(mul(In.Tangent, World));
    Out.Binormal = normalize(mul(In.Binormal, World));
}