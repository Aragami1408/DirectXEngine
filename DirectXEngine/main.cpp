#define WIN32_LEAN_AND_MEAN
#undef UNICODE

#include <stdio.h>
#include <sstream>

#include "DXEWin.h"
#include "DXEException.h"
#include "Window.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	try {
		Window wnd(1280, 720, "DirectX Game Window");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (wnd.kbd.KeyIsPressed(VK_MENU)) {
				MessageBox(nullptr, "Something Happon!", "Alt Key Was Pressed UwU", MB_OK | MB_ICONINFORMATION);
			}
		}

		if (gResult == -1) {
			return -1;
		}
		return (int) msg.wParam;
	}
	catch (const DXEException& e) {
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e) {
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...) {
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}

	return -1;
	
}