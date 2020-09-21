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
    MainWindow::getData();
    MainWindow::makeDataPlot(2000);
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
    QPen pen;

    for(int i=7; i<=40; i++)
    {
        QString name("PT1000_");
        float* PT1000_T = getPT1000Data(i, time_ms);
        for(int j=0; j<time_ms; ++j){
            x[j] = j;
            y[j] = PT1000_T[j];
        }
        ui->customPlot->addGraph();

        pen.setColor(QColor(ColorValues[i-7]));
        //pen.setColor(QColor(0xFF0000));
        ui->customPlot->graph()->setPen(pen);
        ui->customPlot->graph()->setData(x,y);
        ui->customPlot->graph()->setName(name.append(QString::number(i)));
        //ui->customPlot->graph()->setSelectable(stWhole);
    }
    //Title
    ui->customPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(ui->customPlot,"PT1000 Data", 20);
    //title->setFont(QFont::Fantasy);  figure this out
    ui->customPlot->plotLayout()->addElement(0,0, title);
    //Legend
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    //ui->customPlot->legend->setIconSize();
    //Axes labels:
    ui->customPlot->xAxis->setLabel("Time [ms]");
    ui->customPlot->yAxis->setLabel("Temperatur [C]");
    //Axes ranges:
    ui->customPlot->xAxis->setRange(0, time_ms);
    ui->customPlot->yAxis->setRange(0, 13);
    ui->customPlot->replot();

    ui->customPlot->savePdf("C:/Users/janni/Desktop/Plotting/PlottingTest/test.pdf", 1920, 1080);

    qDebug() << "done baby";
}

void MainWindow::getData()
{
    QFile file("C:/Users/janni/Desktop/OpenData/OpenData/HP_50.csv");   //make this sexier

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "file not open";
        return;
    }

    //make this whole section only called once, not with every data instance

    QTextStream in(&file);
    read_data = new QString[2050];    //always get all data

    for(int i=0; i<25; i++){
        read_data[0] = in.readLine(); //make so that data can begin somewhere besides 25th line. (while)
    }
    int i=1;
    while(!in.atEnd()){
        read_data[i] = in.readLine();
        i++;
    }
    file.close();
}

float* MainWindow::getPT1000Data(int sensorNum, int ms)
{
    float* T_sensor = new float[ms];
    QStringList temp;

    for(int i=0; i<ms; i++){    //change, so that custom time range is choosable
        temp = read_data[i].split(",");
        T_sensor[i] = temp[18+sensorNum].toFloat();  // column 25 is PT1000_07
        //qDebug() << "t=" << i << ": " << T_sensor[i];
    }
    return T_sensor;
}
