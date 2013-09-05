#ifndef PROGRESS_H
#define PROGRESS_H
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QPalette>
#include <QAbstractSlider>
#include <QSlider>
#include <QDial>
#include <QLineEdit>
#include <iostream>
#include <QDateTimeEdit>
#include <QListWidget>

class Progress: public QWidget
{
    Q_OBJECT
protected:
    int max;
    QVBoxLayout* _baseLayout;

    QProgressBar* pb;
    QPushButton* btn;
    QLCDNumber* n;
    QCheckBox* cb;

    QRadioButton *rb1, *rb2, *rb3;
    QGroupBox* gb;

    QAbstractSlider* sl;
    QLineEdit* le;

    QListWidget* lw;


public:
    Progress(){
        max = 500;
        setWindowTitle("Test");
        _baseLayout = new QVBoxLayout;

        n = new QLCDNumber;
        n->setDigitCount(30);
        n->setSegmentStyle(QLCDNumber::Flat);
        n->setMode(QLCDNumber::Hex);


        pb = new QProgressBar;
        pb->setMaximum(max);

        btn = new QPushButton("Next");
        btn->setCheckable(true);

        cb = new QCheckBox("Check box");
        cb->setTristate();
        cb->setCheckState(Qt::PartiallyChecked);

        rb1 = new QRadioButton("x1");
        rb1->setChecked(true);
        rb2 = new QRadioButton("x2");
        rb3 = new QRadioButton("x3");

        QHBoxLayout* rl = new QHBoxLayout;
        rl->addWidget(rb1);
        rl->addWidget(rb2);
        rl->addWidget(rb3);
        gb = new QGroupBox("X");
        gb->setLayout(rl);
        gb->setTitle("title");
        gb->setCheckable(true);


        QHBoxLayout* tl = new QHBoxLayout;
        sl = new QDial;
        sl->setOrientation(Qt::Horizontal);
        sl->setRange(0, max);
        sl->setSingleStep(1);
        le = new QLineEdit("line edit");
        le->setEchoMode(QLineEdit::Password);
        tl->addWidget(sl);
        tl->addWidget(le);

        lw = new QListWidget;
        lw->addItem("1 item");
        lw->addItem("2 item");
        lw->addItem("3 item");



        _baseLayout->addWidget(btn);
        _baseLayout->addWidget(pb);
        _baseLayout->addWidget(n);
        _baseLayout->addWidget(cb);
        _baseLayout->addWidget(gb);
        _baseLayout->addLayout(tl);
        _baseLayout->addWidget(new QDateTimeEdit);
        _baseLayout->addWidget(lw);

        setLayout(_baseLayout);

        connect(btn, SIGNAL(clicked()), SLOT(nextIteration()));
        QObject::connect(sl, SIGNAL(valueChanged(int)), pb, SLOT(setValue(int)));
        QObject::connect(sl, SIGNAL(valueChanged(int)), n, SLOT(display(int)));
        QObject::connect(lw, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemChanged(QListWidgetItem*)));

    }

private slots:
    void nextIteration(){
        int x = 0;

        if(rb1->isChecked()){
            x = 1;
        }
        else if (rb2->isChecked()){
            x = 2;
        }
        else if (rb3->isChecked()){
            x = 3;
        }

        pb->setValue(pb->value() + x);
        n->display(pb->value());
    }
    void itemChanged(QListWidgetItem* item){
        std::cout<<"changed "<<item->text().toStdString()<<std::endl;
    }

signals:


};

#endif // PROGRESS_H
