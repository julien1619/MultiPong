#pragma once

#include <D3D11.h>
#include <D3DX11.h>
#include <dxerr.h>
#include <D3DCompiler.h>

class DX11Base
{
public:
	DX11Base(void);
	virtual ~DX11Base(void);

	bool Initialize(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();

	virtual bool LoadContent();
	virtual void UnloadContent();

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

	bool CompileD3DShader(char* filePath, char* entry, char* shaderModel, ID3DBlob** buffer);

protected:
	HINSTANCE hInstance_;
	HWND hwnd_;

	D3D_DRIVER_TYPE driverType_;
	D3D_FEATURE_LEVEL featureLevel_;

	ID3D11Device* d3dDevice_;
	ID3D11DeviceContext* d3dContext_;
	IDXGISwapChain* swapChain_;
	ID3D11RenderTargetView* backBufferTarget_;
};

