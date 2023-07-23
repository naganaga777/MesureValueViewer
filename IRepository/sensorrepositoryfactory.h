#ifndef SENSORREPOSITORYFACTORY_H
#define SENSORREPOSITORYFACTORY_H
#pragma once
#include "isensorrepository.h"
#include <memory>

class SensorRepositoryFactory
{
public:
    SensorRepositoryFactory();

    static std::unique_ptr<ISensorRepository> CreateSensorRepository(bool isFake = true);
};

#endif // SENSORREPOSITORYFACTORY_H
