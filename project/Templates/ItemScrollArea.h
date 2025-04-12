#ifndef ITEMSCROLLAREA_H
#define ITEMSCROLLAREA_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

template<typename T>
class ItemScrollArea
{
protected:
    QScrollArea *scrollArea;

    std::shared_ptr<std::vector<std::pair<std::shared_ptr<T>, QWidget *>>> itemWidgets;

    virtual void clearArea()
    {
        QWidget *container = scrollArea->widget();
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());
        while (QLayoutItem *item = layout->takeAt(0)) {
            delete item->widget();
            delete item;
        }
    }

    virtual void populateItems() = 0;

    virtual void generatePanel(std::shared_ptr<T> &item) = 0;

public:
    virtual void displayItems() = 0;

    void populate()
    {
        QWidget *container = scrollArea->widget();
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());

        if (!layout) {
            layout = new QVBoxLayout(container);
            container->setLayout(layout);
        }

        clearArea();
        populateItems();
    }

    ItemScrollArea(QScrollArea *scrollArea)
        : scrollArea(scrollArea)
    {
        itemWidgets = std::make_shared<std::vector<std::pair<std::shared_ptr<T>, QWidget *>>>();
    }

    ItemScrollArea() { itemWidgets = std::make_shared<std::vector<std::pair<std::shared_ptr<T>, QWidget *>>>(); }

    virtual ~ItemScrollArea() = default;
};
#endif // ITEMSCROLLAREA_H
