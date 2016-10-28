#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>

class Database
{
private:
    QSqlDatabase *db = nullptr;

public:
    Database();
    void createDB();
};

#endif // DATABASE_H
