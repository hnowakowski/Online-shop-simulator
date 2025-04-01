#ifndef OOP_PROJECT_ITEMSCROLLAREAMAIN_H
#define OOP_PROJECT_ITEMSCROLLAREAMAIN_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Abstracts/Buyable.h"
#include "../Templates/ItemScrollArea.h"

class ItemScrollAreaMain : public ItemScrollArea<Buyable>
{
private:
    void populateItems() override;

    void generatePanel(std::shared_ptr<Buyable> &item) override;

public:
    void displayItems() override;

    ItemScrollAreaMain(QScrollArea *scrollArea);
    ItemScrollAreaMain();
};

#endif // OOP_PROJECT_ITEMSCROLLAREAMAIN_H
