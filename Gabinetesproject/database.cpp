#include "database.h"

Database::Database()
{}
bool Database::createDB(QString name)
{
    QSqlQuery query(db);
    if( query.exec(CREATE_DB+name)){

        db.setDatabaseName(name);
        db.open();

        bool ds = false;

        ds = query.exec(CREATE_TABLE ROLES);

        ds = query.exec(CREATE_TABLE CAREER);
        ds = query.exec(INSERT_INTO DEFAULT_CAREER);

        ds = query.exec(CREATE_TABLE PERSON); // fail
        ds = query.exec(INSERT_INTO DEFAULT_PERSON);

        ds = query.exec(CREATE_TABLE ADMIN); // fail
        ds = query.exec(INSERT_INTO DEFAULT_ADMIN);

        ds = query.exec(CREATE_TABLE MEETING); // fail


        qDebug () << query.lastError().text();

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
