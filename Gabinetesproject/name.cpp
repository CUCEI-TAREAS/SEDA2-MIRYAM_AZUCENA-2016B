#include "name.h"

Name::Name()
{

}

QString Name::getFirtsName() const
{
    return firtsName;
}

void Name::setFirtsName(const QString &value)
{
    firtsName = value;
}

QString Name::getSecondName() const
{
    return secondName;
}

void Name::setSecondName(const QString &value)
{
    secondName = value;
}

QString Name::getThirdName() const
{
    return thirdName;
}

void Name::setThirdName(const QString &value)
{
    thirdName = value;
}

QString Name::getLastNameMaternal() const
{
    return LastNameMaternal;
}

void Name::setLastNameMaternal(const QString &value)
{
    LastNameMaternal = value;
}

QString Name::getLastNamePaternal() const
{
    return LastNamePaternal;
}

void Name::setLastNamePaternal(const QString &value)
{
    LastNamePaternal = value;
}
