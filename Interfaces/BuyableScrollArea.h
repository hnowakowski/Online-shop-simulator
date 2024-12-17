#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "Buyable.h"
#include "Interfaces/DynamicWidget.h"

class BuyableScrollArea : public DynamicWidget{
protected:
    QScrollArea *scrollArea;

public:
    virtual void Populate() = 0;

    BuyableScrollArea(QScrollArea *scrollArea);
};
