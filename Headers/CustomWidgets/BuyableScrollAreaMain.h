#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "../Core/Product.h"
#include "../../Interfaces/BuyableScrollArea.h"

class BuyableScrollAreaMain : public BuyableScrollArea{
public:
    void Populate();

    BuyableScrollAreaMain(QScrollArea *scrollArea, std::vector<std::shared_ptr<Product>> products);
};

