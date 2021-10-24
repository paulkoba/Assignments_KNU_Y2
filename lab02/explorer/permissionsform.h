#ifndef PERMISSIONSFORM_H
#define PERMISSIONSFORM_H

#include <QWidget>

#include "helpers.h"

namespace Ui {
class PermissionsForm;
}

class PermissionsForm : public QWidget
{
    Q_OBJECT

public:
    PermissionsForm(std::string, QWidget *parent = nullptr);
    ~PermissionsForm();

private:
    Ui::PermissionsForm *ui;
    std::string path;

private:
    void setupDropdowns();

    void accessComboChanged(int);
    void editComboChanged(int);
    void executeComboChanged(int);
};

#endif // PERMISSIONSFORM_H
