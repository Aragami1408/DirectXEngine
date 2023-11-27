#include "App.h"

App::App() : wnd(1280, 720, "DirectX Game Window")
{
}

int App::Go()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
		
	}

	if (gResult == -1) {
		throw DXEWND_LAST_EXCEPT();
	}
	return (int)msg.wParam;
}

void App::DoFrame()
{
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
