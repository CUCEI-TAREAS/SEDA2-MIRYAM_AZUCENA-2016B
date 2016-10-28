#include <QApplication>

#include <QtSql>
#include <QtSql/QSqlDatabase>

#include "guigabinete.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        //GUIGabinete app;
        QSqlDatabase s = QSqlDatabase::addDatabase("QMYSQL");
        s.setHostName("localhost");
        s.setDatabaseName("information_schema");
        s.setUserName("felipe");
        s.setPassword("hola");
        bool ok = s.open();

        if(ok){
            return 1;
        }

    return a.exec();
}

/* if config.txt doesnt exist
 * captureDatabase and create config.txt
 *
 * if connection is failed
 * show message /
 *
 */
