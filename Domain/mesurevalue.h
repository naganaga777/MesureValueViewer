#ifndef MESUREVALUE_H
#define MESUREVALUE_H

#include "string"
class MesureValue
{
public:

    //コンストラクタ
    MesureValue(float value);
    //測定値の表示文字列を取得する関数
    std::string DisplayValue()const;

private:
    //デフォルトコンストラクタ禁止
    MesureValue();

private:
    //測定値（rawValue）
    float m_value;
};

#endif // MESUREVALUE_H
