#ifndef DATABASE_H
#define DATABASE_H

#include <QSysInfo>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>

#include "personal.h"

#define CAREER_INF "'INFORMATICA'"
#define CAREER_COM "'COMPUTACION'"
#define CAREER_ELE "'ELECTRONICA'"

#define NAME_TABLE_ROLES    " Roles "
#define NAME_TABLE_CAREER   " Career "
#define NAME_TABLE_PERSON   " Person "
#define NAME_TABLE_ADMIN    " Admin "
#define NAME_TABLE_MEETING  " Meeting "

#define ROLES           NAME_TABLE_ROLES    " ( id SERIAL PRIMARY KEY, Rol TEXT NOT NULL );"
#define DEFAULT_ROLES   NAME_TABLE_ROLES    " (Rol) VALUES (" CAREER_INF "), (" CAREER_COM "), (" CAREER_ELE ");"
// columns
#define ROLES_ID 0
#define ROLES_ROL 1


#define CAREER          NAME_TABLE_CAREER   " (  id SERIAL PRIMARY KEY, Career TEXT NOT NULL );"
#define DEFAULT_CAREER  NAME_TABLE_CAREER   " (Career) VALUES (" CAREER_INF "), (" CAREER_COM "), (" CAREER_ELE ");"
// columns
#define CAREER_ID 0
#define CAREER_ROL 1



#define PERSON  NAME_TABLE_PERSON \
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
    "status TEXT NULL, " \
    "currentSemestre TEXT  NULL, " \
    "creditsObtained TEXT  NULL, " \
    "career INTEGER NULL REFERENCES Career(id) , " \
    "codeTutor VARCHAR (10) NULL REFERENCES Person (code) " \
    " ); "

#define DEFAULT_PERSON_CODE "0"
#define DEFAULT_PERSON_NAME "ROOT"
#define DEFAULT_PERSON_PASS "a5z8y1"

#define DEFAULT_PERSON  NAME_TABLE_PERSON   " (code, firstName, LastNamePaternal ) VALUES  ('" DEFAULT_PERSON_CODE "' , '" DEFAULT_PERSON_NAME "', '" DEFAULT_PERSON_NAME "');"
#define PERSON_CODE 0
#define PERSON_FIRSTNAME 1
#define PERSON_SECONDNAME 2
#define PERSON_THIRDNAME 3
#define PERSON_LASTNAMEPATERNAL 4
#define PERSON_LASTNAMEMATERNAL 5
#define PERSON_MAIL 6
#define PERSON_PHONE 7
#define PERSON_EXPEDIENTE 8
#define PERSON_STATUS 9
#define PERSON_CURRENTSEMESTRE 10
#define PERSON_CREDITS 11
#define PERSON_CAREER 12
#define PERSON_TUTOR 13

#define ADMIN           NAME_TABLE_ADMIN    " (id SERIAL PRIMARY KEY, admin VARCHAR (10) REFERENCES Person (code), pass TEXT NOT NULL );"
#define DEFAULT_ADMIN   NAME_TABLE_ADMIN    " (admin, pass) VALUES ( '" DEFAULT_PERSON_CODE "', '" DEFAULT_PERSON_PASS"');"

#define ADMIN_ID 0
#define ADMIN_PERSON 1
#define ADMIN_PASS 2

#define MEETING NAME_TABLE_MEETING " (codeStudent VARCHAR (10) REFERENCES Person (code), codeAdmin  VARCHAR (10), date TIMESTAMP NOT NULL, time TIME NOT NULL);"

#define CREATE_DB "CREATE DATABASE "
#define CREATE_TABLE "CREATE TABLE "
#define INSERT_INTO "INSERT INTO "

#define EXISTS_PERSON "SELECT CODE FROM " NAME_TABLE_PERSON " WHERE CODE LIKE "
#define EXISTS_ADMIN "SELECT PASS FROM " NAME_TABLE_ADMIN " WHERE ADMIN LIKE "
#define EXISTS_ADMIN_PASS 0

#define QUERY_SELECT_ALL "SELECT * FROM "

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
    QSqlQuery selectAll(QString);
    bool createDB(QString);
    bool connectDB(QString host, QString port, QString user, QString pass, QString dblocal);

    //
    bool existsPerson(QString);
    bool addPerson(Personal *);
    bool checkAdmin(QString, QString);

};

#endif // DATABASE_H
