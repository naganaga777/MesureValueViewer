#include "utility.h"
#include "sstream"
#include "iostream"
#include <iomanip>

Utility::Utility()
{

}

std::string Utility::Parse(std::chrono::system_clock::time_point time)
{
    // std::strftimeを使用してtime_pointを文字列に変換
    std::time_t t = std::chrono::system_clock::to_time_t(time);
    std::tm tm = *std::localtime(&t);
    char buffer[80];
//    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm);
    std::strftime(buffer, sizeof(buffer), std::string(Utility::dateFormat).c_str(), &tm);
    std::string timeString = buffer;
    return  timeString;
}

std::chrono::system_clock::time_point Utility::Parse(std::string timeString)
{
     // std::istringstreamを使用して文字列をストリームに読み込む
     std::istringstream iss(timeString);
     // std::tmを使用して年月日時分秒を取得
     std::tm tm = {};
//     iss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
     iss >> std::get_time(&tm, std::string(Utility::dateFormat).c_str());
     // std::mktimeを使用してstd::tmをstd::time_tに変換
     std::time_t t = std::mktime(&tm);
     // std::chrono::system_clock::from_time_tを使用してstd::time_tをtime_pointに変換
     std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(t);
     return timePoint;

}
