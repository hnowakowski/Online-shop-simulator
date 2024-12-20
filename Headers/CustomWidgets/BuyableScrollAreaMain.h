#ifndef OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
#define OOP_PROJECT_BUYABLESCROLLAREAMAIN_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "../../Interfaces/BuyableScrollArea.h"

class BuyableScrollAreaMain : public BuyableScrollArea{
public:
    void Populate();

    BuyableScrollAreaMain(QScrollArea *scrollArea);
    BuyableScrollAreaMain();
};

#endif // OOP_PROJECT_BUYABLESCROLLAREAMAIN_H
