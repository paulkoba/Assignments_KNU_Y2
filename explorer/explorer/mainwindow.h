#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>

#include <QMainWindow>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QShortcut>

#include "settingsmanager.h"
#include "helpers.h"
#include "permissionsform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void renameFileOrFolder();
    void deleteFileOrFolder();
    void createNewFile();
    void createNewFolder();
    void openProperties();
private slots:
    void changeRoot();
    void quit();

private:
    PermissionsForm* permissions;
    SettingsManager settings;

    Ui::MainWindow *ui;
    QFileSystemModel *fsmodel;

    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *changeRootAction;
    QAction *quitAction;
    QAction *renameAction;
    QAction *deleteAction;
    QAction *newFolderAction;
    QAction *newFileAction;
    QAction *about;
    QAction *propertiesAction;

    QShortcut *rename;
};
#endif // MAINWINDOW_H
