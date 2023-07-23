#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdialog.h>
#include <QWidget>
#include "./View/sensorview.h"
#include "ui_sensorview.h"
#include "QWidget"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->btnMesure, &QPushButton::pressed, this, &MainWindow::showMesureWindow);
    initializeViews();
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::showMesureWindow()
{
  this->m_sensorView->show();
}

void MainWindow::initializeViews()
{
  this->m_sensorView = new SensorView();
  this->m_sensorView->hide();


}

