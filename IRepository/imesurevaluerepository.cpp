#include "imesurevaluerepository.h"

IMesureValueRepository::IMesureValueRepository()
{

}


std::vector<MesureValue> IMesureValueRepository::GetAllMesureValueList()
{
    //具象クラスでオーバーライド
    return std::vector<MesureValue>{};
}

bool IMesureValueRepository::TrySave(MesureValue value)
{
    //具象クラスでオーバーライド

    return true;
}
