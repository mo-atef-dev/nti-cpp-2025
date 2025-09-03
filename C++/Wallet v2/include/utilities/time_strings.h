#pragma once

#include <chrono>
#include <string>

class TimeParser
{
    public:
    static std::chrono::time_point<std::chrono::system_clock> FromString(const std::string& timeString);
    static std::string ToString(const std::chrono::time_point<std::chrono::system_clock>& time);
};