#pragma once
#include "Window.h"
#include "DXETimer.h"
class App {
public:
    App();
    // master frame / message loop
    int Go();
    void DoFrame();
private:
    Window wnd;
    DXETimer timer;
};