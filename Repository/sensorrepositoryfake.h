#ifndef SENSORREPOSITORYFAKE_H
#define SENSORREPOSITORYFAKE_H
#include "../IRepository/isensorrepository.h"
#include "../Domain/mesurevalue.h"


class SensorRepositoryFake: public ISensorRepository
{
public:
    SensorRepositoryFake();

    MesureValue GetValue() override ;

};

#endif // SENSORREPOSITORYFAKE_H
