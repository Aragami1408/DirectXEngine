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

			// test code
			static int i = 0;
			while (!wnd.mouse.IsEmpty()) {
				const auto e = wnd.mouse.Read();
				switch (e.GetType()) {
				case Mouse::Event::Type::WheelUp: {
					i++;
					std::ostringstream oss;
					oss << "Up: " << i;
					wnd.SetTitle(oss.str());
				} break;
				case Mouse::Event::Type::WheelDown: {
					i--;
					std::ostringstream oss;
					oss << "Down: " << i;
					wnd.SetTitle(oss.str());
				} break;
				}
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