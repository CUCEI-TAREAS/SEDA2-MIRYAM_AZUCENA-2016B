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

#define REGULAR_EXPRESSION "(" HOST ".+ \n)"

#define NAME_FILE "config.txt"

enum{
    NOEXISTS,
    FAIL,
    DONE, // CHECK FILE STRUCTURE
};

class ConfigFile
{
private:
    char statusFile;
    QFile *config = nullptr;
    QRegularExpression *structure = nullptr;

public:
    ConfigFile();

    void createConfigFile(QString, QString, QString, QString, QString );
    bool checkStructureFile();
};

#endif // CONFIGFILE_H
