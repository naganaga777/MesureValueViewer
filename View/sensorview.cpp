#include "sensorview.h"
#include "ui_sensorview.h"
#include <QWidget>

SensorView::SensorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorView)
{
    ui->setupUi(this);
    m_viewModel = std::make_unique<SensorViewModel>();
    connect(this->ui->btnStartMesure, &QPushButton::pressed,this,&SensorView::startMonitoringSensor);
    connect(this->ui->btnStopMesure ,&QPushButton::pressed,this, &SensorView::stopMonitoringSensor);
    connect(this->ui->btnSaveMesureValue,&QPushButton::pressed,this, &SensorView::saveMesureValue);
    this->setEvent();
}

SensorView::~SensorView()
{
    delete ui;
}

void SensorView::startMonitoringSensor()
{
    this->m_viewModel.get()->StartMonitoringSensor();
}

void SensorView::stopMonitoringSensor()
{
    this->m_viewModel.get()->StopMonitoringSensor();
}
void SensorView::saveMesureValue()
{
    this->m_viewModel.get()->SaveMesureValue();
}


void SensorView::setEvent()
{
    m_viewModel->SetEvent([&](const MesureValue& value)
    {
       this->ui->labelTempature->setText(value.DisplayTempature().c_str());
       this->ui->labelHumidity->setText(value.DisplayHumidity().c_str());

    });
}
