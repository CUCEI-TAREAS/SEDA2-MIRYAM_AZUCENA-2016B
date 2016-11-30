#include "database.h"

Database::Database()
{}

QSqlQuery Database::selectAll(QString table)
{
    QSqlQuery result(db);
    result.exec(QUERY_SELECT_ALL + table);
    return result;
}

bool Database::createDB(QString name)
{
    QSqlQuery query(db);
    if( query.exec(CREATE_DB+name)){

        db.setDatabaseName(name);
        db.open();

        query.exec(CREATE_TABLE ROLES);
        //query.exec(INSERT_INTO DEFAULT_ROLES);

        query.exec(CREATE_TABLE CAREER);
        query.exec(INSERT_INTO DEFAULT_CAREER);

        query.exec(CREATE_TABLE PERSON);
        query.exec(INSERT_INTO DEFAULT_PERSON);

        query.exec(CREATE_TABLE ADMIN);
        query.exec(INSERT_INTO DEFAULT_ADMIN);

        query.exec(CREATE_TABLE MEETING);


        qDebug () << query.lastError().text();

        return true;
    }
    else
        // maybe db already exists
        // check tables if exists
        // dont override database
        qDebug () << query.lastError().text();
    return false;
}

bool Database::connectDB(QString host, QString port, QString user, QString pass, QString dblocal)
{
    if (tryConnectUser(host, port, user, pass)){

        db.setDatabaseName(dblocal);
        return db.open();

    } else {
        // ...  MSG NO SE PUEDE CONNECTAR AL SERVIDOR
        return false;
    }
}

bool Database::existsPerson(QString code)
{
    QSqlQuery query(db);
    query.exec(EXISTS_PERSON "'" + code + "';");

    if(query.next())
        return true;

    return false;
}

bool Database::addPerson(Personal *person)
{
    QString str,
            nombre, nombre2, nombre3,
            apeido, apeido2,
            codigo,
            email,
            telefono,
            expediente,
            carrera,
            codeTutor,
            state,
            semestre,
            creditos;

    nombre = person->getNombre()->getFirtsName();
    nombre2 = person->getNombre()->getSecondName();
    nombre3 = person->getNombre()->getThirdName();
    apeido = person->getNombre()->getLastNamePaternal();
    apeido2 = person->getNombre()->getLastNameMaternal();

    codigo = person->getCodigo();
    email = person->getEmail();
    telefono = person->getTelefono();
    expediente = person->getExpediente();
    state = person->getStatus();
    semestre = person->getSemestre();
    creditos = person->getCreditosCursados();

    carrera =  person->getCarrera()->getId();
    codeTutor =  person->getTutor()->getCodigo();

    str =  INSERT_INTO NAME_TABLE_PERSON "VALUES ( '" + codigo + "',"
            + "'" + nombre + "', "
            + "'" + nombre2 + "', "
            + "'" + nombre3 + "', "
            + "'" + apeido + "', "
            + "'" + apeido2 + "', "
            + "'" + email + "', "
            + "'" + telefono + "', "
            + "'" + expediente + "', "
            + "'" + state + "', "
            + "'" + semestre + "', "
            + "'" + creditos + "', "
            + " " + carrera + ", "
            +  codeTutor +
            + ");";

    QSqlQuery query(db);
    if(query.exec(str)){
        return true;
    }
    qDebug() << query.lastError().text();
    return false;
}

bool Database::checkAdmin(QString code, QString pass)
{
    QSqlQuery query(db);
    query.exec(EXISTS_ADMIN "'" + code + "';");

    if(query.next()){
        if(query.value(EXISTS_ADMIN_PASS).toString() == pass){
            // admin exists
            return true;
        }
    }
    return false;
}

bool Database::tryConnectUser(QString host, QString port, QString user, QString pass)
{
    db = QSqlDatabase::addDatabase(TYPE_DB);
    db.setHostName(host);
    db.setPort(port.toInt());
    db.setUserName(user);
    db.setPassword(pass);

    bool connection = db.open();

    if (!connection)
        qDebug () << db.lastError().text();

    return connection;
}
