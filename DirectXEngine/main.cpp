#define WIN32_LEAN_AND_MEAN
#undef UNICODE
#include <stdio.h>

#include <sstream>

#include "DXEWin.h"
#include "WindowsMessageMap.h"

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	static WindowsMessageMap mm;
	OutputDebugStringA(mm(msg, lParam, wParam).c_str());
	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'D') {
			SetWindowText(hWnd, "Respects");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F') {
			SetWindowText(hWnd, "DangerField");
		}
		break;
	case WM_CHAR: {
		static std::string title;
		title.push_back((char)wParam);
		SetWindowTextA(hWnd, title.c_str());
	} break;
	case WM_LBUTTONDOWN: {
		POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
	} break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = "Direct3D Engine";
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindowEx(
		0, wc.lpszClassName,
		"DirectX Game",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	ShowWindow(hWnd, SW_SHOW);

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1) return -1;
	else return msg.wParam;
}