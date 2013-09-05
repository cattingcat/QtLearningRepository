#ifndef TESTTABWIDGET_H
#define TESTTABWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMenu>
#include <QMenuBar>
#include <QSystemTrayIcon>
//#include "progress.h"
//#include "progress2.h"
//#include "modelviewtest.h"
//#include "filterproxymodeltest.h"
//#include "palettetest.h"
//#include "eventtest.h"
//#include "opengltest.h"
#include "opengl3dtest.h"
#include "settingstest.h"
#include "menutest.h"
#include "scripttest.h"


class MainWidget: public QWidget
{
    Q_OBJECT
private:
    QTabWidget* _tw;
    QMenuBar* _menu;
    QSystemTrayIcon* _trayIcon;

public:
    MainWidget(): QWidget()
    {
        QVBoxLayout* layout = new QVBoxLayout;
        _menu = new QMenuBar;
        _tw = new QTabWidget;
        _trayIcon = new QSystemTrayIcon;
        _menu->addAction("hide", this, SLOT(hideTray()));


        QMenu* iconMenu = new QMenu(this);
        iconMenu->addAction("open", this, SLOT(showTray()));
        _trayIcon->setContextMenu(iconMenu);
        _trayIcon->setToolTip("tool tip");
        _trayIcon->setIcon(QIcon(":/res/img/00.png"));


#if defined(PROGRESS_H)
        _tw->addTab(new Progress , QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\2.jpg"), "progres1");
#endif
#if defined(PROGRESS2_H)
        _tw->addTab(new Progress2, QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\3.jpg"), "progres2");
#endif
#if defined(MODELVIEWTEST_H)
        _tw->addTab(new ModelViewTest, QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\3.jpg"), "ModelView test");
#endif
#if defined(FILTERPROXYMODELTEST_H)
        _tw->addTab(new FilterProxyModelTest, QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\3.jpg"), "Proxy test");
#endif
#if defined(PALETTETEST_H)
        _tw->addTab(new PaletteTest, QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\3.jpg"), "Palette test");
#endif
#if defined(EVENTTEST_H)
        _tw->addTab(new EventTest, QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\3.jpg"), "Event test");
#endif
#if defined(OPENGLTEST_H)
         _tw->addTab(new OpenGLTest, QIcon("C:\\Users\\pc-1\\Desktop\\projects\\untitled_Qt\\img\\3.jpg"), "OpenGL test");
#endif
#if defined(OPENGL3DTEST_H)
         _tw->addTab(new OpenGL3DTest, QIcon(":/res/img/00.png"), "OpenGL 3D test");
#endif
#if defined(SETTINGSTEST_H)
         _tw->addTab(new SettingsTest, QIcon(":/res/img/00.png"), "Settings test");
#endif
#if defined(MENUTEST_H)
         _tw->addTab(new MenuTest, QIcon(":/res/img/00.png"), "menu test");
#endif
#if defined(SCRIPTTEST_H)
         _tw->addTab(new ScriptTest, QIcon(":/res/img/00.png"), "script test");
#endif

        layout->addWidget(_menu);
        layout->addWidget(_tw);
        resize(700, 700);
        setLayout(layout);
    }
private slots:
    void hideTray(){
        this->hide();
        _trayIcon->show();

    }
    void showTray(){
        this->show();
        _trayIcon->hide();
    }

};

#endif // TESTTABWIDGET_H
