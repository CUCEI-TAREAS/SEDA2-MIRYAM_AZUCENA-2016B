#include "configfile.h"

ConfigFile::ConfigFile()
{
    config = new QFile(NAME_FILE);

    if(config->exists(NAME_FILE)){
        checkStructureFile();
    }else{
        config->open(QFile::WriteOnly | QFile::Text);
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

bool ConfigFile::checkStructureFile()
{
    structure = new QRegularExpression (REGULAR_EXPRESSION);

    QTextStream in(config);
    if(structure->match(in.readAll()).hasMatch())
        return false;

    return true;
}
