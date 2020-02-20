#include "viwenote.h"
#include "ui_viwenote.h"
#include "ui_takenote.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include "file.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

ViweNote::ViweNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViweNote)
{
    ui->setupUi(this);


}

ViweNote::~ViweNote()
{
    delete ui;
}

void ViweNote::on_pushButton_clicked()
{
    close();
    emit firstWindow();
}



void ViweNote::on_pushButton_2_clicked()
{
    File *wnd = new File(this);
    wnd->show();

    connect(wnd, SIGNAL(filePath(QString)), this, SLOT(openFile(QString)));
}

void ViweNote::openFile(const QString &filePath)
{
    QFile mFile(filePath);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Error open file");
        return;
    }
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();
    ui->textBrowser->setText(buffer);
    mFile.flush();
    mFile.close();
}
