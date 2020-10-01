#include "Common.hlsli"

void main(in VS_IN In, out PS_IN Out)
{
    matrix wvp;
    wvp = mul(World, View);
    wvp = mul(wvp, Projection);
    
    Out.Position = mul(In.Position, wvp);
    Out.Diffuse = In.Diffuse;
}