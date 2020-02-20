#ifndef VIWENOTE_H
#define VIWENOTE_H

#include <QDialog>

namespace Ui {
class ViweNote;
}

class ViweNote : public QDialog
{
    Q_OBJECT

public:
    explicit ViweNote(QWidget *parent = nullptr);
    ~ViweNote();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void openFile(const QString &filePath);
    void on_pushButton_2_clicked();

private:
    Ui::ViweNote *ui;
};

#endif // VIWENOTE_H
