#include "personal.h"

Personal::Personal()
{

}

Personal::Personal(QString code)
{
    codigo = code;
}

Personal::Personal(Name* n, QString code, QString mail, QString phone, QString exp, QChar sta, QChar semes, QChar cre, Carrera* career, Personal* tuto)
{
    nombre = n;
    codigo = code;
    email = mail;
    telefono = phone;
    expediente = exp;
    status = sta;
    semestre = semes;
    creditosCursados = cre;
    // permisos = per;
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

QChar Personal::getStatus() const
{
    return status;
}

void Personal::setStatus(QChar value)
{
    status = value;
}

QChar Personal::getSemestre() const
{
    return semestre;
}

void Personal::setSemestre(QChar value)
{
    semestre = value;
}

QChar Personal::getCreditosCursados() const
{
    return creditosCursados;
}

void Personal::setCreditosCursados(QChar value)
{
    creditosCursados = value;
}

QChar Personal::getPermisos() const
{
    return permisos;
}

void Personal::setPermisos(QChar value)
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

