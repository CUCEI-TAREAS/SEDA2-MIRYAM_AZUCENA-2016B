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
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QTabWidget>

#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QTableWidget>

#include "configfile.h"
#include "database.h"
#include "personal.h"
#include "list.h"
#include "list.cpp"
#include "admin.h"
#include "node.h"
#include "name.h"
#include "admintask.h"
#include "widgetregdb.h"

// app
#define TITLE_ADD_PERSONAL   "Agregar estudiante"
#define TITLE_LOGIN_ADMIN   "Administrador"

#define TITLE_APP       "Gabinete"
#define MINIMUM_WIDTH   600

// capture DB
#define CONFIGURE_DB    "No se ha configurado un Base de datos"
#define BODY_CONFIGURE_DB_CAPTUREDB "Configure la conexion al servidor"


#define DEFAULT_HOST "127.0.0.1"
#define DEFAULT_PORT "5432"
#define DEFAULT_USER "postgres"
#define DEFAULT_DB "gabinete"

#define STATE_DB_NO_CONECCTION -1
#define STATE_DB_NO_DB 0
#define STATE_DB_DONE 1

// no connection db
#define TITLE_FAIL_CAPTUREDB    "Conexion no establecida"
#define BODY_FAIL_CAPTUREDB     "No fue posible establecer la conexion al servidor"

// no permission to create db
#define TITLE_FAIL_PERMISSION   "Sin permisos para crear la base de datos"
#define BODY_FAIL_PERMISSION    "El usuario no cuenta con privilegios para crear la base de datos"

// db done
#define TITLE_DB_DONE       "Base de datos creada con exito"
#define TITLE_DB_MSG        "se configuro la base datos " + dbLine->text() + " con exito "

// registro
#define ADD_PERSONAL            "Agregado con exito"
#define NO_ADD_PERSONAL         "No agregado"
#define DUPLICATE_PERSONAL      "El usuario ya existe"
#define ERROR_ADD_PERSONAL      "Error al agregar el usuario "

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

// admin
#define NO_LOG_ADMIN "Error ; No logueado"

#define START           -1
#define SETUPDB         0 // capture
#define CONFIGFILE      1
#define READYFILE       2
#define SETUPGUI        4 // register
#define READY           5
#define SESSION         6 // schedules and mails

class GUIGabinete : QObject
{
    Q_OBJECT
private:

    // dynamic storage
    List<Carrera> *carreras = nullptr;
    List<Carrera> *roles = nullptr;
    List<Personal> *personal = nullptr;
    List<Admin> *admins = nullptr;

    // admin
    AdminTask *adminProvider = nullptr;

    // connection db
    ConfigFile *fileConfig = nullptr;

    // db
    Database *db = nullptr;

    // state
    short status;

    // interface
    QTabWidget *tabs = nullptr;
    QMainWindow *window = nullptr;

    QWidget *mainCentralWidget = nullptr, // all into there
    *mainRegistro = nullptr,
    *mainAdminLogin = nullptr,
    *mainAdmin = nullptr;


    // registro
    QFormLayout *adminLoginFormLayout = nullptr,
    //*adminMainFormLayout = nullptr,
    *registroMainLayout = nullptr,
    *mainCentralLayout = nullptr;

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

    WidgetRegDB* capturarDB = nullptr;

    // components of admin


    // replace from class
    //void initCaptureDB();
    void initPersonalRegistro(QWidget*, QFormLayout*);
    void initAdminLogin(QWidget*, QFormLayout*);
    void initAdminTask(QWidget*, QFormLayout*);



    bool allValidationsAddPersonal();
    bool validationPersonal(Personal*); // check only mandatory fields
    Personal* getGUICurrentPersonal();

    void loadAllToLinkedList();
    void loadAllToGuiAddPersonal();

    void loadGuiCarreras(QComboBox*, List<Carrera>*);
    void loadGuiTutores(QComboBox*, List<Admin> *);

    // SELECT ALL
    void loadListCarreas(List<Carrera>*);
    void loadListRoles(List<Carrera>*);
    void loadListPersonal(List<Personal>*);
    void loadListAdmins(List<Admin>*);

    // SELECT BY QUERY
    void loadListCarreas(List<Carrera>*, QString);
    void loadListRoles(List<Carrera>*, QString);
    void loadListPersonal(List<Personal>*, QString);
    void loadListAdmins(List<Admin>*, QString);

private slots:
    char connectDB();
    void clearRegistro();
    void deleteCaptureDB();
    void addPersonalRegistroWidget();
    bool insertPersonalToDB(Personal*);
    bool insertPersonalToDBFromGUI();

    void logAdmin();


signals:
    void fileConfigReady();

public:
    GUIGabinete();
    QString getIdCareerFromList(QString);
};

#endif // GUIGABINETE_H
