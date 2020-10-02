#pragma once
class CText
{
public:
	static void CreateDxgiSurfaceRenderTarget(ComPtr<IDXGISwapChain> pSwapChain, ComPtr<ID2D1Factory> pd2dFactory, ComPtr<IDWriteFactory> pdwriteFactory);
	static void Draw2DText(std::wstring text);
	static void ResetResource();

private:
	static ComPtr<ID2D1RenderTarget> m_pd2dRenderTarget;// D2D渲染目标

	static ComPtr<ID2D1SolidColorBrush> m_pColorBrush;// 单色笔刷
	static ComPtr<IDWriteFont> m_pFont;// 字体
	static ComPtr<IDWriteTextFormat> m_pTextFormat;// 文本格式
};

