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
    done ; implement name as typedata
    done ; tables and defaults user on DB ; these might db connection as root
    done ; create all indepences tables, after tables  with dependencies and foreign keys

    improve relations on cascade or // product_no integer REFERENCES products ON DELETE RESTRICT,
    order_id integer REFERENCES orders ON DELETE CASCADE,

    loadAll() CAreers, Roles, admin
    loadAllCodesPerson() to linked list : seek faster exists
    loadConnectionDB() // create connection DB from file // when file already exists
    loadAdmins() // to load on tutorCombox
    addPerson()
    personExist() // by codigo
    logAsAdmin()
    createMeeting() & dateSchedule() // focused available to date
    sendMail()

Second 

    // user and db always must be lowercase
    verifyeConnectionFromFileConfigToDB() // when fileConfig already exists
    validationsToPerson()
    Fix dependencies and cleanUp QObjects and ram researched
    get focus on Contrasena text on captureDB
    issuesOnGithub
 */
