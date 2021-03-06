#include <QApplication>
#include "guigabinete.h"
//#include "admintask.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //AdminTask app;
    GUIGabinete app;

    return a.exec();
}

/* 
 * All be on RAM ...
 * But addes, changes and modify should store directly on DB
 * Then stored, inmediatly load to list on RAM
 *
 *
Critical priority
    // fix initAdminLogin
    Tickets
    clean up code [refactor] separate class gabinete
    update msg pop-up, current  msg are deprecated

    DB
        When connect is done, but database exists /
            verify DB and show option [delete.new ] /

        When connect file is create but db is no exists...


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
    done ; loadAsAdmin(): learn how to user QListWidget with QStackWidget also QWidget Parents
    done ; orderByQuickSort():methods on List
    done ; personExist() // by codigo

    view all students // quickSort // from Ram by code
    generate PDF to reports, Date and statistics statistics
    logAsAdmin()
    createMeeting() & dateSchedule() // focused available to date
    sendMail()

Features / Improvements

    Export / Import all data


Second
    separate every interface from gui gabinete to type class
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
