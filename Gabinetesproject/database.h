#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

#define INIT        0

class Database
{
 Q_OBJECT
private:

    //QDialog captureConnection

    // use psql
    QSqlDatabase *db = nullptr;
    char statusDB;

private slots:
    bool tryConnectUser();


public:
    Database();
    void createDB();



};

#endif // DATABASE_H
