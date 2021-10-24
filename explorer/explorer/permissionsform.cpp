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

void PermissionsForm::executeComboChanged(int index)
{
    switch (index) {
    case 0:
        std::filesystem::permissions(path, std::filesystem::perms::owner_exec |
                                     std::filesystem::perms::group_exec |
                                     std::filesystem::perms::others_exec,
                                     std::filesystem::perm_options::remove);
        break;
    case 1:
        std::filesystem::permissions(path, std::filesystem::perms::owner_exec |
                                     std::filesystem::perms::group_exec |
                                     std::filesystem::perms::others_exec,
                                     std::filesystem::perm_options::add);
        break;
    case 2:
        std::filesystem::permissions(path, std::filesystem::perms::others_exec,
                                     std::filesystem::perm_options::remove);
        std::filesystem::permissions(path, std::filesystem::perms::owner_exec |
                                     std::filesystem::perms::group_exec,
                                     std::filesystem::perm_options::add);
        break;
    case 3:
        std::filesystem::permissions(path, std::filesystem::perms::others_exec |
                                     std::filesystem::perms::group_exec,
                                     std::filesystem::perm_options::remove);
        std::filesystem::permissions(path, std::filesystem::perms::owner_exec,
                                     std::filesystem::perm_options::add);
        break;
    default:
        break;
    }
}

void PermissionsForm::editComboChanged(int index)
{
    switch (index) {
    case 0:
        std::filesystem::permissions(path, std::filesystem::perms::owner_write |
                                     std::filesystem::perms::group_write |
                                     std::filesystem::perms::others_write,
                                     std::filesystem::perm_options::remove);
        break;
    case 1:
        std::filesystem::permissions(path, std::filesystem::perms::owner_write |
                                     std::filesystem::perms::group_write |
                                     std::filesystem::perms::others_write,
                                     std::filesystem::perm_options::add);
        break;
    case 2:
        std::filesystem::permissions(path, std::filesystem::perms::others_write,
                                     std::filesystem::perm_options::remove);
        std::filesystem::permissions(path, std::filesystem::perms::owner_write |
                                     std::filesystem::perms::group_write,
                                     std::filesystem::perm_options::add);
        break;
    case 3:
        std::filesystem::permissions(path, std::filesystem::perms::others_write |
                                     std::filesystem::perms::group_write,
                                     std::filesystem::perm_options::remove);
        std::filesystem::permissions(path, std::filesystem::perms::owner_write,
                                     std::filesystem::perm_options::add);
        break;
    default:
        break;
    }
}

void PermissionsForm::accessComboChanged(int index)
{
    switch (index) {
    case 0:
        std::filesystem::permissions(path, std::filesystem::perms::owner_read |
                                     std::filesystem::perms::group_read |
                                     std::filesystem::perms::others_read,
                                     std::filesystem::perm_options::remove);
        break;
    case 1:
        std::filesystem::permissions(path, std::filesystem::perms::owner_read |
                                     std::filesystem::perms::group_read |
                                     std::filesystem::perms::others_read,
                                     std::filesystem::perm_options::add);
        break;
    case 2:
        std::filesystem::permissions(path, std::filesystem::perms::others_read,
                                     std::filesystem::perm_options::remove);
        std::filesystem::permissions(path, std::filesystem::perms::owner_read |
                                     std::filesystem::perms::group_read,
                                     std::filesystem::perm_options::add);
        break;
    case 3:
        std::filesystem::permissions(path, std::filesystem::perms::others_read |
                                     std::filesystem::perms::group_read,
                                     std::filesystem::perm_options::remove);
        std::filesystem::permissions(path, std::filesystem::perms::owner_read,
                                     std::filesystem::perm_options::add);
        break;
    default:
        break;
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

    QObject::connect(ui->accessCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [=] (int index) {
        accessComboChanged(index);
    });

    QObject::connect(ui->executeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [=] (int index) {
        executeComboChanged(index);
    });

    QObject::connect(ui->modifyCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [=] (int index) {
        editComboChanged(index);
    });
}

PermissionsForm::~PermissionsForm()
{
    delete ui;
}
