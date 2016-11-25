#ifndef NAME_H
#define NAME_H

#include <QString>

class Name
{
private:
    QString firtsName, // mandatory
    secondName,
    thirdName,
    LastNamePaternal, // mandatory
    LastNameMaternal; // mandatory

public:
    Name();

    QString getFirtsName() const;
    void setFirtsName(const QString &value);

    QString getSecondName() const;
    void setSecondName(const QString &value);

    QString getThirdName() const;
    void setThirdName(const QString &value);

    QString getLastNameMaternal() const;
    void setLastNameMaternal(const QString &value);

    QString getLastNamePaternal() const;
    void setLastNamePaternal(const QString &value);


};

#endif // NAME_H
