#pragma once
#include "sensorrepositoryfactory.h"
#include "../Repository/sensorrepositoryfake.h"
#include <utility>

SensorRepositoryFactory::SensorRepositoryFactory()
{     

}

std::unique_ptr<ISensorRepository>  SensorRepositoryFactory::CreateSensorRepository(bool isFake)
{
    return std::make_unique<SensorRepositoryFake>();
}

