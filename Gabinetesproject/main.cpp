#include <QApplication>
#include "guigabinete.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GUIGabinete app;

    return a.exec();
}

/* 
 * All be on RAM ...
 * But addes, changes and modify should store directly on DB
 * Then stored, inmediatly load to list on RAM
 *
High priority

    done ; message around db is create sicces
    done ; implement name as typedata
    done ; tables and defaults user on DB ; these might db connection as root
    done ; create all indepences tables, after tables  with dependencies and foreign keys
    done ; loadConnectionDB() // create connection DB from file // when file already exists
    done ; loadAllToLinkedList() CAreers, Roles, admin
    done ; loadAllCodesPerson() to linked list : seek faster exists
    done ; loadAdmins() // to load on GUI e.g. tutorCombox
    done ; addPerson() new algorithms, all stored as TEXT, not more Char

    separate every interface from gui gabinete to type class
    ...loadAsAdmin():other Qwidget to admin task // create new tab to admin task
    orderByQuickSort
    generate PDF to reports, Date and statistics statistics
    personExist() // by codigo
    logAsAdmin()
    createMeeting() & dateSchedule() // focused available to date
    sendMail()

Second
    // show calendar/days available from registro GUI bottom
    addCalendar()
    new Table to states person [active / inactive / ]

    improve relations on cascade or // product_no integer REFERENCES products ON DELETE RESTRICT,
    order_id integer REFERENCES orders ON DELETE CASCADE,

    security passwords, algorithms to codify
    // user and db always must be lowercase
    verifyeConnectionFromFileConfigToDB() // when fileConfig already exists
    validationsToPerson()
    Fix dependencies and cleanUp QObjects and ram researched
    get focus on Contrasena text on captureDB
    issuesOnGithub
 */
