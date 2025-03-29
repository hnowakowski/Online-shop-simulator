#ifndef ITEMSCROLLAREACHECKOUT_H
#define ITEMSCROLLAREACHECKOUT_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Templates/ItemScrollArea.h"
#include "CartItem.h"

class ItemScrollAreaCheckout : public ItemScrollArea<CartItem>
{
private:
    void populateItems() override;

    void generatePanel(std::shared_ptr<CartItem> &item) override;

public:
    void displayItems() override;

    ItemScrollAreaCheckout(QScrollArea *scrollArea);
    ItemScrollAreaCheckout();
};

#endif // ITEMSCROLLAREACHECKOUT_H
