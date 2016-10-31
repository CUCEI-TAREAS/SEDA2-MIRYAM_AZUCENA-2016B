#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QFile>
#include <QTextStream>

#define HOST "host "
#define PORT "port "
#define USER "user "

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

public:
    ConfigFile();

    void createConfigFile(QString, QString, QString, QString, QString );
    bool checkStructureFile();
    bool isOpen();
};

#endif // CONFIGFILE_H
