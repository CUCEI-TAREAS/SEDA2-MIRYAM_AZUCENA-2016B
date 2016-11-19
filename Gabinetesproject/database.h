#ifndef DATABASE_H
#define DATABASE_H

#include <QSysInfo>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>

#define ROLES "Roles ( id SERIAL PRIMARY KEY, Rol TEXT NOT NULL );"
#define CAREER "Career (  id SERIAL PRIMARY KEY, Career TEXT NOT NULL );"

#define PERSON  " Person " \
    "( " \
    "code VARCHAR (10) UNIQUE PRIMARY KEY NOT NULL," \
    "firtsName TEXT NOT NULL," \
    "secondName TEXT NULL," \
    "thirdName TEXT NULL," \
    "LastNamePaternal TEXT NOT NULL," \
    "LastNameMaternal TEXT NULL," \
    "mail TEXT NOT NULL," \
    "phone TEXT NOT NULL," \
    "expediente TEXT NOT NULL, " \
    "status CHAR(1) NOT NULL, " \
    "currentSemestre CHAR(1) NOT NULL, " \
    "creditsObtained CHAR(1) NOT NULL, " \
    "career INTERGER NULL REFERENCES Career(id), " \
    "codeTutor VARCHAR (10) REFERENCES Person (code)" \
    " ); "

#define ADMIN " Admin (id SERIAL PRIMARY KEY, admin VARCHAR (10) REFERENCE Person (code) );"
#define MEETING " Meeting (codeStudent VARCHAR (10) REFERENCES Person (code), codeAdmin  VARCHAR (10), date TIMESTAMP NOT NULL, time TIME NOT NULL);"

#define CREATE_DB "CREATE DATABASE "
#define CREATE_TABLE "CREATE TABLE "
#define INSERT_INTO "INSERT INTO "

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
