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
    void populateBuyables(QVBoxLayout *layout) override;

    void generatePanel(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout) override;

public:
    void displayBuyables() override;

    BuyableScrollAreaCart(QScrollArea *scrollArea);
    BuyableScrollAreaCart();
};

#endif // BUYABLESCROLLAREACART_H
