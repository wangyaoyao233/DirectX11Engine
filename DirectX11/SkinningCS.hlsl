
//RWBuffer<float4> g_Data : register(u0);

//struct BONE
//{
//    matrix Matrix0;
//    matrix Matrix1;
//    matrix Matrix2;
//    matrix Matrix3;
//    matrix Result;
//    float4 Weight;
//};

//cbuffer Bone : register(b8)
//{
//    BONE bone;
//}

//[numthreads(16, 16, 1)]
//void main( uint3 DTid : SV_DispatchThreadID )
//{
//    bone.Result._11 = bone.Matrix0._11 * bone.Weight.x
//    + bone.Matrix1._11 * bone.Weight.y
//    + bone.Matrix2._11 * bone.Weight.z
//    + bone.Matrix3._11 * bone.Weight.w;
    
//    bone.Result._12 = bone.Matrix0._12 * bone.Weight.x
//    + bone.Matrix1._12 * bone.Weight.y
//    + bone.Matrix2._12 * bone.Weight.z
//    + bone.Matrix3._12 * bone.Weight.w;
    
//    bone.Result._13 = bone.Matrix0._13 * bone.Weight.x
//    + bone.Matrix1._13 * bone.Weight.y
//    + bone.Matrix2._13 * bone.Weight.z
//    + bone.Matrix3._13 * bone.Weight.w;
    
//    bone.Result._14 = bone.Matrix0._14 * bone.Weight.x
//    + bone.Matrix1._14 * bone.Weight.y
//    + bone.Matrix2._14 * bone.Weight.z
//    + bone.Matrix3._14 * bone.Weight.w;
    
    
//    bone.Result._21 = bone.Matrix0._21 * bone.Weight.x
//    + bone.Matrix1._21 * bone.Weight.y
//    + bone.Matrix2._21 * bone.Weight.z
//    + bone.Matrix3._21 * bone.Weight.w;
    
//    bone.Result._22 = bone.Matrix0._22 * bone.Weight.x
//    + bone.Matrix1._22 * bone.Weight.y
//    + bone.Matrix2._22 * bone.Weight.z
//    + bone.Matrix3._22 * bone.Weight.w;
    
//    bone.Result._23 = bone.Matrix0._23 * bone.Weight.x
//    + bone.Matrix1._23 * bone.Weight.y
//    + bone.Matrix2._23 * bone.Weight.z
//    + bone.Matrix3._23 * bone.Weight.w;
    
//    bone.Result._24 = bone.Matrix0._24 * bone.Weight.x
//    + bone.Matrix1._24 * bone.Weight.y
//    + bone.Matrix2._24 * bone.Weight.z
//    + bone.Matrix3._24 * bone.Weight.w;
    

    
//    bone.Result._31 = bone.Matrix0._31 * bone.Weight.x
//    + bone.Matrix1._31 * bone.Weight.y
//    + bone.Matrix2._31 * bone.Weight.z
//    + bone.Matrix3._31 * bone.Weight.w;
    
//    bone.Result._32 = bone.Matrix0._32 * bone.Weight.x
//    + bone.Matrix1._32 * bone.Weight.y
//    + bone.Matrix2._32 * bone.Weight.z
//    + bone.Matrix3._32 * bone.Weight.w;
    
//    bone.Result._33 = bone.Matrix0._33 * bone.Weight.x
//    + bone.Matrix1._33 * bone.Weight.y
//    + bone.Matrix2._33 * bone.Weight.z
//    + bone.Matrix3._33 * bone.Weight.w;
    
//    bone.Result._34 = bone.Matrix0._34 * bone.Weight.x
//    + bone.Matrix1._34 * bone.Weight.y
//    + bone.Matrix2._34 * bone.Weight.z
//    + bone.Matrix3._34 * bone.Weight.w;
    
    
    
//    bone.Result._41 = bone.Matrix0._41 * bone.Weight.x
//    + bone.Matrix1._41 * bone.Weight.y
//    + bone.Matrix2._41 * bone.Weight.z
//    + bone.Matrix3._41 * bone.Weight.w;
    
//    bone.Result._42 = bone.Matrix0._42 * bone.Weight.x
//    + bone.Matrix1._42 * bone.Weight.y
//    + bone.Matrix2._42 * bone.Weight.z
//    + bone.Matrix3._42 * bone.Weight.w;
    
//    bone.Result._43 = bone.Matrix0._43 * bone.Weight.x
//    + bone.Matrix1._43 * bone.Weight.y
//    + bone.Matrix2._43 * bone.Weight.z
//    + bone.Matrix3._43 * bone.Weight.w;
    
//    bone.Result._44 = bone.Matrix0._44 * bone.Weight.x
//    + bone.Matrix1._44 * bone.Weight.y
//    + bone.Matrix2._44 * bone.Weight.z
//    + bone.Matrix3._44 * bone.Weight.w;
//}