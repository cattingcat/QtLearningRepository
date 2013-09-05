#ifndef PROGRESS2_H
#define PROGRESS2_H
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <iostream>
#include <QPushButton>
#include <QTreeWidget>
#include <QTableWidget>
#include <QStringListModel>

class Progress2: public QWidget
{
    Q_OBJECT
private:
    QListView* _lw;
    QTreeWidget* _tw;
    QTableWidget* _tblw;


public:
    Progress2(){
        QVBoxLayout* layout = new QVBoxLayout;

        _lw = new QListView;
        QStringListModel* model = new QStringListModel(QStringList()<<"qwe"<<"asd"<<"zxc");
        _lw->setModel(model);



        _tw = new QTreeWidget;
        QStringList sl;
        sl.append("item1");
        sl << "item2"<<"item3";
        _tw->setHeaderLabels(sl);
        _tw->addTopLevelItem(new QTreeWidgetItem(sl));



        _tblw = new QTableWidget(100, 100);
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText("text");
        item->setIcon(QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\1.jpg"));
        _tblw->setItem(0, 0, item);










        //QObject::connect(_lw, SIGNAL(itemSelectionChanged()), this, SLOT(listWgtSlot()));


        layout->addWidget(_lw);
        layout->addWidget(_tw);
        layout->addWidget(_tblw);
        setLayout(layout);
    }

private slots:
    void listWgtSlot(){

    }

signals:


};

#endif // PROGRESS2_H
