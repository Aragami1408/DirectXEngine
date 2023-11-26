#define WIN32_LEAN_AND_MEAN
#undef UNICODE

#include <stdio.h>
#include <sstream>

#include "DXEWin.h"
#include "Window.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	Window wnd(800, 300, "DirectX Game Window");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1) {
		return -1;
	}

	return msg.wParam;
}