#ifndef SETPERSONALDATA_H
#define SETPERSONALDATA_H

#include <QDialog>

namespace Ui {
class setPersonalData;
}

class setPersonalData : public QDialog
{
    Q_OBJECT

public:
    explicit setPersonalData(QWidget *parent = nullptr);
    ~setPersonalData();

private:
    Ui::setPersonalData *ui;
};

#endif // SETPERSONALDATA_H
