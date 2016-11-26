#include "admin.h"

QString Admin::getId() const
{
    return id;
}

void Admin::setId(const QString &value)
{
    id = value;
}

QString Admin::getAdmin() const
{
    return admin;
}

void Admin::setAdmin(const QString &value)
{
    admin = value;
}

QString Admin::getPass() const
{
    return pass;
}

void Admin::setPass(const QString &value)
{
    pass = value;
}

Admin::Admin()
{

}
