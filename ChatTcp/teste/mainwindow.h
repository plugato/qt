#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "PackageBuilder.h"
#include "package.h"
#include <QPushButton>


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Envia();

    ~MainWindow();

signals:
    //void SendPack(  QByteArray );




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
