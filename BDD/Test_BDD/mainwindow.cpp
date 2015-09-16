#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("192.168.1.42");
    db.setPort(3306);
    db.setDatabaseName("TEST");
    db.setUserName("pouet");
    db.setPassword("");
    if (!db.open())
    {
        QMessageBox::critical(this, "PAS REUSSI", db.lastError().text());
    }
    else
    {
//        QSqlQuery tata;
//        tata.prepare("CREATE TABLE EXAMPLE (CONTENT TEXT)");
//        if (tata.exec())
//        {
//            QMessageBox::information(this, "table creee","table creee");
//            tata.prepare("insert into EXAMPLE values("")");
//            if (tata.exec())
//            {

//            }

//        }
//        else
        QMessageBox::critical(this, "COOL", "COOL");
    }
    db.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
