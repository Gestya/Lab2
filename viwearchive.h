#ifndef VIWEARCHIVE_H
#define VIWEARCHIVE_H

#include <QDialog>

namespace Ui {
class ViweArchive;
}

class ViweArchive : public QDialog
{
    Q_OBJECT

public:
    explicit ViweArchive(QWidget *parent = nullptr);
    ~ViweArchive();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void openFile(const QString &filePath);
    void on_pushButton_2_clicked();

private:
    Ui::ViweArchive *ui;
};

#endif // VIWEARCHIVE_H
