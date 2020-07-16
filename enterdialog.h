#ifndef ENTERDIALOG_H
#define ENTERDIALOG_H

#include <QDialog>

namespace Ui {
class enterDialog;
}

class enterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit enterDialog(QWidget *parent = 0);
    ~enterDialog();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::enterDialog *ui;
};

#endif // ENTERDIALOG_H
