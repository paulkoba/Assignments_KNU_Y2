#include "permissionsform.h"
#include "ui_permissionsform.h"

void PermissionsForm::setupDropdowns()
{
    std::filesystem::permissions(path, std::filesystem::perms::owner_all |
                                 std::filesystem::perms::group_all |
                                 std::filesystem::perms::others_all );
}

PermissionsForm::PermissionsForm(std::string filepath, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PermissionsForm)
    , path(std::move(filepath))
{
    ui->setupUi(this);
    setupDropdowns();
}

PermissionsForm::~PermissionsForm()
{
    delete ui;
}
