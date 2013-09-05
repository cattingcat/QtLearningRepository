#ifndef MODELVIEWTEST_H
#define MODELVIEWTEST_H
#include <QWidget>
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QAbstractItemModel>
#include <QHBoxLayout>
#include <QStringListModel>
#include <QStandardItemModel>


class ModelViewTest: public QWidget
{
    Q_OBJECT
private:
    QAbstractItemModel* _model;
    QItemSelectionModel* _selectionModel;

    QListView* _listv;
    QTableView* _tablev;
    QTreeView* _treev;

public:
    ModelViewTest(){
        QHBoxLayout* layout = new QHBoxLayout;


        _model = new QStandardItemModel(5, 3);
        for(int ir = 0; ir < _model->rowCount(); ++ir){
            QModelIndex index = _model->index(ir, 0);
            _model->setData(index, "str " + QString::number(ir));

            _model->setData(_model->index(ir, 1), "lalue");

            _model->insertColumns(0, 3, index);
            _model->insertRows(0, 3, index);
            for(int ic = 0; ic < 3; ++ic){
                for(int ir = 0; ir < 3; ++ir){
                    QModelIndex tindex = _model->index(ir, ic, index);
                    _model->setData(tindex, QString("%1, %2").arg(ic).arg(ir));
                    _model->setData(tindex, "tool tip", Qt::ToolTipRole);

                }
            }
        }



        _selectionModel = new QItemSelectionModel(_model);


        _listv = new QListView;
        _tablev = new QTableView;
        _treev = new QTreeView;


        _listv->setModel(_model);
        _treev->setModel(_model);
        _tablev->setModel(_model);

        _listv->setSelectionModel(_selectionModel);
        _treev->setSelectionModel(_selectionModel);
        _tablev->setSelectionModel(_selectionModel);


        layout->addWidget(_listv);
        layout->addWidget(_tablev);
        layout->addWidget(_treev);



        setLayout(layout);
    }

signals:

public slots:


};

#endif // MODELVIEWTEST_H
