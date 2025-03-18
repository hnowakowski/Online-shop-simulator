#ifndef OOP_PROJECT_BUYABLESCROLLAREA_H
#define OOP_PROJECT_BUYABLESCROLLAREA_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include "Buyable.h"

class BuyableScrollArea
{
protected:
    QScrollArea *scrollArea;

    std::shared_ptr<std::unordered_map<std::string, QWidget *>> buyablePanel;

    virtual void populateBuyables(QVBoxLayout *layout) = 0;

    virtual void generateLayout(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout) = 0;

    void clearArea();

public:
    virtual void displayBuyables() = 0;

    void populate();

    BuyableScrollArea(QScrollArea *scrollArea);
    BuyableScrollArea();

    virtual ~BuyableScrollArea() = default;
};

#endif // OOP_PROJECT_BUYABLESCROLLAREA_H
