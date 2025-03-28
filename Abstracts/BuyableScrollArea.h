#ifndef OOP_PROJECT_BUYABLESCROLLAREA_H
#define OOP_PROJECT_BUYABLESCROLLAREA_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

class BuyableScrollArea
{
protected:
    QScrollArea *scrollArea;

public:
    virtual void populate() = 0;

    BuyableScrollArea(QScrollArea *scrollArea);
    BuyableScrollArea();

    virtual ~BuyableScrollArea() = default;
};

#endif // OOP_PROJECT_BUYABLESCROLLAREA_H
