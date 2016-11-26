#include "guigabinete.h"


GUIGabinete::GUIGabinete()
{
    status =  START;
    db = new Database();
    fileConfig = new ConfigFile();
    if(fileConfig->getStatusFile() < EXISTS ){
        initCaptureDB();
        QMessageBox::warning(captureDB, CONFIGURE_DB, BODY_CONFIGURE_DB_CAPTUREDB, 1, 2);
        status =  SETUPDB;
    } else {
        if ( db->connectDB(fileConfig->getHost(), fileConfig->getPort(), fileConfig->getUser(), fileConfig->getPass(), fileConfig->getNameDB())){
            addPersonalRegistroWidget();
        } else {
            // MSG SE PUDO CONECTAR AL SERVER, PERO NO A LA BASE DE DATOS
        }

    }
}


void GUIGabinete::initCaptureDB()
{
    QLabel  *hostLabel,
            *portLabel,
            *userLabel,
            *passLabel,
            *dbLabel;

    QVBoxLayout *layout = new QVBoxLayout(captureDB);
    QPushButton *conectar =  new QPushButton(CONECTAR_CAPTUREDB, captureDB);

    hostLabel = new QLabel(HOST_CAPTUREDB, captureDB);
    portLabel = new QLabel(PORT_CAPTUREDB, captureDB);
    userLabel = new QLabel(USER_CAPTUREDB, captureDB);
    passLabel = new QLabel(PASS_CAPTUREDB, captureDB);
    dbLabel = new QLabel(DB_CAPTUREDB, captureDB);

    hostLine = new QLineEdit(DEFAULT_HOST, captureDB);
    portLine = new QLineEdit(DEFAULT_PORT, captureDB);
    userLine = new QLineEdit(DEFAULT_USER, captureDB);
    passLine = new QLineEdit(captureDB);
    passLine->setEchoMode(QLineEdit::Password);
    dbLine = new QLineEdit(DEFAULT_DB, captureDB);

    layout->addWidget(hostLabel, 1);
    layout->addWidget(hostLine, 2);

    layout->addWidget(portLabel, 3);
    layout->addWidget(portLine, 4);

    layout->addWidget(userLabel, 5);
    layout->addWidget(userLine, 6);

    layout->addWidget(passLabel, 7);
    layout->addWidget(passLine, 8);

    layout->addWidget(dbLabel, 9);
    layout->addWidget(dbLine, 10);

    layout->addWidget(conectar, 11);

    captureDB = new QWidget();
    captureDB->setMinimumWidth(MINIMUM_WIDTH);
    captureDB->setLayout(layout);
    captureDB->setWindowTitle(TITLE_CAPTUREDB);

    // connects
    connect(conectar, SIGNAL(clicked()), this,  SLOT(connectDB()));
    connect(this, SIGNAL(fileConfigReady()), this, SLOT(deleteCaptureDB()));
    captureDB->show();
}

