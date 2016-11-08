#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QTextStream>

#define HOST "host "
#define PORT "port "
#define USER "user "
#define PASS "pass "
#define DB  "db "

#define REGULAR_EXPRESSION "/("HOST" .+\n)("PORT" \d+\n)("USER" .+\n)("PASS" .+\d\n)("DB" .+)/g"

#define NAME_FILE "config.txt"

#define FAIL        -1 // exists corrupted
#define NOEXISTS    0
#define EMPTY       1
#define EXISTS      2
#define DONE        4 // CHECK FILE STRUCTURE


class ConfigFile
{
private:

    char statusFile;
    QFile *config = nullptr;
    QRegularExpression *structure = nullptr;

public:
    ConfigFile();

    void createConfigFile(QString, QString, QString, QString, QString );
    void checkStructureFile();

    char getStatusFile();
    void setStatusFile(char);
};

#endif // CONFIGFILE_H
