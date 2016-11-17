#ifndef DATABASE_H
#define DATABASE_H

#include <QSysInfo>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

#include <QSqlError>
#include <QDebug>

/*
all persons register on Personal table,
with masterkey linked to other tables by example

default

*/

#define CREATE_DB "create database "
#define DEFAULT_PSQL_DB "postgres"
#define CREATE_TABLE_PERSONAL "create table Personal (nombre varchar(100), code varchar(255));"
#define INSERT_TABLE_PERSONAL_DEFAULT_ADMIN ""

#define CREATE_TABLE_ADMIN " create table admin(code varchar(12));"


#define DB_NO_CREATE -1

#define TYPE_DB "QPSQL"

class Database : public QObject
{
    Q_OBJECT

public slots:
    bool tryConnectUser(QString, QString, QString, QString);

private:
    QSqlDatabase db;

public:
    Database();
    bool createDB(QString);

};

#endif // DATABASE_H
