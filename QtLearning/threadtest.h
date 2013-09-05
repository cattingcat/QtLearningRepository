#ifndef THREADTEST_H
#define THREADTEST_H
#include <QThread>
#include <QDebug>
#include <QTimer>

class ThreadTest: public QThread{
    Q_OBJECT
private:
    int _now;
    int _max;

public:
    ThreadTest(int max = 50):QThread(), _now(0),_max(max) {

    }
protected:
    virtual void run(){
        QTimer timer;
        connect(&timer, SIGNAL(timeout()), SLOT(slot()));
        timer.start(1000);
        qDebug()<<"run";
        exec();
    }

protected slots:
    void slot(){
        emit next(_now++);
        if(_now == _max){
            emit finished();
            this->exit();
        }
    }

signals:
    void next(int);
    void finished();

};

#endif // THREADTEST_H
