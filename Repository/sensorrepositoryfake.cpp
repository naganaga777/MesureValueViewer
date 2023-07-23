#include "sensorrepositoryfake.h"
#include <random>
SensorRepositoryFake::SensorRepositoryFake()
{

}

MesureValue SensorRepositoryFake::GetValue()
{
    //乱数を1.0から20.00の乱数

    std::random_device rnd;     // 非決定的な乱数生成器を生成
    std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    std::uniform_int_distribution<> rand100(101, 2000);        // [101, 2000] 範囲の一様乱数
    auto rand =  rand100(mt)/100.0;
    return MesureValue(rand);
}


