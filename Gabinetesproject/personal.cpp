#include "personal.h"

Personal::Personal()
{

}
Name *Personal::getNombre() const
{
    return nombre;
}

void Personal::setNombre(Name *value)
{
    nombre = value;
}


QString Personal::getCodigo() const
{
    return codigo;
}

void Personal::setCodigo(const QString &value)
{
    codigo = value;
}

QString Personal::getEmail() const
{
    return email;
}

void Personal::setEmail(const QString &value)
{
    email = value;
}

QString Personal::getTelefono() const
{
    return telefono;
}

void Personal::setTelefono(const QString &value)
{
    telefono = value;
}

QString Personal::getExpediente() const
{
    return expediente;
}

void Personal::setExpediente(const QString &value)
{
    expediente = value;
}

char Personal::getStatus() const
{
    return status;
}

void Personal::setStatus(char value)
{
    status = value;
}

char Personal::getSemestre() const
{
    return semestre;
}

void Personal::setSemestre(char value)
{
    semestre = value;
}

char Personal::getCreditosCursados() const
{
    return creditosCursados;
}

void Personal::setCreditosCursados(char value)
{
    creditosCursados = value;
}

char Personal::getPermisos() const
{
    return permisos;
}

void Personal::setPermisos(char value)
{
    permisos = value;
}


Carrera *Personal::getCarrera() const
{
    return carrera;
}

void Personal::setCarrera(Carrera *value)
{
    carrera = value;
}

Personal *Personal::getTutor() const
{
    return tutor;
}

void Personal::setTutor(Personal *value)
{
    tutor = value;
}

