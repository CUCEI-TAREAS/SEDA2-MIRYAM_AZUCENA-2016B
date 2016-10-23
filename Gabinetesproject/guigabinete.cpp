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

}
