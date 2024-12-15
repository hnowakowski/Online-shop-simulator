#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "../Headers/Core/Product.h"
#include "Interfaces/DynamicWidget.h"

class BuyableScrollArea : public DynamicWidget{
protected:
    std::vector<std::shared_ptr<Product>> products;
    QScrollArea *scrollArea;

public:
    virtual void Populate() = 0;

    BuyableScrollArea(QScrollArea *scrollArea, std::vector<std::shared_ptr<Product>> products);
};
