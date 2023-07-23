#include "sensorviewmodel.h"
#include "IRepository/sensorrepositoryfactory.h"
#include "IRepository/mesurevaluerepositoryfactory.h"
#include "utility"

SensorViewModel::SensorViewModel()
{
    auto rep = SensorRepositoryFactory::CreateSensorRepository();
    this->m_sensorRepositry = std::move(rep);
    this->m_mesureValueRepository = MesureValueRepositoryFactory::CreateMesueValueRepository();
    isEnableMonitoring = false;
}

void SensorViewModel::StartMonitoringSensor()
{
    if(isEnableMonitoring){return;}
    isEnableMonitoring=true;
    this->m_thread = std::thread(&SensorViewModel::ThreadWork,this);
}

void SensorViewModel::StopMonitoringSensor()
{
    this->isEnableMonitoring = false;
    if(this->m_thread.joinable())
    {
        this->m_thread.join();
    }
}

void SensorViewModel::SetEvent(std::function<void(const MesureValue&)>func)
{
    this->OnPropertyChanged = func;
}


void SensorViewModel::ThreadWork()
{
    std::chrono::milliseconds interval(1000);
    while(isEnableMonitoring)
    {
        auto tmp = m_sensorRepositry.get()->GetValue();
        if(nullptr != this->OnPropertyChanged)
        {
            this->OnPropertyChanged(tmp);
        }
        std::this_thread::sleep_for(interval);
    }
}
