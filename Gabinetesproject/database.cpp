#include "database.h"

Database::Database()
{}
bool Database::createDB(QString name)
{
    QSqlQuery query(db);
    if( query.exec(CREATE_DB+name)){

        db.setDatabaseName(name);
        db.open();

        query.exec(CREATE_TABLE ROLES);
        query.exec(CREATE_TABLE CAREER);
        query.exec(CREATE_TABLE PERSON);
        query.exec(CREATE_TABLE ADMIN);
        query.exec(CREATE_TABLE MEETING);
        return true;
    }
    else
        // maybe db already exists
        // check tables if exists
        // dont override database
        qDebug () << query.lastError().text();
    return false;
}

bool Database::tryConnectUser(QString host, QString port, QString user, QString pass)
{
    db = QSqlDatabase::addDatabase(TYPE_DB);
    db.setHostName(host);
    db.setPort(port.toInt());
    db.setUserName(user);
    db.setPassword(pass);

    bool connection = db.open();

    if (!connection)
        qDebug () << db.lastError().text();

    return connection;
}
