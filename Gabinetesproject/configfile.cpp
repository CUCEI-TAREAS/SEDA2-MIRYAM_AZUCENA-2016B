#include "configfile.h"

QString ConfigFile::getHost() const
{
    return host;
}

void ConfigFile::setHost(const QString &value)
{
    host = value;
}

QString ConfigFile::getPort() const
{
    return port;
}

void ConfigFile::setPort(const QString &value)
{
    port = value;
}

QString ConfigFile::getUser() const
{
    return user;
}

void ConfigFile::setUser(const QString &value)
{
    user = value;
}

QString ConfigFile::getPass() const
{
    return pass;
}

void ConfigFile::setPass(const QString &value)
{
    pass = value;
}

QString ConfigFile::getNameDB() const
{
    return database;
}

void ConfigFile::setNameDB(const QString &value)
{
    database = value;
}

ConfigFile::ConfigFile()
{
    config = new QFile(NAME_FILE);

    if(config->exists(NAME_FILE)){
        statusFile = EXISTS;
        if (checkStructureFile()){
            loadDataConnection();
        } else{
            // msg for user, file is fail
        }
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

bool ConfigFile::checkStructureFile()
{
    config->open(QFile::ReadOnly | QFile::Text);
    structure = new QRegularExpression (REGULAR_EXPRESSION);

    QTextStream in(config);
    QString temp;
    temp = in.readAll();
    match = structure->match(temp);
    config->close();
    config = nullptr;

    if(match.hasMatch()){
        statusFile = DONE;
        return true;
    } else {
        statusFile = FAIL;
        return false;
    }
}

void ConfigFile::loadDataConnection()
{
    // http://doc.qt.io/qt-5/qregularexpression.html#extracting-captured-substrings

    host = match.captured(EXP_REG_HOST);
    port = match.captured(EXP_REG_PORT);
    user = match.captured(EXP_REG_USER);
    pass = match.captured(EXP_REG_PASS);
    database =  match.captured(EXP_REG_DB);
}

char ConfigFile::getStatusFile()
{
    return statusFile;
}

void ConfigFile::setStatusFile(char n)
{
    statusFile = n;
}
