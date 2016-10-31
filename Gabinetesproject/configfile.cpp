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

}

bool ConfigFile::checkStructureFile()
{
    QTextStream in(config);

    /* FILE STRUCTURE
host ANYTEXT
port number
user ANYTEXT
pass ANYTEXT
db ANYTEXT
*/
}

bool ConfigFile::isOpen()
{

}