void GUIGabinete::initPersonalRegistro()
{
    //layout
    registroGroupLayout = new QGroupBox();
    registroGridLayout = new QGridLayout();

    // labels
    nombreLabel = new QLabel(NAME_PERSONAL);
    apeidoLabel = new QLabel(LAST_NAME_PERSONAL);
    codigoLabel = new QLabel(CODE_PERSONAL);
    emailLabel = new QLabel(EMAIL_PERSONAL);
    telefonoLabel = new QLabel(PHONE_PERSONAL);
    expedienteLabel = new QLabel(EXP_PERSONAL);
    statusPersonalLabel = new QLabel (STATE_PERSONAL);
    semestreLabel =  new QLabel (SEMESTRE_PERSONAL);
    creditosCursadosLabel = new QLabel(CURRENT_PERSONAL);
    carreraLabel = new QLabel (CARRERA_PERSONAL); // combox
    tutorLabel = new QLabel (TUTOR_ESTUDIANTE);  // combox

    // Lines
    nombreLine = new QLineEdit();
    apeidoLine = new QLineEdit();
    codigoLine = new QLineEdit();
    emailLine = new QLineEdit();
    telefonoLine = new QLineEdit();
    expedienteLine = new QLineEdit();
    creditosCursadosLine = new QLineEdit();

    // QComboBox
    statusPersonalCombobox = new QComboBox();
    statusPersonalCombobox->addItem(STATUS_PERSONAL_ACTIVE);
    statusPersonalCombobox->addItem(STATUS_PERSONAL_INACTIVE);

    carreraCombobox = new QComboBox();
    tutorCombobox = new QComboBox();

    // QSpinBox
    semestreSpin = new QSpinBox();
    semestreSpin->setRange(MIN_RANGE_SEMESTRE, MAX_RANGE_SEMESTRE);

    // QPushButton
    addPersonalButton = new QPushButton(TEXT_ADD_PERSONAL);

    // implementation
    registroGridLayout->addWidget(nombreLabel, 0, 0);
    registroGridLayout->addWidget(nombreLine, 0, 1);

    registroGridLayout->addWidget(apeidoLabel, 1, 0);
    registroGridLayout->addWidget(apeidoLine, 1, 1);

    registroGridLayout->addWidget(codigoLabel, 2, 0);
    registroGridLayout->addWidget(codigoLine, 2, 1);

    registroGridLayout->addWidget(emailLabel, 3, 0);
    registroGridLayout->addWidget(emailLine, 3, 1);

    registroGridLayout->addWidget(telefonoLabel, 4, 0);
    registroGridLayout->addWidget(telefonoLine, 4, 1);

    registroGridLayout->addWidget(expedienteLabel, 5, 0);
    registroGridLayout->addWidget(expedienteLine, 5, 1);

    registroGridLayout->addWidget(statusPersonalLabel, 6, 0);
    registroGridLayout->addWidget(statusPersonalCombobox, 6, 1);

    registroGridLayout->addWidget(semestreLabel, 7, 0);
    registroGridLayout->addWidget(semestreSpin, 7, 1);

    registroGridLayout->addWidget(carreraLabel, 8, 0);
    registroGridLayout->addWidget(carreraCombobox, 8, 1);

    registroGridLayout->addWidget(tutorLabel, 9, 0);
    registroGridLayout->addWidget(tutorCombobox, 9, 1);

    registroGridLayout->addWidget(addPersonalButton, 10, 0, 1, 2);
    registroGroupLayout->setLayout(registroGridLayout);
}

bool GUIGabinete::allValidationsAddPersonal()
{
    // check only mandatory fields

    return true;
}

void GUIGabinete::loadAllToLinkedList()
{
    carreras = new List<Carrera>();
    roles = new List<Carrera>();
    personal = new List<Personal>();
    admins = new List<Admin>();

    loadListCarreas(carreras);
    loadListRoles(roles);
    loadListPersonal(personal);
    loadListAdmins(admins);
}

void GUIGabinete::loadAllToGuiAddPersonal()
{
    loadGuiCarreras(carreraCombobox, carreras);
}

void GUIGabinete::loadGuiCarreras(QComboBox *combo, List<Carrera>* myList)
{
    Node<Carrera>* node = nullptr;
    Carrera temp;

    node = myList->head();

    while ( node != nullptr){
        temp = node->data;
        combo->addItem(temp.getCarrera());
        node = node->next;
    }
}

void GUIGabinete::loadListCarreas(List<Carrera> * myList)
{
    Carrera *temp = nullptr;
    QSqlQuery result = db->selectAll(NAME_TABLE_CAREER);

    while(result.next()){

        temp = new Carrera();
        temp->setId(result.value(CAREER_ID).toString());
        temp->setCarrera(result.value(CAREER_ROL).toString());

        myList->add_head(*temp);
    }

    temp = nullptr;
    delete temp;
}

void GUIGabinete::loadListRoles(List<Carrera> * myList)
{
    Carrera *temp = nullptr;
    QSqlQuery result = db->selectAll(NAME_TABLE_ROLES);

    while(result.next()){

        temp = new Carrera();
        temp->setId(result.value(ROLES_ID).toString());
        temp->setCarrera(result.value(ROLES_ROL).toString());

        myList->add_head(*temp);
    }

    temp = nullptr;
    delete temp;
}

