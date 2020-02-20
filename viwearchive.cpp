#include "viwearchive.h"
#include "ui_viwearchive.h"
#include "takenote.h"
#include "ui_takenote.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include "file.h"
#include <QMessageBox>


ViweArchive::ViweArchive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViweArchive)
{
    ui->setupUi(this);

}

ViweArchive::~ViweArchive()
{
    delete ui;
}

void ViweArchive::on_pushButton_clicked()
{
    close();
    emit firstWindow();
}


void ViweArchive::on_pushButton_2_clicked()
{
    File *wnd = new File(this);
    wnd->show();

    connect(wnd, SIGNAL(filePath(QString)), this, SLOT(openFile(QString)));
}

void ViweArchive::openFile(const QString &filePath)
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
