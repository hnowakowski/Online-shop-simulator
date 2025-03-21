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
public:
    void populate();

    BuyableScrollAreaCart(QScrollArea *scrollArea);
    BuyableScrollAreaCart();
};

#endif // BUYABLESCROLLAREACART_H
