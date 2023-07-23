#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "View/sensorview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SensorView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//public Q_SLOTS:
    void showMesureWindow();


    //メンバ関数
private:
    void initializeViews();
    //メンバ変数
private:
    Ui::MainWindow *ui;
    SensorView *m_sensorView;



};
#endif // MAINWINDOW_H
