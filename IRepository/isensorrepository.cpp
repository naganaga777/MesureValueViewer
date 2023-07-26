#pragma once
#include "isensorrepository.h"
#include "chrono"

ISensorRepository::ISensorRepository()
{

}

MesureValue ISensorRepository::GetValue()
{
    //具象クラスでオーバーライド
    return MesureValue(1.0,1.0,std::chrono::system_clock::now());
}
