#ifndef BUYABLESCROLLAREACART_H
#define BUYABLESCROLLAREACART_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Abstracts/BuyableScrollArea.h"

class BuyableScrollAreaCart : public BuyableScrollArea
{
private:
    void populateElements(QVBoxLayout *layout) override;

    void displayBuyable(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout);

public:
    BuyableScrollAreaCart(QScrollArea *scrollArea);
    BuyableScrollAreaCart();
};

#endif // BUYABLESCROLLAREACART_H
