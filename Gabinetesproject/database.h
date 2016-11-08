#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

#define TYPE_DB "psql"
#define INIT        0

class Database : public QObject
{
    Q_OBJECT

public slots:
    bool tryConnectUser(QString, QString, QString, QString);

private:
    QSqlDatabase db;
    char statusDB;


public:
    Database();
    void createDB(QString, QString, QString, QString);

};

#endif // DATABASE_H
