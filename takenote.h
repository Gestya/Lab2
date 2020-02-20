#ifndef TAKENOTE_H
#define TAKENOTE_H

#include <QDialog>

namespace Ui {
class TakeNote;
}

class TakeNote : public QDialog
{
    Q_OBJECT

public:
    explicit TakeNote(QWidget *parent = nullptr);
    ~TakeNote();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void saveFile(const QString &filePath);
    void on_pushButton_clicked();

private:
    Ui::TakeNote *ui;
};

#endif // TAKENOTE_H
