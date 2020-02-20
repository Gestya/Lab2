#include "takenote.h"
#include "ui_takenote.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include "file.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>


TakeNote::TakeNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TakeNote)
{
    ui->setupUi(this);
}

TakeNote::~TakeNote()
{
    delete ui;
}

void TakeNote::on_pushButton_2_clicked()
{
    close();
    emit firstWindow();
}





void TakeNote::on_pushButton_clicked()
{
    File *wnd = new File(this);
    wnd->show();

    connect(wnd, SIGNAL(filePath(QString)), this, SLOT(saveFile(QString)));
}

void TakeNote::saveFile(const QString &filePath)
{
    QFile mFile(filePath);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Error open file");
        return;
    }
    QTextStream stream(&mFile);
    stream << ui->textEdit->toPlainText();
    mFile.close();
}

