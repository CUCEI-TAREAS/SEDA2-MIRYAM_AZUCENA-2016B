#ifndef GUIGABINETE_H
#define GUIGABINETE_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>

#include "configfile.h"
#include "database.h"

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

#define MIN_RANGE_SEMESTRE 1
#define MAX_RANGE_SEMESTRE 22

#define TEXT_ADD_PERSONAL   "Agregar estudiante"

#define TITLE_APP       "Gabinete"
#define MINIMUM_WIDTH   600

enum {
    CONFIGFILE,
    SETUPDB,
    SETUPGUI,
    READY,
    SESSION
};

class GUIGabinete : QObject
{
    Q_OBJECT
private:

    // connection db
    ConfigFile *fileConfig = nullptr;

    // db
    Database *db = nullptr;

    // state
    short status;

    // interface
    QMainWindow *window = nullptr;
    QLayout *mainLayout = nullptr;
    QWidget *mainWidget = nullptr; // all into there

    QGroupBox *registroGroupLayout = nullptr;

    // registro
    QGridLayout *registroGridLayout = nullptr;

    // components of registro
    QLabel
    *nombreLabel = nullptr,
    *apeidoLabel = nullptr,
    *codigoLabel = nullptr,
    *emailLabel = nullptr,
    *telefonoLabel= nullptr,
    *expedienteLabel = nullptr,
    *statusPersonalLabel = nullptr,
    *semestreLabel = nullptr,
    *creditosCursadosLabel= nullptr,
    *carreraLabel = nullptr, // combox
    *tutorLabel = nullptr;  // combox

    QLineEdit
    *nombreLine = nullptr,
    *apeidoLine = nullptr,
    *codigoLine = nullptr,
    *emailLine = nullptr,
    *telefonoLine = nullptr,
    *expedienteLine = nullptr,
    *creditosCursadosLine = nullptr;

    QPushButton *addPersonalButton = nullptr;
    QSpinBox *semestreSpin = nullptr;

    QComboBox *carreraCombobox = nullptr,
    *tutorCombobox = nullptr,
    *statusPersonalCombobox = nullptr;


    void initRegistro(void);
    void clearRegistro();

private slots:
    void addPersonal();

public:
    GUIGabinete();

};

#endif // GUIGABINETE_H
