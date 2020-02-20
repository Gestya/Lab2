#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "takenote.h"
#include "viwenote.h"
#include "viwearchive.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


private:
    Ui::MainWindow *ui;
    TakeNote *window_TakeNote;
    ViweNote *window_ViweNote;
    ViweArchive *window_ViweArchive;
};

#endif // MAINWINDOW_H
