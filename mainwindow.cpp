#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     window_TakeNote = new TakeNote(this);
     connect(window_TakeNote, &TakeNote::firstWindow, this, &MainWindow::show);

     window_ViweNote = new ViweNote(this);
    connect(window_ViweNote, &ViweNote::firstWindow, this, &MainWindow::show);

     window_ViweArchive = new ViweArchive(this);
    connect(window_ViweArchive, &ViweArchive::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    close();
    window_TakeNote->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
    window_ViweNote->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
    window_ViweArchive->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "close?", "Close the program?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
        QApplication::quit();
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this, "What is it?", "This is a program for creating notes, and further using them.");
}
