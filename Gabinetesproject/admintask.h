#ifndef ADMINTASK_H
#define ADMINTASK_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QTabWidget>
#include <QFormLayout>

class AdminTask : public QWidget
{
    Q_OBJECT

private:
    QTabWidget* verticalTabs = nullptr;

    QFormLayout* mainLayout = nullptr;

    QLabel *text = nullptr;

public:

    explicit AdminTask(QWidget *parent = 0);

    void initLayout(QFormLayout*);
    void addTabs(QWidget*, QString);


    QTabWidget *getVerticalTabs() const;
    void setVerticalTabs(QTabWidget *value);

signals:

public slots:
};

#endif // ADMINTASK_H
