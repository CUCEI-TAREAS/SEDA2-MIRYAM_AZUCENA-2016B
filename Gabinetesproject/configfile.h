#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QFile>

#define NAME_FILE "config.txt"

class ConfigFile
{
private:
    QFile *config = nullptr;

public:
    ConfigFile();
};

#endif // CONFIGFILE_H
