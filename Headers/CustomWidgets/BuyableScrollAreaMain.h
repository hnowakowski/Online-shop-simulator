#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "../../Interfaces/Buyable.h"
#include "../../Interfaces/BuyableScrollArea.h"

class BuyableScrollAreaMain : public BuyableScrollArea{
public:
    void Populate();

    BuyableScrollAreaMain(QScrollArea *scrollArea);
};

