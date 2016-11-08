#include "guigabinete.h"


GUIGabinete::GUIGabinete()
{
    status =  START;

    db = new Database();

    // load file and validate status
    fileConfig = new ConfigFile();

    if(fileConfig->getStatusFile() < EXISTS ){
        //mainWidget = new QWidget();
        //QMessageBox::Critical("No se a configurado una base de datos aun");
        initCaptureDB(mainWidget);
    } else {

        // GUI
        window = new QMainWindow();
        mainLayout = new QGridLayout();

        initRegistroPersonal();
        mainLayout->addWidget(registroGroupLayout);
        mainWidget->setLayout(mainLayout);

        window->setCentralWidget(mainWidget);
        window->setWindowTitle(TITLE_APP);
        window->setMinimumWidth(MINIMUM_WIDTH);
        window->show();
    }
}

void GUIGabinete::initCaptureDB(QWidget *x)
{
    QLabel  *hostLabel,
            *portLabel,
            *userLabel,
            *passLabel,
            *dbLabel;

    QLineEdit *hostLine,
            *portLine,
            *userLine,
            *passLine,
            *dbLine;

    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *conectar =  new QPushButton(CONECTAR_CAPTUREDB);

    hostLabel = new QLabel(HOST_CAPTUREDB);
    portLabel = new QLabel(PORT_CAPTUREDB);
    userLabel = new QLabel(USER_CAPTUREDB);
    passLabel = new QLabel(PASS_CAPTUREDB);
    dbLabel = new QLabel(DB_CAPTUREDB);

    hostLine = new QLineEdit();
    portLine = new QLineEdit();
    userLine = new QLineEdit();
    passLine = new QLineEdit();
    passLine->setEchoMode(QLineEdit::Password);
    dbLine = new QLineEdit();

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

    captureDB = new QDialog(x);
    captureDB->setMinimumWidth(MINIMUM_WIDTH);
    captureDB->setLayout(layout);

    captureDB->setWindowTitle(TITLE_CAPTUREDB);
    //captureDB->set
    captureDB->show();
}

void GUIGabinete::initRegistroPersonal()
{
    //widget
    //registroWidget = new QWidget();

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
    // statusPersonalCombobox->addItem();

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

void GUIGabinete::clearRegistro()
{

}

void GUIGabinete::addPersonal()
{

}