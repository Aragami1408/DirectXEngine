#include "App.h"

#include <iomanip>

App::App() : wnd(1280, 720, "DirectX Game Window")
{
}

int App::Go()
{
	while (true) {
		if (const auto ecode = Window::ProcessMessages()) {
			return *ecode;
		}
		DoFrame();
		// Sleep(1); only uncomment this when the window title keeps changing at a fast pace
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c,c,1.0f);
	wnd.Gfx().EndFrame();
}
