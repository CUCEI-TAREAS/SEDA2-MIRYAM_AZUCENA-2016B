#include "guigabinete.h"


GUIGabinete::GUIGabinete()
{
    status =  CONFIGFILE;

    // load file
    fileConfig = new ConfigFile();

    // GUI
    window = new QMainWindow();
    mainWidget = new QWidget();
    mainLayout = new QGridLayout();

    initRegistro();
    mainLayout->addWidget(registroGroupLayout);
    mainWidget->setLayout(mainLayout);

    window->setCentralWidget(mainWidget);
    window->setWindowTitle(TITLE_APP);
    window->setMinimumWidth(MINIMUM_WIDTH);
    window->show();
}

void GUIGabinete::initRegistro()
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
