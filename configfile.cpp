#include "configfile.h"

ConfigFile::ConfigFile()
{
    config = new QFile(NAME_FILE);

    if(config->exists(NAME_FILE)){
        statusFile = EXISTS;
        checkStructureFile();
    }else{
        statusFile = NOEXISTS;
        //config->open(QFile::WriteOnly | QFile::Text);
        //createConfigFile();
    }
}

void ConfigFile::createConfigFile(QString host,
                                  QString port,
                                  QString user,
                                  QString pass,
                                  QString db)
{
    QTextStream out(config);
    out<<HOST<<host;
    out<<PORT<<port;
    out<<USER<<user;
    out<<PASS<<pass;
    out<<DB<<db;
}

void ConfigFile::checkStructureFile()
{
    structure = new QRegularExpression (REGULAR_EXPRESSION);

    QTextStream in(config);
    if(structure->match(in.readAll()).hasMatch()){
        statusFile = DONE;
    } else {
        statusFile = FAIL;
    }
}

char ConfigFile::getStatusFile()
{
    return statusFile;
}

void ConfigFile::setStatusFile(char n)
{
    statusFile = n;
}
