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
    void digit_pressed();

    void on_pushButton_dat_released();
    void unary_operation_pressed();
    void binary_operation_pressed();

    void on_pushButton_equal_released();

    void on_pushButton_clear_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
