#ifndef PALETTETEST_H
#define PALETTETEST_H
#include <progress.h>
#include <QPalette>
#include <QColor>

class PaletteTest: public Progress
{
    Q_OBJECT
public:
    PaletteTest(): Progress(){
        QPalette pal = palette();
        pal.setColor(QPalette::Button, Qt::red);
        pal.setColor(QPalette::Base, Qt::red);
        pal.setColor(QPalette::Light, Qt::green);
        setPalette(pal);
    }
};

#endif // PALETTETEST_H
