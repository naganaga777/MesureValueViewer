#ifndef SENSORVIEW_H
#define SENSORVIEW_H

#include <QWidget>
#include "ViewModel/sensorviewmodel.h"
#include <memory>

namespace Ui {
class SensorView;
}

class SensorView : public QWidget
{
    Q_OBJECT

public:
    explicit SensorView(QWidget *parent = nullptr);
    ~SensorView();

private:
    void startMonitoringSensor();
    void stopMonitoringSensor();
    void saveMesureValue();
    void setEvent();

private:
    Ui::SensorView *ui;
    std::unique_ptr<SensorViewModel> m_viewModel;

};

#endif // SENSORVIEW_H
