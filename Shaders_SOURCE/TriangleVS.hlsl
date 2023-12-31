
struct VTX_IN
{
    float3 vPos : POSITION;
    float4 vColor : COLOR;
};

struct VTX_OUT
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR;
};

cbuffer Transform : register(b0)
{
    float3 cbPos;
    int padd1;
    float3 cbScale;
    int padd2;
};

VTX_OUT VS_Test(VTX_IN _in)
{
    VTX_OUT output = (VTX_OUT) 0.f;
    
    output.vPos = float4(_in.vPos + cbPos.xyz, 1.f);
    output.vPos.y /= 9;
    output.vPos.x /= 16;
    output.vPos.xy *= cbScale;
    
    output.vColor = _in.vColor;
    
    return output;
}
