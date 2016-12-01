#include "admintask.h"

AdminTask::AdminTask()
{
    main = new QWidget();
    mainLayout = new QFormLayout();

    initLayout(mainLayout);
    main->setLayout(mainLayout);

    // connect
    connect(listWidget, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

void AdminTask::initLayout(QWidget *widget, QFormLayout *layout)
{
    listWidget = new QListWidget();
    stack = new QStackedWidget();

    layout->addRow(listWidget, stack);
    widget->setLayout(layout);
}

void AdminTask::addToList(QWidget *widget, QString title)
{
    stack->addWidget(widget);
    listWidget->addItem(title);
}

void AdminTask::initLayout(QFormLayout *layout)
{
    listWidget = new QListWidget();
    stack = new QStackedWidget();

    layout->addRow(listWidget, stack);

}
