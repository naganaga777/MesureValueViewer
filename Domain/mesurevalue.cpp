#include "mesurevalue.h"
#include "cmath"
#include <sstream>
#include <iostream>
#include <iomanip>

//コンストラクタ
MesureValue::MesureValue(float tempature,
                         float humidity,
                         std::chrono::system_clock::time_point time):
    m_tempatureValue(tempature),
    m_humidity(humidity),
    m_dateTime(time)
{

}

//測定値の表示文字列を取得する関数
std::string MesureValue::DisplayTempature() const
{
    int digits = 2;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(digits) << this->m_tempatureValue;
    std::string value = oss.str();
    return value + "℃";

}

std::string MesureValue::DisplayHumidity() const
{
    int digits = 2;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(digits) << this->m_humidity;
    std::string value = oss.str();
    return value + "%";
}
