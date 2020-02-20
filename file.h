#ifndef FILE_H
#define FILE_H

#include <QDialog>

namespace Ui {
class File;
}

class File : public QDialog
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    ~File();

private:
    Ui::File *ui;
signals:
    void filePath(const QString &str);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    void okClicked();
};

#endif // FILE_H
