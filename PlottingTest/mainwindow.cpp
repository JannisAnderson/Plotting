#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makeDataPlot(1500);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::makePlot1()
{
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    QPen pen;
    QStringList lineNames;
    lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
    // add graphs with different line styles:
    for (int i=QCPGraph::lsNone; i<=QCPGraph::lsImpulse; ++i)
    {
      ui->customPlot->addGraph();
      pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));
      ui->customPlot->graph()->setPen(pen);
      ui->customPlot->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
      ui->customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);
      ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
      // generate data:
      QVector<double> time(150), temp(150);
      for (int j=0; j<150; ++j)
      {
        time[j] = j;
        temp[j] = 7*qSin(time[j])/time[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
      }
      ui->customPlot->graph()->setData(time, temp);
      ui->customPlot->graph()->rescaleAxes(true);
    }
    // zoom out a bit:
    ui->customPlot->yAxis->scaleRange(1.1, ui->customPlot->yAxis->range().center());
    ui->customPlot->xAxis->scaleRange(1.1, ui->customPlot->xAxis->range().center());
    // set blank axis lines:
    ui->customPlot->xAxis->setTicks(true);
    ui->customPlot->yAxis->setTicks(true);
    ui->customPlot->xAxis->setTickLabels(false);
    ui->customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    ui->customPlot->axisRect()->setupFullAxesBox();
}

void MainWindow::makeDataPlot(int time_ms)
{
    // generate some data:
    QVector<double> x(time_ms), y(time_ms); // initialize with entries 0..100
    float* PT1000_08_T = getData(time_ms);
    for (int i=0; i<time_ms; ++i)
    {
      x[i] = i; // x goes from 0s - 9.9s
      y[i] = PT1000_08_T[i]; //Temp of sensor
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("Time [ms]");
    ui->customPlot->yAxis->setLabel("Temperatur [C]");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, time_ms);
    ui->customPlot->yAxis->setRange(0, 12);
    ui->customPlot->replot();
    qDebug() << "done baby";
}

float* MainWindow::getData(int ms)
{
    QFile file("C:/Users/janni/Desktop/OpenData/OpenData/HP_50.csv");   //make this sexier

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "file not open";
        return 0;
    }

    QTextStream in(&file);
    QString* read_data = new QString[ms];    //data for time after 0.i seconds

    for(int i=0; i<25; i++){
        read_data[0] = in.readLine(); //make so that data begin somewhere besides 25th line. (while)
    }
    for(int i=1; i<ms; i++){
        read_data[i] = in.readLine();
    }
    file.close();


    float* T_sensor = new float[ms];
    QStringList temp;

    for(int i=0; i<ms; i++){
        temp = read_data[i].split(",");
        T_sensor[i] = temp[25].toFloat();  // column 25 is PT1000_07
        //qDebug() << "t=" << i << ": " << T_sensor[i];
    }
    return T_sensor;
}
