#ifndef ADMINTASK_H
#define ADMINTASK_H

#include <QWidget>
#include <QObject>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QString>
#include <QFormLayout>

class AdminTask : QObject
{
    Q_OBJECT

private:

    QWidget *main = nullptr;
    QListWidget *listWidget = nullptr;
    QStackedWidget *stack = nullptr;
    QFormLayout* mainLayout = nullptr;


    void initLayout(QFormLayout *);
public:

    explicit AdminTask();
    void initLayout(QWidget*, QFormLayout *);

    void addToList(QWidget*, QString);

signals:

public slots:
};

#endif // ADMINTASK_H
