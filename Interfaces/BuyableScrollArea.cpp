#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "BuyableScrollArea.h"

BuyableScrollArea::BuyableScrollArea(QScrollArea *scrollArea) : scrollArea(scrollArea) {};
BuyableScrollArea::BuyableScrollArea() : scrollArea(nullptr) {};
