#ifndef GUIGABINETE_H
#define GUIGABINETE_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QLabel>

#define TITLE_APP       "Gabinete"
#define MINIMUM_WIDTH   300

enum {
    SETUP,
    READY
};

class GUIGabinete : QObject
{
    Q_OBJECT
private:

    // state
    short status;

    // interface
    QMainWindow *window = nullptr;
    QWidget *mainWidget = nullptr; // all into there
    QLayout *mainLayout = nullptr;

    // registro
    QWidget *registroWidget = nullptr;

    // components of registro
    QLabel
    nombre,
    codigo,
    email,
    telefono,
    expediente,
    statusPersonal,
    semestre,
    creditosCursados,
    permisos, // is necesary ?
    carrera, // combox
    tutor;  // combox

    void initRegistro(void);

public:
    GUIGabinete();

};

#endif // GUIGABINETE_H
