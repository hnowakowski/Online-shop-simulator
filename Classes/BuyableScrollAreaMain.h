#ifndef OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
#define OOP_PROJECT_BUYABLESCROLLAREAMAIN_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "../Interfaces/BuyableScrollArea.h"

class BuyableScrollAreaMain : public BuyableScrollArea
{
  public:
    void Populate();

    BuyableScrollAreaMain(QScrollArea* scrollArea);
    BuyableScrollAreaMain();
};

#endif // OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
