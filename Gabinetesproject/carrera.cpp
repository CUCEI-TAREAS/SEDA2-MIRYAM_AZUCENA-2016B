#include "carrera.h"

QString Carrera::getId() const
{
    return id;
}

void Carrera::setId(QString value)
{
    id = value;
}

QString Carrera::getCarrera() const
{
    return carrera;
}

void Carrera::setCarrera(const QString value)
{
    carrera = value;
}

Carrera::Carrera()
{
    // index of table
    id = carrera = "";
}
