#ifndef DATABASE_H
#define DATABASE_H

#include <QSysInfo>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

#include <QSqlError>
#include <QDebug>

#define CREATE_DB "create database "
#define DEFAULT_PSQL_DB "postgres"
#define CREATE_TABLE_PERSONAL "create table Personal (nombre varchar(50));"

#define DB_NO_CREATE -1

#define TYPE_DB "QPSQL"

class Database : public QObject
{
    Q_OBJECT

public slots:
    bool tryConnectUser(QString, QString, QString, QString);

private:
    //QSqlError err = nullptr;
    QSqlDatabase db;

public:
    Database();
    bool createDB(QString);

};

#endif // DATABASE_H