void GUIGabinete::loadListPersonal(List<Personal> *myList)
{
    Personal *temp = nullptr,
            *tutor = nullptr;

    Name *nombre = nullptr;
    Carrera *carrera = nullptr;

    QSqlQuery result = db->selectAll(NAME_TABLE_PERSON);

    while(result.next()){

        temp = new Personal();
        temp->setCodigo(result.value(PERSON_CODE).toString());
        temp->setEmail(result.value(PERSON_MAIL).toString());
        temp->setTelefono(result.value(PERSON_PHONE).toString());
        temp->setExpediente(result.value(PERSON_EXPEDIENTE).toString());

        // status did work ?
        temp->setSemestre(result.value(PERSON_CURRENTSEMESTRE).toChar());
        temp->setCreditosCursados(result.value(PERSON_CREDITS).toChar());
        temp->setSemestre(result.value(PERSON_CURRENTSEMESTRE).toChar());

        nombre = new Name();
        nombre->setFirtsName(result.value(PERSON_FIRSTNAME).toString());
        nombre->setSecondName(result.value(PERSON_SECONDNAME).toString());
        nombre->setThirdName(result.value(PERSON_THIRDNAME).toString());
        nombre->setLastNamePaternal(result.value(PERSON_LASTNAMEPATERNAL).toString());
        nombre->setLastNameMaternal(result.value(PERSON_LASTNAMEPATERNAL).toString());

        // retrieve id career & tutor and linked from Career & Tutor(Code Person) list to Person

        temp->setNombre(nombre);

        myList->add_head(*temp);

        temp = nullptr;
        tutor = nullptr;
        nombre = nullptr;
        carrera = nullptr;
    }
}

void GUIGabinete::loadListAdmins(List<Admin>* myList)
{
    Admin *temp = nullptr;
    QSqlQuery result = db->selectAll(NAME_TABLE_ADMIN);

    while(result.next()){

        temp = new Admin();
        temp->setId(result.value(ADMIN_ID).toString());
        temp->setAdmin(result.value(ADMIN_PERSON).toString());
        temp->setPass(result.value(ADMIN_PASS).toString());
        myList->add_head(*temp);
    }

    temp = nullptr;
    delete temp;
}

void GUIGabinete::loadListCarreas(List<Carrera> *, QString)
{

}

void GUIGabinete::loadListRoles(List<Carrera> *, QString)
{

}

void GUIGabinete::loadListAdmins(List<Admin> *, QString)
{

}

void GUIGabinete::loadListPersonal(List<Personal> *, QString)
{

}

void GUIGabinete::clearRegistro()
{

}

void GUIGabinete::deleteCaptureDB()
{
    captureDB->hide();
    captureDB = nullptr;
    //captureDB->destroy();
    delete captureDB;

    addPersonalRegistroWidget();
}

char GUIGabinete::connectDB()
{
    if(db->tryConnectUser(hostLine->text(), portLine->text(), userLine->text(), passLine->text())){


        //  if db connection is done, try connect with default DB gave by user
        // if db is not found, create itself

        status = SETUPDB;

        if (db->createDB(dbLine->text())){
            fileConfig->createConfigFile(hostLine->text(), portLine->text(), userLine->text(), passLine->text(), dbLine->text());
            fileConfigReady();
            QMessageBox::information(captureDB, TITLE_DB_DONE, TITLE_DB_MSG, 1, 2);
            return STATE_DB_DONE;
        }
        else
            QMessageBox::critical(captureDB, TITLE_FAIL_PERMISSION, BODY_FAIL_PERMISSION, 1, 2);

        return STATE_DB_NO_DB;

    } else {
        QMessageBox::critical(captureDB, TITLE_FAIL_CAPTUREDB, BODY_FAIL_CAPTUREDB, 1, 2);
        return STATE_DB_NO_CONECCTION;
    }
}

void GUIGabinete::addPersonalRegistroWidget()
{
    // GUI
    mainWidget = new QWidget();
    window = new QMainWindow();
    mainLayout = new QGridLayout();

    initPersonalRegistro();
    loadAllToLinkedList(); // to insert all data on files and consults
    loadAllToGuiAddPersonal();

    // also init to GabinetePersonal()
    mainLayout->addWidget(registroGroupLayout);
    mainWidget->setLayout(mainLayout);

    window->setCentralWidget(mainWidget);
    window->setWindowTitle(TITLE_APP);
    window->setMinimumWidth(MINIMUM_WIDTH);
    window->show();

    // connects

}

