#ifndef WDIGETREGDB_H
#define WDIGETREGDB_H

#include <QWidget>
#include <guigabinete.h>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPushButton;
class QVBoxLayout;
QT_END_NAMESPACE

#define TITLE_CAPTUREDB "Configuracion de la Base de datos PostgreSQL"
#define HOST_CAPTUREDB  "Host"
#define PORT_CAPTUREDB  "Puerto"
#define USER_CAPTUREDB  "Usuario"
#define PASS_CAPTUREDB  "Contraseña"
#define DB_CAPTUREDB    "Nombre de la base de datos para " TITLE_APP " Software"
#define CONECTAR_CAPTUREDB "Conectar"

class WidgetRegDB : public QWidget
{
    Q_OBJECT
public:
    WidgetRegDB();

private:

    //QWidget *captureDB = nullptr; // instead itself
    QLineEdit *hostLine = nullptr,
    *portLine = nullptr,
    *userLine = nullptr,
    *passLine = nullptr,
    *dbLine = nullptr;

    QLabel  *hostLabel = nullptr,
    *portLabel = nullptr,
    *userLabel = nullptr,
    *passLabel = nullptr,
    *dbLabel = nullptr;

    QVBoxLayout *layout = nullptr;
    QPushButton *conectar = nullptr;

};

#endif // WDIGETREGDB_H
