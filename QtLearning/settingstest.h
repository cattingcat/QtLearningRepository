#ifndef SETTINGSTEST_H
#define SETTINGSTEST_H
#include <QWidget>
#include <QSettings>
#include <iostream>
#include <QMouseEvent>

class SettingsTest: public QWidget
{
    Q_OBJECT
private:
    QSettings* _settings;

public:
    SettingsTest(){
        _settings = new QSettings("orgname", "app");
        int v = _settings->value("key").value<int>();
        _settings->setValue("key", ++v);

    }

protected:
    virtual void mousePressEvent(QMouseEvent *){
        int v = _settings->value("key").value<int>();
        std::cout<<"val= "<<v<<std::endl;
    }
};

#endif // SETTINGSTEST_H
