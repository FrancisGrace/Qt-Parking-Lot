#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateMessage(QString msg);
    ~MainWindow();

private slots:
    void on_enter_clicked();

    void on_leave_clicked();

    void on_checkCar_clicked();

    void on_checkParking_clicked();

    void closeEvent();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
