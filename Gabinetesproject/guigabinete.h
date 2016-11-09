#ifndef GUIGABINETE_H
#define GUIGABINETE_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QObject>
#include <QLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>

#include "configfile.h"
#include "database.h"

// app
#define TEXT_ADD_PERSONAL   "Agregar estudiante"

#define TITLE_APP       "Gabinete"
#define MINIMUM_WIDTH   600

// capture DB
#define TITLE_CAPTUREDB "Configuracion de la Base de datos PostgreSQL"
#define HOST_CAPTUREDB  "Host"
#define PORT_CAPTUREDB  "Puerto"
#define USER_CAPTUREDB  "Usuario"
#define PASS_CAPTUREDB  "Contraseña"
#define DB_CAPTUREDB    "Nombre de la base de datos para "TITLE_APP" Software"
#define CONECTAR_CAPTUREDB "Conectar"

#define DEFAULT_HOST "127.0.0.1"
#define DEFAULT_PORT "5432"
#define DEFAULT_USER "postgres"
#define DEFAULT_DB TITLE_APP

#define STATE_DB_NO_CONECCTION -1
#define STATE_DB_NO_DB 0
#define STATE_DB_DONE 1

#define TITLE_FAIL_CAPTUREDB    "Conexion no establecida"
#define BODY_FAIL_CAPTUREDB     "No fue posible establecer la conexion al servidor"
// registro
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


#define START           0
#define SETUPDB         3
#define READYFILE       1
#define CONFIGFILE      2
#define SETUPGUI        4
#define READY           5
#define SESSION         6

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

    //capture db

    QDialog *captureDB = nullptr;

    QLineEdit *hostLine = nullptr,
            *portLine = nullptr,
            *userLine = nullptr,
            *passLine = nullptr,
            *dbLine = nullptr;

    void initCaptureDB(QWidget*);
    void initRegistroPersonal(void);
    void clearRegistro();


private slots:
    char conectDB();
    void addPersonal();

public:
    GUIGabinete();

};

#endif // GUIGABINETE_H
