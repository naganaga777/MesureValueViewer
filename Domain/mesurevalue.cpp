#include "mesurevalue.h"
#include "cmath"
#include <sstream>
#include <iostream>
#include <iomanip>

//コンストラクタ
MesureValue::MesureValue(float value):
    m_value(value)
{

}

//測定値の表示文字列を取得する関数
std::string MesureValue::DisplayValue()const
{
    int digits = 2;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(digits) << this->m_value;
    std::string value = oss.str();
    return value+"m/s";

}
