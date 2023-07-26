#ifndef MESUREVALUE_H
#define MESUREVALUE_H

#include "string"
#include "chrono"
#include "/home/user/jsonlib/json.hpp"
#include "Utility/utility.h"



class MesureValue
{
public:
    //コンストラクタ
    MesureValue(){};
    MesureValue(float tempature,
                float humidity,
                std::chrono::system_clock::time_point time);
    //温度の表示文字列を取得する関数
    std::string DisplayTempature()const;
    //温度の表示文字列を取得する関数
    std::string DisplayHumidity()const;
    float Tempature()const{return m_tempatureValue;}
    float Humidity()const{return m_humidity;}
    std::chrono::system_clock::time_point DateIime()const {return m_dateTime;}


private:
    //温度（rawValue）
    float m_tempatureValue;
    //湿度（rawValue）
    float m_humidity;
    //計測日
    std::chrono::system_clock::time_point m_dateTime;
};







#endif // MESUREVALUE_H
