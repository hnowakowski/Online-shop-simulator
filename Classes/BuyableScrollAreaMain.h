#ifndef OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
#define OOP_PROJECT_BUYABLESCROLLAREAMAIN_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Abstracts/Buyable.h"
#include "../Abstracts/BuyableScrollArea.h"

class BuyableScrollAreaMain : public BuyableScrollArea
{
public:
    void populate();

    void updateBuyables();

    void displayBuyable(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout);

    BuyableScrollAreaMain(QScrollArea *scrollArea);
    BuyableScrollAreaMain();
};

#endif // OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
