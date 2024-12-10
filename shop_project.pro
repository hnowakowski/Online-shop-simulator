QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/Core/Currency.cpp \
    Classes/Core/Price.cpp \
    Classes/Core/Product.cpp \
    Classes/Core/Service.cpp \
    Classes/Domain/Cart.cpp \
    Classes/Domain/Clothing.cpp \
    Classes/Domain/Customer.cpp \
    Classes/Domain/Order.cpp \
    Classes/Domain/Wallet.cpp \
    Classes/System/StoreSystem.cpp \
    Interfaces/Buyable.cpp \
    Interfaces/MoneyPossesive.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Enums/Color.h \
    Enums/ServiceType.h \
    Headers/Core/Currency.h \
    Headers/Core/Price.h \
    Headers/Core/Product.h \
    Headers/Core/Service.h \
    Headers/Domain/Cart.h \
    Headers/Domain/Clothing.h \
    Headers/Domain/Customer.h \
    Headers/Domain/Order.h \
    Headers/Domain/Wallet.h \
    Headers/System/StoreSystem.h \
    Interfaces/Buyable.h \
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
