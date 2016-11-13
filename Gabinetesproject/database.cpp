#include "database.h"

Database::Database()
{
}

char Database::createDB(QString name)
{
    QSqlQuery query;
    if( query.exec(CREATE_DB+name)){
        db.setDatabaseName(name);

        query.exec(CREATE_TABLE_PERSONAL);

    }
    else
        return DB_NO_CREATE;
}

bool Database::tryConnectUser(QString host, QString port, QString user, QString pass)
{
    db = QSqlDatabase::addDatabase(TYPE_DB);

    // differents ways OS
#if defined(Q_OS_LINUX)
// broken API
    db.setDatabaseName("template1");
// POSIX API
#endif

    db.setHostName(host);
    db.setPort(port.toInt());
    db.setUserName(user);
    db.setPassword(pass);

    return db.open();

}

