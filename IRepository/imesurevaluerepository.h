#ifndef IMESUREVALUEREPOSITORY_H
#define IMESUREVALUEREPOSITORY_H

#include "Domain/mesurevalue.h"
#include "vector"


class IMesureValueRepository
{
public:
    IMesureValueRepository();

    virtual std::vector<MesureValue>  GetAllMesureValueList();
    virtual bool TrySave(MesureValue value) ;
};

#endif // IMESUREVALUEREPOSITORY_H
