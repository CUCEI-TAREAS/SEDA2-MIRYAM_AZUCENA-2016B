#ifndef GUIGABINETE_H
#define GUIGABINETE_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QGroupBox>

#define NAME_PERSONAL           "Nombre del estudiante"
#define LAST_NAME_PERSONAL      "Apeido del estudiante"
#define CODE_PERSONAL           "Codigo del estudiante"
#define EMAIL_PERSONAL          "Email del estudiante"
#define PHONE_PERSONAL          "Telefono del estudiante"
#define EXP_PERSONAL            "Expediente del estudiante"
#define STATE_PERSONAL          "Status del estudiante"
#define SEMESTRE_PERSONAL       "Semestre del estudiante"
#define CURRENT_PERSONAL        "Creditos cursados del estudiante"
#define PERMISOS_PERSONAL       "Permisos del estudiante"
#define CARRERA_PERSONAL        "Carrera del estudiante"
#define TUTOR_ESTUDIANTE        "Tutor del estudiante"

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
    QGroupBox *registroLayout = nullptr;

    // components of registro
    QLabel
    *nombre,
    *apeido,
    *codigo,
    *email,
    *telefono,
    *expediente,
    *statusPersonal,
    *semestre,
    *creditosCursados,
    *permisos, // is necesary ?
    *carrera, // combox
    *tutor;  // combox

    void initRegistro(void);

public:
    GUIGabinete();

};

#endif // GUIGABINETE_H
