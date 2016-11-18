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
    expediente;

    char status,
    semestre,
    creditosCursados,
    permisos;

    Name *nombre =  nullptr;

    Carrera* carrera = nullptr;
    Personal* tutor = nullptr;

public:
    Personal();

    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getExpediente() const;
    void setExpediente(const QString &value);
    char getStatus() const;
    void setStatus(char value);
    char getSemestre() const;
    void setSemestre(char value);
    char getCreditosCursados() const;
    void setCreditosCursados(char value);
    char getPermisos() const;
    void setPermisos(char value);


    Carrera *getCarrera() const;
    void setCarrera(Carrera *value);
    Personal *getTutor() const;
    void setTutor(Personal *value);


    Name *getNombre() const;
    void setNombre(Name *value);
};

#endif // PERSONAL_H
