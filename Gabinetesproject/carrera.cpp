#include "carrera.h"

int Carrera::getId() const
{
    return id;
}

void Carrera::setId(int value)
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
    id = 0;
    carrera = "";
}
