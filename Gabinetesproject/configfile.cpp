#include "configfile.h"

ConfigFile::ConfigFile()
{
    config = new QFile(NAME_FILE);
    if(!config->open(QIODevice::ReadOnly))
        statusFile = NOEXISTS;
    else{

    }

}

void ConfigFile::createConfigFile()
{

}

bool ConfigFile::checkStructureFile()
{
/* FILE STRUCTURE
user: ANYTEXT
pass: ANYTEXT
*/
}

bool ConfigFile::isOpen()
{

}
