#include "time_strings.h"
#include <format>
#include <ctime>
#include <iomanip>

static const char* FORMAT = "%Y-%m-%d %H:%M:%S";

std::chrono::time_point<std::chrono::system_clock> TimeParser::FromString(const std::string& timeString)
{
    std::tm tm_struct = {};
    std::istringstream ss(timeString);
    ss >> std::get_time(&tm_struct, FORMAT);

    if (ss.fail()) {
        throw std::runtime_error("Failed to parse time string.");
    }

    std::time_t time = std::mktime(&tm_struct);
    return std::chrono::system_clock::from_time_t(time);
}

std::string TimeParser::ToString(const std::chrono::time_point<std::chrono::system_clock>& time)
{
    return std::format("{:%Y-%m-%d %H:%M:%S}", time);
}