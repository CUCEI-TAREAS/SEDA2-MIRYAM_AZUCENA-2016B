#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QTextStream>

#define HOST "host"
#define PORT "port"
#define USER "user"
#define PASS "pass"
#define DB  "db"

//#define REGULAR_EXPRESSION HOST " .*\n" PORT " .*\n" USER " .*\n" PASS " .*\n" DB " .*"
#define REGULAR_EXPRESSION HOST " (.*)\n" PORT " (.*)\n" USER " (.*)\n" PASS " (.*)\n" DB " (.*)"

#define EXP_REG_HOST 1
#define EXP_REG_PORT 2
#define EXP_REG_USER 3
#define EXP_REG_PASS 4
#define EXP_REG_DB 5


#define NAME_FILE "config.txt"

#define FAIL        -1 // exists corrupted
#define NOEXISTS    0
#define EMPTY       1
#define EXISTS      2
#define DONE        4 // CHECK FILE STRUCTURE


class ConfigFile
{
private:

    unsigned char statusFile;
    QFile *config = nullptr;
    QRegularExpression *structure = nullptr;
    QRegularExpressionMatch match;

    QString host, port, user, pass, database;

public:
    ConfigFile();

    void createConfigFile(QString, QString, QString, QString, QString );
    bool checkStructureFile();
    void loadDataConnection();

    char getStatusFile();
    void setStatusFile(char);

    QString getHost() const;
    void setHost(const QString &value);
    QString getPort() const;
    void setPort(const QString &value);
    QString getUser() const;
    void setUser(const QString &value);
    QString getPass() const;
    void setPass(const QString &value);
    QString getNameDB() const;
    void setNameDB(const QString &value);
};

#endif // CONFIGFILE_H
