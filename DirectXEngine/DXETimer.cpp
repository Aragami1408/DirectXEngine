#include "DXETimer.h"

DXETimer::DXETimer()
{
    last = std::chrono::steady_clock::now();
}

float DXETimer::Mark()
{
    const auto old = last;
    last = std::chrono::steady_clock::now();
    const auto frameTime = last - old;
    return frameTime.count();
}

float DXETimer::Peek() const {
    return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
