#ifndef SCRIPTTEST_H
#define SCRIPTTEST_H
#include <QtWidgets>
#include <QtScript>

class ScriptTest: public QWidget{
    Q_OBJECT
    Q_PROPERTY(bool boolProp WRITE setBoolProp READ getBoolProp)

private:
    QScriptEngine* _engine;
    QLabel* _lbl;
    QPushButton* _btn;

public:
    ScriptTest(): QWidget(){
        QVBoxLayout* layout = new QVBoxLayout;

        _engine = new QScriptEngine;
        _lbl = new QLabel;
        _btn = new QPushButton;

        layout->addWidget(_lbl);
        layout->addWidget(_btn);

        QScriptValue sv = _engine->newQObject(this);
        _engine->globalObject().setProperty("form", sv);

        connect(_btn, SIGNAL(clicked()), SLOT(btnSlot()));

        setLayout(layout);
    }

public slots:
    void setBoolProp(bool){
        _lbl->setText("script evalueted");

    }

    bool getBoolProp(){
        return true;
    }

    void btnSlot(){
        //_engine->evaluate("form.boolProp = true");
        QFile file("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\script.js");
        file.open(QFile::ReadOnly);
        QTextStream ts(&file);
        _engine->evaluate(ts.readAll());

    }

};

#endif // SCRIPTTEST_H
