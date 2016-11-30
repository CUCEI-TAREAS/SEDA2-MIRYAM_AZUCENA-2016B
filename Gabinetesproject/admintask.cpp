#include "admintask.h"

AdminTask::AdminTask(QWidget *parent) : QWidget(parent)
{
    initLayout(mainLayout);
    setLayout(mainLayout);
}

QTabWidget *AdminTask::getVerticalTabs() const
{
    return verticalTabs;
}

void AdminTask::setVerticalTabs(QTabWidget *value)
{
    verticalTabs = value;
}


void AdminTask::initLayout(QFormLayout *layout)
{
    layout = new QFormLayout();

    text = new QLabel("text");
    layout->addRow(text);

}

void AdminTask::addTabs(QWidget *, QString)
{

}
