#ifndef CARRERA_H
#define CARRERA_H

#include <QString>

class Carrera
{
private:
    // int id; //CHANGE TO STRING
    QString id, carrera;

public:
    Carrera();

    QString getId() const;
    void setId(QString value);

    QString getCarrera() const;
    void setCarrera(const QString value);
};

#endif // CARRERA_H
