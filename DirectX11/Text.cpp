/*system header*/
#include "Main.h"
#include "DXTrace.h"
#include "d3dUtil.h"
#include "Renderer.h"
#include "Manager.h"
/*tools header*/
/*scenes header*/
/*gameobjects header*/
/*self header*/
#include "Text.h"

ComPtr<ID2D1RenderTarget> CText::m_pd2dRenderTarget;// D2D渲染目标
ComPtr<ID2D1SolidColorBrush> CText::m_pColorBrush;// 单色笔刷
ComPtr<IDWriteFont> CText::m_pFont;// 字体
ComPtr<IDWriteTextFormat> CText::m_pTextFormat;// 文本格式

void CText::CreateDxgiSurfaceRenderTarget(ComPtr<IDXGISwapChain> pSwapChain, ComPtr<ID2D1Factory> pd2dFactory, ComPtr<IDWriteFactory> pdwriteFactory)
{
	// 为D2D创建DXGI表面渲染目标
	ComPtr<IDXGISurface> surface;
	HR(pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), reinterpret_cast<void**>(surface.GetAddressOf())));
	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED));
	HRESULT hr = pd2dFactory->CreateDxgiSurfaceRenderTarget(surface.Get(), &props, m_pd2dRenderTarget.GetAddressOf());
	surface.Reset();

	if (hr == E_NOINTERFACE)
	{
		OutputDebugStringW(L"\n警告：Direct2D与Direct3D互操作性功能受限，你将无法看到文本信息。现提供下述可选方法：\n"
			L"1. 对于Win7系统，需要更新至Win7 SP1，并安装KB2670838补丁以支持Direct2D显示。\n"
			L"2. 自行完成Direct3D 10.1与Direct2D的交互。详情参阅："
			L"https://docs.microsoft.com/zh-cn/windows/desktop/Direct2D/direct2d-and-direct3d-interoperation-overview""\n"
			L"3. 使用别的字体库，比如FreeType。\n\n");
	}
	else if (hr == S_OK)
	{
		// 创建固定颜色刷和文本格式
		HR(m_pd2dRenderTarget->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::White),
			m_pColorBrush.GetAddressOf()));
		HR(pdwriteFactory->CreateTextFormat(L"微软雅黑", nullptr, DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 20, L"zh-cn",
			m_pTextFormat.GetAddressOf()));
	}
	else
	{
		// 报告异常问题
		assert(m_pd2dRenderTarget);
	}
}

void CText::Draw2DText(std::wstring text)
{
	//
	// 绘制Direct2D部分
	//
	if (m_pd2dRenderTarget != nullptr)
	{
		m_pd2dRenderTarget->BeginDraw();
		m_pd2dRenderTarget->DrawTextW(text.c_str(), (UINT32)text.size(), m_pTextFormat.Get(),
			D2D1_RECT_F{ 0.0f, 0.0f, 600.0f, 200.0f }, m_pColorBrush.Get());
		HR(m_pd2dRenderTarget->EndDraw());
	}
}

void CText::ResetResource()
{
	// 释放D2D的相关资源
	m_pColorBrush.Reset();
	m_pd2dRenderTarget.Reset();
}
