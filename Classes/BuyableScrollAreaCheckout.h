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
public:
    void populate();

    BuyableScrollAreaCheckout(QScrollArea *scrollArea);
    BuyableScrollAreaCheckout();
};

#endif // BUYABLESCROLLAREACHECKOUT_H
