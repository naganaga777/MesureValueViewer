#ifndef MESUREVALUEREPOSITORYFACTORY_H
#define MESUREVALUEREPOSITORYFACTORY_H
#include "IRepository/imesurevaluerepository.h"
#include "memory"

class MesureValueRepositoryFactory
{
public:
    MesureValueRepositoryFactory();
    static std::shared_ptr<IMesureValueRepository> CreateMesueValueRepository();
};

#endif // MESUREVALUEREPOSITORYFACTORY_H
