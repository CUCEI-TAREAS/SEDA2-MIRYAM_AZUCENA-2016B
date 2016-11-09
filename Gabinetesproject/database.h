#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

#define CREATE_DB "create database "
#define CREATE_TABLE_STUDENT "create table(nombre varchar(50));"

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
    char createDB(QString);

};

#endif // DATABASE_H
