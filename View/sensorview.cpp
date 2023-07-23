#include "sensorview.h"
#include "ui_sensorview.h"
#include <QWidget>

SensorView::SensorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorView)
{
    ui->setupUi(this);
    m_viewModel = std::make_unique<SensorViewModel>();
    connect(this->ui->btnMesure, &QPushButton::pressed,this,&SensorView::startMonitoringSensor);
    connect(this->ui->btnStopMesure ,&QPushButton::pressed,this, &SensorView::stopMonitoringSensor);
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


void SensorView::setEvent()
{
    m_viewModel->SetEvent([&](const MesureValue& value)
    {
       this->ui->labelMesureValue->setText(value.DisplayValue().c_str());
    });
}
