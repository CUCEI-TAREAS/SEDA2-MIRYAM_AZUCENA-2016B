#include "admintask.h"

AdminTask::AdminTask(QWidget *parent)
{
    main = new QWidget(parent);
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

QWidget *AdminTask::getMain() const
{
    return main;
}

void AdminTask::setMain(QWidget *value)
{
    main = value;
}

void AdminTask::initLayout(QFormLayout *layout)
{
    listWidget = new QListWidget();
    stack = new QStackedWidget();

    layout->addRow(listWidget, stack);

}
