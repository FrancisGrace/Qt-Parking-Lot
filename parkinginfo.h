#ifndef PARKINGINFO_H
#define PARKINGINFO_H

#include <QDialog>
#include <QTableView>
#include <QTextBrowser>

namespace Ui {
class parkingInfo;
}

class parkingInfo : public QDialog
{
    Q_OBJECT

public:
    explicit parkingInfo(QWidget *parent = 0);
    ~parkingInfo();
    QTableView* getTableAddress();
    QTextBrowser* getTextAddress();

private:
    Ui::parkingInfo *ui;
};

#endif // PARKINGINFO_H
