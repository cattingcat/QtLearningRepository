#ifndef EVENTTEST_H
#define EVENTTEST_H
#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCoreApplication>
#include <QPainter>

class EventTest: public QWidget
{
    Q_OBJECT
private:
    QLabel* _coords;
    QPushButton* _btn;
    QLineEdit* _line;
    QPainter* _painter;


protected:
    virtual void mousePressEvent(QMouseEvent *e){
        QWidget::mousePressEvent(e);
    }
    virtual void mouseMoveEvent(QMouseEvent *e){
        _coords->setText(QString("Mouse position: x = %1, y = %2").arg(e->pos().x()).arg(e->pos().y()));

    }

public:
    EventTest(): QWidget(){
        QVBoxLayout* layout = new QVBoxLayout;

        _coords = new QLabel;
        _btn = new QPushButton("btn");
        _line = new QLineEdit;
        _painter = new QPainter;

        QObject::connect(_btn, SIGNAL(clicked()), this, SLOT(btnPressed()));

        layout->addWidget(_coords);
        layout->addWidget(_btn);
        layout->addWidget(_line);

        setLayout(layout);
    }

protected slots:
    void btnPressed(){
        QCoreApplication::postEvent(_line, new QKeyEvent(QKeyEvent::KeyPress, 1, Qt::NoModifier, "1"));

        _painter->begin(_line);
        _painter->drawArc(0, 0, 200, 200, 1, 1);
        _painter->end();
    }

};

#endif // EVENTTEST_H
