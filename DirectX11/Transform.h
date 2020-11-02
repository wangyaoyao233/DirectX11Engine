#pragma once
class Transform
{
public:
    Transform() = default;
    Transform(const DirectX::XMFLOAT3 & scale, const DirectX::XMFLOAT3 & rotation, const DirectX::XMFLOAT3 & position);
    ~Transform() = default;

    Transform(const Transform&) = default;
    Transform& operator=(const Transform&) = default;

    Transform(Transform&&) = default;
    Transform& operator=(Transform&&) = default;

    // 获取对象缩放比例
    XMFLOAT3 GetScale() const;
    XMVECTOR GetScaleXM() const;

    // 获取对象欧拉角(弧度)
    // 对象以 Z-X-Y 轴顺序旋转
    XMFLOAT3 GetRotation() const;
    XMVECTOR GetRotationXM() const;

    // 获取对象位置
    XMFLOAT3 GetPosition() const;
    XMVECTOR GetPositionXM() const;

    // 获取右方向轴
    XMFLOAT3 GetRightAxis() const;
    XMVECTOR GetRightAxisXM() const;

    // 获取上方向轴
    XMFLOAT3 GetUpAxis() const;
    XMVECTOR GetUpAxisXM() const;

    // 获取前方向轴
    XMFLOAT3 GetForwardAxis() const;
    XMVECTOR GetForwardAxisXM() const;

    // 获取世界变换矩阵
    XMFLOAT4X4 GetLocalToWorldMatrix() const;
    XMMATRIX GetLocalToWorldMatrixXM() const;

    // 获取逆世界变换矩阵
    XMFLOAT4X4 GetWorldToLocalMatrix() const;
    XMMATRIX GetWorldToLocalMatrixXM() const;

    // 设置对象缩放比例
    void SetScale(const XMFLOAT3& scale);
    void SetScale(float x, float y, float z);

    // 设置对象欧拉角
    void SetRotation(const XMFLOAT3& eulerAnglesInRadian);
    // 对象以 Z-X-Y 轴顺序旋转
    void SetRotation(float x, float y, float z);

    // 设置对象位置
    void SetPosition(const XMFLOAT3& position);
    void SetPosition(float x, float y , float z);

    // 指定欧拉角旋转对象
    void Rotate(const XMFLOAT3& eulerAnglesInRadian);

    // 指定以原点为中心绕轴旋转
    void RotateAxis(const XMFLOAT3& axis, float radian);

    // 指定以 point 为旋转中心绕轴旋转
    void RotateAround(const XMFLOAT3& point, const XMFLOAT3& axis, float radian);

    // 沿某一方向平移
    void Translate(const XMFLOAT3& direction, float magnitude);

    // 观察某一点
    void LookAt(const XMFLOAT3& target, const XMFLOAT3& up = { 0.0f,1.0f,0.0f });

    // 沿着某以方向观察
    void LookTo(const XMFLOAT3& direction, const XMFLOAT3& up = { 0.0f,1.0f,0.0f });

private:
    // 从旋转矩阵获取旋转欧拉角
    XMFLOAT3 GetEulerAnglesFromRotationMatrix(const XMFLOAT4X4& rotationMatrix);
private:
    XMFLOAT3 m_Scale = { 1.0f,1.0f,1.0f };
    XMFLOAT3 m_Rotation = {};
    XMFLOAT3 m_Position = {};
};

