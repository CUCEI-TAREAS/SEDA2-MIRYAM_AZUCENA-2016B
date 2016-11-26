#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

class Admin
{
private:
    QString id, // id of admin
    admin, // code of person on Person table
    pass; //

public:
    Admin();

    QString getId() const;
    void setId(const QString &value);
    QString getAdmin() const;
    void setAdmin(const QString &value);
    QString getPass() const;
    void setPass(const QString &value);
};

#endif // ADMIN_H
