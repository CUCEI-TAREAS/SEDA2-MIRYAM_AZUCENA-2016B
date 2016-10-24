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
    nombre = new QLabel(NAME_PERSONAL);
    apeido = new QLabel(LAST_NAME_PERSONAL);
    codigo = new QLabel(CODE_PERSONAL);
    email = new QLabel (EMAIL_PERSONAL);
    telefono,
    expediente,
    statusPersonal,
    semestre,
    creditosCursados,
    permisos, // is necesary ?
    carrera, // combox
    tutor;  // combox
}
