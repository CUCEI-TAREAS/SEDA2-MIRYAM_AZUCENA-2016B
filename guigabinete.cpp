#include "guigabinete.h"


GUIGabinete::GUIGabinete()
{
    status =  SETUP;
    window = new QMainWindow();
    mainWidget = new QWidget();
    mainLayout = new QGridLayout();

    window->setLayout(mainLayout);

    window->setWindowTitle(TITLE_APP);
    window->setMinimumWidth(MINIMUM_WIDTH);
    window->show();
}

void GUIGabinete::initRegistro()
{
    //widget
    registroWidget = new QWidget();

    //layout
    registroLayout = new QGroupBox();

    // labels
    nombre = new QLabel(NAME_PERSONAL);
    apeido = new QLabel(LAST_NAME_PERSONAL);
    codigo = new QLabel(CODE_PERSONAL);
    email = new QLabel(EMAIL_PERSONAL);
    telefono = new QLabel(PHONE_PERSONAL);
    expediente = new QLabel(EXP_PERSONAL);
    statusPersonal = new QLabel (STATE_PERSONAL);
    semestre =  new QLabel (SEMESTRE_PERSONAL);
    creditosCursados = new QLabel(CURRENT_PERSONAL);
    permisos = new QLabel (PERMISOS_PERSONAL); // is necesary ?
    carrera = new QLabel (CARRERA_PERSONAL); // combox
    tutor = new QLabel (TUTOR_ESTUDIANTE);  // combox

    registroWidget->

}
