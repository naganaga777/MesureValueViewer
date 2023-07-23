#ifndef IMESUREVALUEREPOSITORY_H
#define IMESUREVALUEREPOSITORY_H

#include "Domain/mesurevalue.h"
#include "vector"


class IMesureValueRepository
{
public:
    IMesureValueRepository();

    virtual std::vector<MesureValue>  GetAllMesureValueList();
};

#endif // IMESUREVALUEREPOSITORY_H
