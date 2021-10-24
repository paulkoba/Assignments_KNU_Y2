#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::openProperties()
{
    QModelIndexList ll = ui->fileTreeView->selectionModel()->selectedIndexes();

    if(ll.size() != 0)
    {
        auto el = ll.at(0);
        auto r = fsmodel->filePath(el).toStdString();

        permissions = new PermissionsForm(r);
        permissions->show();
    }
}

void MainWindow::changeRoot()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Change root location"),
                                tr("New location: "), QLineEdit::Normal,
                                QDir::home().dirName(), &ok);

    if(!ok) return;

    std::string converted = text.toStdString();
    if(!std::filesystem::exists(converted))
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid location.");
        msgBox.exec();
        return;
    }

    fsmodel->setRootPath(text);
    ui->fileTreeView->setRootIndex(fsmodel->index(text));

    settings.set("rootLocation", text);
}

void MainWindow::renameFileOrFolder() {
    QModelIndexList ll = ui->fileTreeView->selectionModel()->selectedIndexes();

    if(ll.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid location.");
        msgBox.exec();
        return;
    }
    bool ok;
    std::string text = QInputDialog::getText(this, tr("New name"),
                                tr("New name: "), QLineEdit::Normal,
                                QDir::home().dirName(), &ok).toStdString();

    if(!ok) return;

    auto el = ll.at(0);
    auto r = fsmodel->filePath(el).toStdString();

    auto folder = r;
    while(!folder.empty() && *folder.rbegin() != '/') folder.pop_back();
    text = folder + text;
    if(std::filesystem::exists(text)) {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("File with given name already exists."));
        msgBox.exec();
        return;
    }

    std::filesystem::rename(r, text);
}

void MainWindow::deleteFileOrFolder() {
    QModelIndexList ll = ui->fileTreeView->selectionModel()->selectedIndexes();

    if(ll.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid location.");
        msgBox.exec();
        return;
    }

    auto el = ll.at(0);
    auto r = fsmodel->filePath(el).toStdString();

    std::filesystem::remove_all(r);
}

void MainWindow::quit()
{
    exit(0);
}

void MainWindow::createNewFile()
{
    QModelIndexList ll = ui->fileTreeView->selectionModel()->selectedIndexes();

    if(ll.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid location.");
        msgBox.exec();
        return;
    }

    auto el = ll.at(0);
    auto r = fsmodel->filePath(el).toStdString();

    if(!std::filesystem::is_directory(r))
    {
        QMessageBox msgBox;
        msgBox.setText("Not a directory.");
        msgBox.exec();
        return;
    }

    bool ok;
    std::string text = QInputDialog::getText(this, tr("New name"),
                                tr("New name: "), QLineEdit::Normal,
                                QDir::home().dirName(), &ok).toStdString();

    if(!ok) return;

    text = r + '/' + text;

    if(std::filesystem::exists(text)) {
        QMessageBox msgBox;
        msgBox.setText("File with given name already exists.");
        msgBox.exec();
        return;
    }

    std::ofstream str(text);
}

void MainWindow::createNewFolder()
{
    QModelIndexList ll = ui->fileTreeView->selectionModel()->selectedIndexes();

    if(ll.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid location.");
        msgBox.exec();
        return;
    }

    auto el = ll.at(0);
    auto r = fsmodel->filePath(el).toStdString();

    if(!std::filesystem::is_directory(r))
    {
        QMessageBox msgBox;
        msgBox.setText("Not a directory.");
        msgBox.exec();
        return;
    }

    bool ok;
    std::string text = QInputDialog::getText(this, tr("New name"),
                                tr("New name: "), QLineEdit::Normal,
                                QDir::home().dirName(), &ok).toStdString();

    if(!ok) return;

    text = r + '/' + text;

    if(std::filesystem::exists(text)) {
        QMessageBox msgBox;
        msgBox.setText("File with given name already exists.");
        msgBox.exec();
        return;
    }

    std::filesystem::create_directory(text);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fsmodel(new QFileSystemModel)
    , settings("settings")
{
    ui->setupUi(this);

    //Setup main filesystem view & restore saved location.
    ui->fileTreeView->setModel(fsmodel);
    auto rootPath = settings.get("rootLocation", QDir::homePath()).toString();

    fsmodel->setRootPath(rootPath);
    ui->fileTreeView->setRootIndex(fsmodel->index(rootPath));


    fileMenu = menuBar()->addMenu(tr("&File"));
    changeRootAction = fileMenu->addAction("&Change root");
    renameAction = fileMenu->addAction("&Rename");
    deleteAction = fileMenu->addAction("&Delete");
    newFileAction = fileMenu->addAction("Create new fil&e");
    newFolderAction = fileMenu->addAction("Create new f&older");
    quitAction = fileMenu->addAction("&Quit");
    propertiesAction = fileMenu->addAction("&Properties");

    //Setup slots
    QObject::connect(ui->fileTreeView, &QTreeView::doubleClicked,
                     [=] (const QModelIndex& val) {
        Helpers::tryOpenFile(fsmodel->filePath(val));
    });

    QObject::connect(changeRootAction, &QAction::triggered, this, &MainWindow::changeRoot);
    QObject::connect(quitAction, &QAction::triggered, this, &MainWindow::quit);
    QObject::connect(renameAction, &QAction::triggered, this, &MainWindow::renameFileOrFolder);
    QObject::connect(deleteAction, &QAction::triggered, this, &MainWindow::deleteFileOrFolder);
    QObject::connect(newFolderAction, &QAction::triggered, this, &MainWindow::createNewFolder);
    QObject::connect(newFileAction, &QAction::triggered, this, &MainWindow::createNewFile);
    QObject::connect(propertiesAction, &QAction::triggered, this, &MainWindow::openProperties);
}

MainWindow::~MainWindow()
{
    delete ui;
}

