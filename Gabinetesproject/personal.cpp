#include "personal.h"

Personal::Personal()
{

}

Personal::Personal(QString code)
{
    codigo = code;
}

Personal::Personal(Name* n, QString code, QString mail, QString phone, QString exp, QString sta, QString semes, QString cre, Carrera* career, Personal* tuto)
{
    nombre = n;
    codigo = code;
    email = mail;
    telefono = phone;
    expediente = exp;
    status = sta;
    semestre = semes;
    creditosCursados = cre;
    carrera = career;
    tutor = tuto;
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

QString Personal::getStatus() const
{
    return status;
}

void Personal::setStatus(QString value)
{
    status = value;
}

QString Personal::getSemestre() const
{
    return semestre;
}

void Personal::setSemestre(QString value)
{
    semestre = value;
}

QString Personal::getCreditosCursados() const
{
    return creditosCursados;
}

void Personal::setCreditosCursados(QString value)
{
    creditosCursados = value;
}

QString Personal::getPermisos() const
{
    return permisos;
}

void Personal::setPermisos(QString value)
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

