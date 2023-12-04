#include "App.h"

#include <iomanip>

App::App() : wnd(800, 600, "Direct3D 11 Game Engine - By Higanbana")
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
	// const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(1.0f,1.0f,1.0f);
	wnd.Gfx().DrawTestTriangle();
	wnd.Gfx().EndFrame();
}
