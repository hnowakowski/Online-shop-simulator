#ifndef BUYABLESCROLLAREACHECKOUT_H
#define BUYABLESCROLLAREACHECKOUT_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Interfaces/BuyableScrollArea.h"

class BuyableScrollAreaCheckout : public BuyableScrollArea
{
  public:
    void Populate();

    BuyableScrollAreaCheckout(QScrollArea* scrollArea);
    BuyableScrollAreaCheckout();
};


#endif // BUYABLESCROLLAREACHECKOUT_H
