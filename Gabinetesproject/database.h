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

*/

/*
TABLE Career
    id SERIAL PRIMARY KEY,
    Career TEXT NOT NULL;

*/


/*
TABLE Personal

    code    VARCHAR(10) UNIQUE PRIMARY KEY NOT NULL,

    firtsName           TEXT NOT  NULL,
    secondName          TEXT NULL,
    thirdName           TEXT NULL,
    LastNamePaternal    TEXT NOT  NULL,
    LastNameMaternal    TEXT NULL,

    mail                TEXT NOT NULL,

    phone               TEXT NOT NULL,

    expediente          TEXT NOT NULL,

    status              CHAR(1) NOT NULL,

    currentSemestre     CHAR(1) NOT NULL,
    creditsObtained     CHAR(1) NOT NULL,

    career              INTERGER NULL REFERENCES Career(id), // index to id TABLE Career
    codeTutor           VARCHAR(10) REFERENCES Personal(code) // index to code

*/


#define CREATE_DB "create database "
#define DEFAULT_PSQL_DB "postgres"

#define INSERT_TABLE_PERSONAL_DEFAULT_ADMIN ""

// independents tables
#define CREATE_TABLE_CAREER "CREATE TABLE Career (id SERIAL PRIMARY KEY, Career TEXT NOT NULL);"

// dependencies tables
#define CREATE_TABLE_PERSONAL "CREATE TABLE Person (code VARCHAR(10) UNIQUE PRIMARY KEY NOT NULL,""firtsName TEXT NOT  NULL,);"
#define CREATE_TABLE_ADMIN ""


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
