#ifndef MESUREVALUEJSONREPOSITORY_H
#define MESUREVALUEJSONREPOSITORY_H
#include "IRepository/imesurevaluerepository.h"
#include "Domain/mesurevalue.h"
#include <vector>

class MesureValueJsonRepository: public IMesureValueRepository
{
public:
    MesureValueJsonRepository();
    std::vector<MesureValue>  GetAllMesureValueList() override;

};

#endif // MESUREVALUEJSONREPOSITORY_H
