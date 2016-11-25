#ifndef CARRERA_H
#define CARRERA_H

#include <QString>

class Carrera
{
private:
    int id;
    QString carrera;

public:
    Carrera();

    int getId() const;
    void setId(int value);

    QString getCarrera() const;
    void setCarrera(const QString value);
};

#endif // CARRERA_H
