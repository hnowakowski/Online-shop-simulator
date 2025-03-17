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
private:
    void populateElements(QVBoxLayout *layout) override;

    void displayBuyable(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout);

public:
    void updateElements() override;

    BuyableScrollAreaMain(QScrollArea *scrollArea);
    BuyableScrollAreaMain();
};

#endif // OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
