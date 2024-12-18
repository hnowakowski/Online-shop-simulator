#ifndef OOP_PROJECT_BUYABLESCROLLAREA_H
#define OOP_PROJECT_BUYABLESCROLLAREA_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "Interfaces/DynamicWidget.h"

class BuyableScrollArea : public DynamicWidget{
protected:
    QScrollArea *scrollArea;

public:
    virtual void Populate() = 0;

    BuyableScrollArea(QScrollArea *scrollArea);
    BuyableScrollArea();
};

#endif // OOP_PROJECT_BUYABLESCROLLAREA_H
