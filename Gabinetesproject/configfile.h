#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QFile>
#include <QByteArray>

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

    void createConfigFile();
    bool checkStructureFile();
    bool isOpen();
};

#endif // CONFIGFILE_H
