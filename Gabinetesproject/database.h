#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
private:
    QSqlDatabase *db = nullptr;

public:
    Database();
};

#endif // DATABASE_H
