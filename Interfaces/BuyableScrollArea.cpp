#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "BuyableScrollArea.h"

BuyableScrollArea::BuyableScrollArea(QScrollArea *scrollArea, std::vector<std::shared_ptr<Buyable>> buyables) : buyables(buyables), scrollArea(scrollArea) {};

