#ifndef CARRERA_H
#define CARRERA_H

#include <QString>

#define CAREER_NO_VERIFY -1

class Carrera
{
private:
    // int id; //CHANGE TO STRING
    QString id, carrera;

public:
    Carrera();
    Carrera(QString);

    QString getId() const;
    void setId(QString value);

    QString getCarrera() const;
    void setCarrera(const QString value);
};

#endif // CARRERA_H
