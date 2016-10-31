#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
private:
    // use psql
    QSqlDatabase *db = nullptr;

public:
    Database();
    void createDB();
};

#endif // DATABASE_H
