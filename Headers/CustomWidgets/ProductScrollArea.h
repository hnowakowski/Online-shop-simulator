#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "../Core/Product.h"
#include "../../Interfaces/DynamicWidget.h"

class ProductScrollArea : public DynamicWidget{
protected:
    std::vector<std::shared_ptr<Product>> products;
    QScrollArea *scrollArea;

public:
    void Populate();

    ProductScrollArea(QScrollArea *scrollArea, std::vector<std::shared_ptr<Product>> products);
};
