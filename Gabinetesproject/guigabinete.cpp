#include "guigabinete.h"


GUIGabinete::GUIGabinete()
{
    status =  START;
    db = new Database();
    fileConfig = new ConfigFile();
    if(fileConfig->getStatusFile() < EXISTS ){
        capturarDB = new WidgetRegDB();
        QMessageBox::warning(capturarDB, CONFIGURE_DB, BODY_CONFIGURE_DB_CAPTUREDB, 1, 2);
        status =  SETUPDB;
    } else {
        if ( db->connectDB(fileConfig->getHost(), fileConfig->getPort(), fileConfig->getUser(), fileConfig->getPass(), fileConfig->getNameDB())){
            addPersonalRegistroWidget();
        } else {

            // MSG SE PUDO CONECTAR AL SERVER, PERO NO A LA BASE DE DATOS
        }

    }
}

QString GUIGabinete::getIdCareerFromList(QString career)
{
    Node<Carrera>* node = nullptr;
    node = carreras->head();

    while ( node != nullptr){
        if( node->data.getCarrera() == career ){
            return node->data.getId();
        }
        node = node->next;
    }
    return CAREER_NO_VERIFY;
}

void GUIGabinete::initPersonalRegistro(QWidget* widget, QFormLayout *layout)
{
    // labels
    nombreLabel = new QLabel(NAME_PERSONAL);
    apeidoLabel = new QLabel(LAST_NAME_PERSONAL);
    codigoLabel = new QLabel(CODE_PERSONAL);
    emailLabel = new QLabel(EMAIL_PERSONAL);
    telefonoLabel = new QLabel(PHONE_PERSONAL);
    expedienteLabel = new QLabel(EXP_PERSONAL);
    statusPersonalLabel = new QLabel (STATE_PERSONAL);
    semestreLabel =  new QLabel (SEMESTRE_PERSONAL);
    creditosCursadosLabel = new QLabel( CURRENT_PERSONAL);
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
    // load by database
    statusPersonalCombobox->addItem(STATUS_PERSONAL_ACTIVE);
    statusPersonalCombobox->addItem(STATUS_PERSONAL_INACTIVE);

    carreraCombobox = new QComboBox();
    tutorCombobox = new QComboBox();

    // QSpinBox
    semestreSpin = new QSpinBox();
    semestreSpin->setRange(MIN_RANGE_SEMESTRE, MAX_RANGE_SEMESTRE);

    // QPushButton
    addPersonalButton = new QPushButton(TITLE_ADD_PERSONAL);

    // implementation
    layout->addRow(nombreLabel,nombreLine);
    layout->addRow(apeidoLabel, apeidoLine);
    layout->addRow(codigoLabel, codigoLine);
    layout->addRow(emailLabel, emailLine);
    layout->addRow(telefonoLabel, telefonoLine);
    layout->addRow(expedienteLabel, expedienteLine);
    layout->addRow(statusPersonalLabel, statusPersonalCombobox);
    layout->addRow(semestreLabel, semestreSpin);
    layout->addRow(carreraLabel, carreraCombobox);
    layout->addRow(tutorLabel, tutorCombobox);
    layout->addRow(addPersonalButton);

    widget->setLayout(layout);

    connect(addPersonalButton, SIGNAL(clicked(bool)), this, SLOT(insertPersonalToDBFromGUI()));
}

void GUIGabinete::initAdminLogin(QWidget *widget, QFormLayout *layout)
{
/*    QPushButton *log = nullptr;
    QLabel *userLabel = nullptr,
            *passLabel = nullptr;

    userLabel = new QLabel(USER_CAPTUREDB);
    passLabel = new QLabel(PASS_CAPTUREDB);

    userLine = new QLineEdit();
    passLine = new QLineEdit();
    passLine->setEchoMode(QLineEdit::Password);

    log = new QPushButton(TITLE_LOGIN_ADMIN);

    layout->addRow(userLabel, userLine);
    layout->addRow(passLabel, passLine);
    layout->addRow(log);

    widget->setLayout(layout);

    connect(log, SIGNAL(clicked(bool)), this, SLOT(logAdmin()));
  */
}

void GUIGabinete::initAdminTask(QWidget *widget, QFormLayout *layout)
{
    // ...
    //widget = new AdminTask();
}

