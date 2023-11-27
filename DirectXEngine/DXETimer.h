#pragma once
#include <chrono>

class DXETimer {
public:
    DXETimer();
    float Mark();
    float Peek() const;
private:
    std::chrono::steady_clock::time_point last;
};