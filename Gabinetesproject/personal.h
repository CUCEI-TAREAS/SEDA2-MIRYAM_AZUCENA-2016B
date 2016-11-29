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

    QChar status, // status did work ?
    semestre,
    creditosCursados,
    permisos; // status did work ?

    Name *nombre =  nullptr;

    Carrera* carrera = nullptr;
    Personal* tutor = nullptr;

public:
    Personal();
    Personal(QString);
    Personal(Name*, QString, QString, QString, QString, QChar, QChar, QChar, Carrera*, Personal*);

    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getExpediente() const;
    void setExpediente(const QString &value);
    QChar getStatus() const;
    void setStatus(QChar value);
    QChar getSemestre() const;
    void setSemestre(QChar value);
    QChar getCreditosCursados() const;
    void setCreditosCursados(QChar value);
    QChar getPermisos() const;
    void setPermisos(QChar value);


    Carrera *getCarrera() const;
    void setCarrera(Carrera *value);
    Personal *getTutor() const;
    void setTutor(Personal *value);


    Name *getNombre() const;
    void setNombre(Name *value);
};

#endif // PERSONAL_H
