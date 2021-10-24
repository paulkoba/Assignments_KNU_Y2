#include "permissionsform.h"
#include "ui_permissionsform.h"

void PermissionsForm::setupDropdowns()
{
   /* std::filesystem::permissions (path, std::filesystem::perms::owner_all |
                                 std::filesystem::perms::group_all |
                                 std::filesystem::perms::others_all );
    */

    auto perms = std::filesystem::status(path).permissions();

    if((perms & std::filesystem::perms::others_read) != std::filesystem::perms::none) {
        ui->accessCombo->setCurrentIndex(1);
    } else if((perms & std::filesystem::perms::group_read) != std::filesystem::perms::none) {
        ui->accessCombo->setCurrentIndex(2);
    } else if((perms & std::filesystem::perms::owner_read) != std::filesystem::perms::none) {
        ui->accessCombo->setCurrentIndex(3);
    }

    if((perms & std::filesystem::perms::others_exec) != std::filesystem::perms::none) {
        ui->executeCombo->setCurrentIndex(1);
    } else if((perms & std::filesystem::perms::group_exec) != std::filesystem::perms::none) {
        ui->executeCombo->setCurrentIndex(2);
    } else if((perms & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) {
        ui->executeCombo->setCurrentIndex(3);
    }

    if((perms & std::filesystem::perms::others_write) != std::filesystem::perms::none) {
        ui->modifyCombo->setCurrentIndex(1);
    } else if((perms & std::filesystem::perms::group_write) != std::filesystem::perms::none) {
        ui->modifyCombo->setCurrentIndex(2);
    } else if((perms & std::filesystem::perms::owner_write) != std::filesystem::perms::none) {
        ui->modifyCombo->setCurrentIndex(3);
    }
}

PermissionsForm::PermissionsForm(std::string filepath, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PermissionsForm)
    , path(std::move(filepath))
{
    ui->setupUi(this);
    setupDropdowns();
    ui->location->setText(QString::fromStdString(path));
}

PermissionsForm::~PermissionsForm()
{
    delete ui;
}
