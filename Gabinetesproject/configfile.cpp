#include "configfile.h"

ConfigFile::ConfigFile()
{
    config = new QFile(NAME_FILE);

    if(config->exists(NAME_FILE)){
        statusFile = EXISTS;
        checkStructureFile();
    }else{
        statusFile = NOEXISTS;
        config = nullptr;
    }
}

void ConfigFile::createConfigFile(QString host,
                                  QString port,
                                  QString user,
                                  QString pass,
                                  QString db)
{
    config = new QFile(NAME_FILE);
    config->open(QFile::WriteOnly | QFile::Text);

    QTextStream out(config);
    out<<HOST<<" "<<host<<endl;
    out<<PORT<<" "<<port<<endl;
    out<<USER<<" "<<user<<endl;
    out<<PASS<<" "<<pass<<endl;
    out<<DB<<" "<<db;
    out.flush();

    statusFile = DONE;
    config->close();
    config = nullptr;
}

void ConfigFile::checkStructureFile()
{
    config->open(QFile::ReadOnly | QFile::Text);
    structure = new QRegularExpression (REGULAR_EXPRESSION);
    QRegularExpressionMatch match;

    QTextStream in(config);
    QString temp;
    temp = in.readAll();
    match = structure->match(temp);
    config->close();
    config = nullptr;

    if(match.hasMatch()){
          statusFile = DONE;
    } else {
        statusFile = FAIL;
    }

    return;
}

char ConfigFile::getStatusFile()
{
    return statusFile;
}

void ConfigFile::setStatusFile(char n)
{
    statusFile = n;
}
