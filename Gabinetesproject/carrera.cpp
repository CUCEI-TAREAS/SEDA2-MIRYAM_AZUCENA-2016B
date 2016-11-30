#include "carrera.h"

Carrera::Carrera()
{
}
Carrera::Carrera(QString ca)
{
    id = CAREER_NO_VERIFY;
    carrera = ca;
}

Carrera::Carrera(QString value, QString caree)
{
    id = value;
   carrera = caree;
}

QString Carrera::getCarrera() const
{
    return carrera;
}

void Carrera::setCarrera(const QString value)
{
    carrera = value;
}

QString Carrera::getId() const
{
    return id;
}

void Carrera::setId(QString value)
{
    id = value;
}
