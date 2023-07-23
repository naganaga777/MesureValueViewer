#ifndef SENSORVIEWMODEL_H
#define SENSORVIEWMODEL_H
#include "IRepository/isensorrepository.h"
#include "IRepository/imesurevaluerepository.h"
#include "functional"
#include "memory"
#include <chrono>
#include <thread>
#include "string"
#include "Domain/mesurevalue.h"
#include "thread"

class SensorViewModel
{
public:
    SensorViewModel();
    void StartMonitoringSensor();
    void StopMonitoringSensor();
    void SetEvent(std::function<void(const MesureValue&)> func);


private:
     std::unique_ptr<ISensorRepository> m_sensorRepositry;
     std::shared_ptr<IMesureValueRepository> m_mesureValueRepository;//他のViewModelでも使用するからshared_ptr？？
     std::function<void(const MesureValue&)>  OnPropertyChanged;
     bool isEnableMonitoring =false;
     std::thread m_thread;

     void ThreadWork();
};

#endif // SENSORVIEWMODEL_H
