#include "file.h"
#include "ui_file.h"
#include <QPushButton>

File::File(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);

}

File::~File()
{
    delete ui;
}

void File::on_pushButton_2_clicked()
{
    emit filePath(ui->lineEdit->text());
    close();
}

void File::on_pushButton_3_clicked()
{
    close();
}
