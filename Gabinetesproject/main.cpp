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
    addPerson()
    logAsAdmin()
    createMeeting() & dateSchedule() // focused available to date
    
Second 
    Fix dependencies and researched
 */
