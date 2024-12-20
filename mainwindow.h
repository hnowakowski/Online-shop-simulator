#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Headers/CustomWidgets/BuyableScrollAreaMain.h"

#ifdef DEBUG
#define PATH (std::filesystem::current_path().string() + "\\..\\..\\")
#else
#define PATH ""
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBoxSearch_currentIndexChanged(int index);

    void on_btnSearch_clicked();

    void on_radioSortName_clicked();

    void on_radioSortPrice_clicked();

    void on_radioRating_clicked();

    void UpdateCartLabel();

private:
    Ui::MainWindow *ui;
    BuyableScrollAreaMain mainScrollArea;
};
#endif // MAINWINDOW_H
