#pragma once
#include "isensorrepository.h"

ISensorRepository::ISensorRepository()
{

}

MesureValue ISensorRepository::GetValue()
{
    //具象クラスでオーバーライド
    return MesureValue(1);
}
