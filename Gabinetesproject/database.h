#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

#define INIT        0

class Database
{
private:

    //QDialog captureConnection

    // use psql
    QSqlDatabase *db = nullptr;
    char statusDB;

public:
    Database();
    void createDB();
};

#endif // DATABASE_H
