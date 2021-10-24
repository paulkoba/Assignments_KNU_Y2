#ifndef PERMISSIONSFORM_H
#define PERMISSIONSFORM_H

#include <filesystem>

#include <QWidget>

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

    void accessComboChanged();
    void editComboChanged();
    void executeComboChanged();
};

#endif // PERMISSIONSFORM_H
