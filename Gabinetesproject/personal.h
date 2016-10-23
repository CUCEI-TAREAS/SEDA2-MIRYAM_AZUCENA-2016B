#ifndef PERSONAL_H
#define PERSONAL_H

#include <QString>

#include "carrera.h"

class Personal
{
private:

    QString name,
        codigo,
        email,
        telefono,
        expediente;

     char status,
        semestre,
        creditosCursados,
        permisos;

     Carrera* carrera = nullptr;
     Personal* tutor = nullptr;


public:
    Personal();
};

#endif // PERSONAL_H
