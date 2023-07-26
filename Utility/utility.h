#ifndef UTILITY_H
#define UTILITY_H

#include "string"
#include "chrono"
#include "string_view"

class Utility
{
public:
    Utility();

    static std::string Parse(std::chrono::system_clock::time_point time);
    static std::chrono::system_clock::time_point Parse(std::string timeString);

private:
    static constexpr std::string_view dateFormat {R"(%Y-%m-%d %H:%M:%S)"};

};

#endif // UTILITY_H
