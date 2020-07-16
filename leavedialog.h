#ifndef LEAVEDIALOG_H
#define LEAVEDIALOG_H

#include <QDialog>

namespace Ui {
class leaveDialog;
}

class leaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit leaveDialog(QWidget *parent = 0);
    ~leaveDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::leaveDialog *ui;
};

#endif // LEAVEDIALOG_H
