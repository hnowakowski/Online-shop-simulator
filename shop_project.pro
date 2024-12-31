QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

debug: DEFINES += DEBUG #comment this out when the project is finished

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/BuyableScrollAreaCart.cpp \
    Classes/BuyableScrollAreaCheckout.cpp \
    Classes/Price.cpp \
    Classes/Product.cpp \
    Classes/Service.cpp \
    Classes/Cart.cpp \
    Classes/Clothing.cpp \
    Classes/Customer.cpp \
    Classes/Order.cpp \
    Classes/Wallet.cpp \
    Classes/AddressLineEdit.cpp \
    Classes/BuyableScrollAreaMain.cpp \
    Classes/StoreSystem.cpp \
    Interfaces/Buyable.cpp \
    Interfaces/BuyableScrollArea.cpp \
    Interfaces/MoneyPossesive.cpp \
    main.cpp \
    pageCart.cpp \
    pageCheckout.cpp \
    pageLogin.cpp \
    pageMain.cpp \
    pageSignUp.cpp

HEADERS += \
    Classes/BuyableScrollAreaCart.h \
    Classes/BuyableScrollAreaCheckout.h \
    Enums/BuyableDisplayedType.h \
    Enums/BuyableSortedBy.h \
    Enums/BuyableSortedBy.h \
    Enums/Color.h \
    Enums/ServiceType.h \
    Classes/Price.h \
    Classes/Product.h \
    Classes/Service.h \
    Classes/AddressLineEdit.h \
    Classes/BuyableScrollAreaMain.h \
    Classes/Cart.h \
    Classes/Clothing.h \
    Classes/Customer.h \
    Classes/Order.h \
    Classes/Wallet.h \
    Classes/StoreSystem.h \
    Interfaces/Buyable.h \
    Interfaces/BuyableScrollArea.h \
    Interfaces/DynamicWidget.h \
    Interfaces/MoneyPossesive.h \
    Interfaces/Serializable.h \
    Templates/Listing.h \
    Templates/LoaderSaver.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
