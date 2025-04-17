QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/CartItem.cpp \
    Classes/ItemScrollAreaCart.cpp \
    Classes/ItemScrollAreaCheckout.cpp \
    Classes/ItemScrollAreaMain.cpp \
    Classes/Price.cpp \
    Classes/Product.cpp \
    Classes/Service.cpp \
    Classes/Cart.cpp \
    Classes/Clothing.cpp \
    Classes/Customer.cpp \
    Classes/Wallet.cpp \
    Classes/StoreSystem.cpp \
    Abstracts/Buyable.cpp \
    Abstracts/MoneyPossesive.cpp \
    main.cpp \
    Pages/pageCart.cpp \
    Pages/pageCheckout.cpp \
    Pages/pageLogin.cpp \
    Pages/pageMain.cpp \
    Pages/pageSignUp.cpp

HEADERS += \
    Classes/CartItem.h \
    Classes/ItemScrollAreaCart.h \
    Classes/ItemScrollAreaCheckout.h \
    Classes/ItemScrollAreaMain.h \
    Enums/BuyableDisplayedType.h \
    Enums/BuyableSortedBy.h \
    Enums/BuyableSortedBy.h \
    Enums/Color.h \
    Enums/ServiceType.h \
    Classes/Price.h \
    Classes/Product.h \
    Classes/Service.h \
    Classes/Cart.h \
    Classes/Clothing.h \
    Classes/Customer.h \
    Classes/Wallet.h \
    Classes/StoreSystem.h \
    Abstracts/Buyable.h \
    Abstracts/MoneyPossesive.h \
    Abstracts/Serializable.h \
    Templates/ItemScrollArea.h \
    Templates/LoaderSaver.h \
    mainwindow.h \

FORMS += \
    mainwindow.ui

RC_FILE = icon_resource.rc

INCLUDEPATH += $$PWD/ExternalLibs/libsodium/include

LIBS += -L$$PWD/ExternalLibs/libsodium/lib -lsodium

CONFIG(debug, debug|release) {
    DLL_DEST = \"$$OUT_PWD\\debug\\libsodium-23.dll\"
} else {
    DLL_DEST = \"$$OUT_PWD\\release\\libsodium-23.dll\"
}

copy_dll.target = copy_dll
copy_dll.commands = cmd /C copy /Y \"$$PWD\\ExternalLibs\\libsodium\\bin\\libsodium-23.dll\" $$DLL_DEST
QMAKE_EXTRA_TARGETS += copy_dll
POST_TARGETDEPS += copy_dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
