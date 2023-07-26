#include "sensorrepositoryfake.h"
#include <random>
#include "chrono"
SensorRepositoryFake::SensorRepositoryFake()
{

}

MesureValue SensorRepositoryFake::GetValue()
{
    //乱数を101から3000の乱数
    std::random_device rndTemp;
    std::mt19937 mt(rndTemp());
    std::uniform_int_distribution<> randTemp(101, 4500);
    float tempature =  randTemp(mt)/100.0;


    std::random_device rndHum;
    std::random_device seed_gen;
    std::mt19937 mtHum{seed_gen()};
    std::uniform_int_distribution<> randHum(10,9999);
    float humidity = randHum(mtHum)/100.0;

    auto date = std::chrono::system_clock::now();

    return MesureValue(tempature,humidity,date);
}