bool GUIGabinete::allValidationsAddPersonal()
{
    // check only mandatory fields

    return true;
}

Personal *GUIGabinete::getGUICurrentPersonal()
{
    QString nombre,
            apeido,
            codigo,
            email,
            telefono,
            expediente,
            carrera, idCarrera,
            codeTutor,
            state,
            semestre,
            creditos;

    nombre = nombreLine->text();
    apeido = apeidoLine->text();
    codigo = codigoLine->text();
    email = emailLine->text();
    telefono = telefonoLine->text();
    expediente = expedienteLine->text();
    state = statusPersonalCombobox->currentText();
    semestre = semestreSpin->text();
    creditos = creditosCursadosLine->text();

    carrera =  carreraCombobox->currentText(); // look on linke

    codeTutor =  tutorCombobox->currentText();
    idCarrera = getIdCareerFromList(carrera);

    Personal *tutor = new Personal(codeTutor);
    Name *name = new Name(nombre, apeido);
    Carrera *career = new Carrera(idCarrera, carrera);

    //
    return new Personal(name, codigo, email, telefono, expediente, state, semestre, creditos, career, tutor);
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
    loadGuiTutores(tutorCombobox, admins);
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

void GUIGabinete::loadGuiTutores(QComboBox *combo, List<Admin> *myList)
{
    Node<Admin>* node = nullptr;
    Admin temp;

    node = myList->head();

    while ( node != nullptr){
        temp = node->data;
        combo->addItem(temp.getAdmin());
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

//... terminate and validate storage on ram
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
    capturarDB->hide();
    //captureDB = nullptr;
    //captureDB->deleteLater();
    //delete captureDB;

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
    // MainWindow
    window = new QMainWindow();

    // widgets
    mainCentralWidget = new QWidget();
    mainRegistro = new QWidget();
    mainAdmin = new QWidget();
    mainAdminLogin = new QWidget(mainAdmin);

    // layouts
    registroMainLayout = new QFormLayout();
    mainCentralLayout =  new QFormLayout();
    adminLoginFormLayout = new QFormLayout();

    initPersonalRegistro(mainRegistro, registroMainLayout);
    initAdminLogin(mainAdminLogin, adminLoginFormLayout);

    tabs = new QTabWidget();
    tabs->addTab(mainRegistro, TITLE_ADD_PERSONAL);
    tabs->addTab(mainAdmin, TITLE_LOGIN_ADMIN);

    mainCentralLayout->addRow(tabs);
    mainCentralWidget->setLayout(mainCentralLayout);

    loadAllToLinkedList(); // to insert all data on files and consults
    loadAllToGuiAddPersonal();

    window->setCentralWidget(mainCentralWidget);
    window->setWindowTitle(TITLE_APP);
    window->setMinimumWidth(MINIMUM_WIDTH);
    window->show();
}

bool GUIGabinete::insertPersonalToDB(Personal* persona)
{

    // .. validations to add a default db
    if (db->existsPerson(persona->getCodigo())){
        QMessageBox::critical(mainRegistro, NO_ADD_PERSONAL, DUPLICATE_PERSONAL, 1, 2);
        return false;
        // msg ya existe ese ID
    }
    if(db->addPerson(persona)){
        loadListPersonal(personal); // load new person to lnked list
        QMessageBox::information(mainRegistro, ADD_PERSONAL, ADD_PERSONAL, 1, 2);
        return true;
    } else {
        QMessageBox::critical(mainRegistro, NO_ADD_PERSONAL, ERROR_ADD_PERSONAL, 1, 2);
        return false;
    }
}

bool GUIGabinete::insertPersonalToDBFromGUI()
{   // ... Person validations as code
    return insertPersonalToDB(getGUICurrentPersonal());
}

void GUIGabinete::logAdmin()
{
    // .. validations GUI
    if (db->checkAdmin(userLine->text(), passLine->text())){
        delete mainAdminLogin;
        adminProvider = new AdminTask(mainAdmin);

        adminProvider->addToList(new QTableView(mainAdmin), "tes");

        return;
    }
        QMessageBox::critical(mainRegistro, NO_LOG_ADMIN, NO_LOG_ADMIN, 1, 2);

}

