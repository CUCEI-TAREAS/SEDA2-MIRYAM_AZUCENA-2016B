#ifndef PERSONAL_H
#define PERSONAL_H

#include <QString>

#include "carrera.h"
#include  "name.h"

#define STATUS_PERSONAL_ACTIVE "ACTIVO"
#define STATUS_PERSONAL_INACTIVE "INACTIVO"

#define ACTIVE      '1'
#define INACTIVE    '0'

class Personal
{
private:

    QString codigo,
    email,
    telefono,
    expediente,
    status, // status did work ?
    semestre,
    creditosCursados,
    permisos; // status did work ?

    Name *nombre =  nullptr;

    Carrera* carrera = nullptr;
    Personal* tutor = nullptr;

public:
    Personal();
    Personal(QString);
    Personal(Name*, QString, QString, QString, QString, QString, QString, QString, Carrera*, Personal*);

    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getExpediente() const;
    void setExpediente(const QString &value);
    QString getStatus() const;
    void setStatus(QString value);
    QString getSemestre() const;
    void setSemestre(QString value);
    QString getCreditosCursados() const;
    void setCreditosCursados(QString value);
    QString getPermisos() const;
    void setPermisos(QString value);


    Carrera *getCarrera() const;
    void setCarrera(Carrera *value);
    Personal *getTutor() const;
    void setTutor(Personal *value);


    Name *getNombre() const;
    void setNombre(Name *value);
};

#endif // PERSONAL_H
