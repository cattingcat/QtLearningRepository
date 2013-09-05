#ifndef MENUTEST_H
#define MENUTEST_H
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <iostream>
#include <QContextMenuEvent>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>

class MenuTest: public QWidget
{
    Q_OBJECT
private:
    QMenu* menu;

public:
    MenuTest(){
        QVBoxLayout* layout = new QVBoxLayout;

        QMenuBar* bar = new QMenuBar;
        menu = new QMenu;
        menu->setTitle("title");
        menu->addAction("connected with slot", this, SLOT(mySlot()));
        menu->addSeparator();
        menu->addAction("act 2");
        menu->setTearOffEnabled(true);
        bar->addMenu(menu);
        //bar->show();
        layout->addWidget(bar);
        layout->addWidget(new QPushButton("qwe"));
        setLayout(layout);

    }
protected:
    virtual void contextMenuEvent(QContextMenuEvent *e){
        menu->exec(e->globalPos());

    }

protected slots:
    void mySlot(){
        std::cout<<"slot called"<<std::endl;
        QFileDialog(this).exec();

    }


};

#endif // MENUTEST_H
