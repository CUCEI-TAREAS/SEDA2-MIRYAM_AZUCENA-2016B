#include "widgetregdb.h"

WidgetRegDB::WidgetRegDB()
{
    layout = new QVBoxLayout();
    conectar =  new QPushButton(CONECTAR_CAPTUREDB);

    hostLabel = new QLabel(HOST_CAPTUREDB);
    portLabel = new QLabel(PORT_CAPTUREDB);
    userLabel = new QLabel(USER_CAPTUREDB);
    passLabel = new QLabel(PASS_CAPTUREDB);
    dbLabel = new QLabel(DB_CAPTUREDB);

    hostLine = new QLineEdit(DEFAULT_HOST);
    portLine = new QLineEdit(DEFAULT_PORT);
    userLine = new QLineEdit(DEFAULT_USER);
    passLine = new QLineEdit();
    passLine->setEchoMode(QLineEdit::Password);
    dbLine = new QLineEdit(DEFAULT_DB);

    layout->addWidget(hostLabel, 1);
    layout->addWidget(hostLine, 2);

    layout->addWidget(portLabel, 3);
    layout->addWidget(portLine, 4);

    layout->addWidget(userLabel, 5);
    layout->addWidget(userLine, 6);

    layout->addWidget(passLabel, 7);
    layout->addWidget(passLine, 8);

    layout->addWidget(dbLabel, 9);
    layout->addWidget(dbLine, 10);

    layout->addWidget(conectar, 11);

    setMinimumWidth(MINIMUM_WIDTH);
    setLayout(layout);
    setWindowTitle(TITLE_CAPTUREDB);

    connect(conectar, SIGNAL(clicked(bool)), GUIGabinete, SLOT(connectDB()));
    connect(GUIGabinete, SIGNAL(fileConfigReady()), GUIGabinete, SLOT(deleteCaptureDB()));

    show();
}
