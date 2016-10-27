#include <QApplication>

#include "guigabinete.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        GUIGabinete app;


    return a.exec();
}

/* if config.txt doesnt exist
 * captureDatabase and create config.txt
 *
 * if connection is failed
 * show message /
 *
