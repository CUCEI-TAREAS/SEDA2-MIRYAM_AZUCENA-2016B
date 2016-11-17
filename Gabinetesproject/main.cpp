#include <QApplication>
#include "guigabinete.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        GUIGabinete app;

    return a.exec();
}

// database use postgresql

/* 
High priority

    done ; message around db is create sicces
    tables and defaults user on DB ; these might db connection as root

    loadAllCodes() to linked list : seek faster exists
    loadConnectionDB() // create connection DB from file // when file already exists
    loadAdmins() // to load on tutorCombox
    addPerson()
    personExist() // by codigo
    logAsAdmin()
    createMeeting() & dateSchedule() // focused available to date
    
Second 

    verifyeConnectionFromFileConfigToDB() // when fileConfig already exists
    validationsToPerson()
    Fix dependencies and cleanUp QObjects and ram researched
    issuesOnGithub
 */
