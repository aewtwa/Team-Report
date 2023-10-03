// HLSL �� VertexShader �ۼ��ϱ�

struct VTX_OUT
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR;
};

cbuffer TRANSFORM : register(b2)
{
    float4 cbCol;
};

float4 PS_Test(VTX_OUT _in) : SV_Target
{
    return _in.vColor + cbCol;
}