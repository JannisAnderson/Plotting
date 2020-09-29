#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getData(QString loc);
    void makePlot1();
    void makeDataPlot(int);
    float* getPT1000Data(int, int);
    void on_add_File_triggered();
    void on_save_as_pdf_triggered();
    void on_save_as_jpg_triggered();

private:
    Ui::MainWindow *ui;

    QString* read_data;
    QString saveLoc = "C://";

    int ColorValues[56] {
            0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF, 0x00FFFF, 0x000000,
            0x800000, 0x008000, 0x000080, 0x808000, 0x800080, 0x008080, 0x808080,
            0xC00000, 0x00C000, 0x0000C0, 0xC0C000, 0xC000C0, 0x00C0C0, 0xC0C0C0,
            0x400000, 0x004000, 0x000040, 0x404000, 0x400040, 0x004040, 0x404040,
            0x200000, 0x002000, 0x000020, 0x202000, 0x200020, 0x002020, 0x202020,
            0x600000, 0x006000, 0x000060, 0x606000, 0x600060, 0x006060, 0x606060,
            0xA00000, 0x00A000, 0x0000A0, 0xA0A000, 0xA000A0, 0x00A0A0, 0xA0A0A0,
            0xE00000, 0x00E000, 0x0000E0, 0xE0E000, 0xE000E0, 0x00E0E0, 0xE0E0E0,
        };
};
#endif // MAINWINDOW_H
