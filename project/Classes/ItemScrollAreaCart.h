#ifndef ITEMSCROLLAREACART_H
#define ITEMSCROLLAREACART_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Templates/ItemScrollArea.h"
#include "CartItem.h"

class ItemScrollAreaCart : public ItemScrollArea<CartItem>
{
private:
    void populateItems() override;

    void generatePanel(std::shared_ptr<CartItem> &item) override;

    void clearArea() override;

    bool panelExists(const std::shared_ptr<CartItem> &item) const;

public:
    void displayItems() override;

    ItemScrollAreaCart(QScrollArea *scrollArea);
    ItemScrollAreaCart();
};

#endif // ITEMSCROLLAREACART_H
