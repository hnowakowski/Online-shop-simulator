#ifndef BUYABLESCROLLAREACHECKOUT_H
#define BUYABLESCROLLAREACHECKOUT_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Abstracts/BuyableScrollArea.h"

class BuyableScrollAreaCheckout : public BuyableScrollArea
{
private:
    void populateElements(QVBoxLayout *layout) override;

    void displayBuyable(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout);

public:
    BuyableScrollAreaCheckout(QScrollArea *scrollArea);
    BuyableScrollAreaCheckout();
};

#endif // BUYABLESCROLLAREACHECKOUT_H
