#ifndef DATABASE_H
#define DATABASE_H

#include <QSysInfo>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>

#define CAREER_INF "'INFORMATICA'"
#define CAREER_COM "'COMPUTACION'"
#define CAREER_ELE "'ELECTRONICA'"

#define ROLES "Roles ( id SERIAL PRIMARY KEY, Rol TEXT NOT NULL );"
#define DEFAULT_ROLES " Roles (Rol) VALUES (" CAREER_INF "), (" CAREER_COM "), (" CAREER_ELE ");"

#define CAREER "Career (  id SERIAL PRIMARY KEY, Career TEXT NOT NULL );"
#define DEFAULT_CAREER " Roles (Rol) VALUES (" CAREER_INF "), (" CAREER_COM "), (" CAREER_ELE ");"


//"status CHAR(1) NOT NULL, "
#define PERSON  " Person " \
    "( " \
    "code VARCHAR (10) UNIQUE PRIMARY KEY NOT NULL," \
    "firstName TEXT NOT NULL," \
    "secondName TEXT NULL," \
    "thirdName TEXT NULL," \
    "LastNamePaternal TEXT NOT NULL," \
    "LastNameMaternal TEXT NULL," \
    "mail TEXT NULL," \
    "phone TEXT NULL," \
    "expediente TEXT NULL, " \
    "currentSemestre CHAR(1) NULL, " \
    "creditsObtained CHAR(1) NULL, " \
    "career INTEGER NULL REFERENCES Career(id) , " \
    "codeTutor VARCHAR (10) NULL REFERENCES Person (code) " \
    " ); "


#define DEFAULT_PERSON " Person (code, firstName, LastNamePaternal ) VALUES  ('999', 'ADMIN', 'ROOT')"

#define ADMIN " Admin (id SERIAL PRIMARY KEY, admin VARCHAR (10) REFERENCES Person (code), pass TEXT NOT NULL );"
#define DEFAULT_ADMIN " Admin (admin, pass) VALUES ( '999', '123');"

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
    bool connectDB(QString host, QString port, QString user, QString pass, QString dblocal);

};

#endif // DATABASE_H
