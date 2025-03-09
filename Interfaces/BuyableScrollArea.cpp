#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "BuyableScrollArea.h"

BuyableScrollArea::BuyableScrollArea(QScrollArea *scrollArea)
    : scrollArea(scrollArea) {};

BuyableScrollArea::BuyableScrollArea()
    : scrollArea(nullptr) {};
