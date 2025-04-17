QT += testlib gui widgets
CONFIG += qt warn_on testcase console

TEMPLATE = app

SOURCES += \
        ../project/Classes/Product.cpp \
        ../project/Classes/Price.cpp \
        ../project/Abstracts/Buyable.cpp \
        ../project/Abstracts/MoneyPossesive.cpp \
        ../project/Classes/Clothing.cpp \
        ../project/Classes/Service.cpp \
        ../project/Classes/StoreSystem.cpp \
        ../project/Classes/Cart.cpp \
        ../project/Classes/Customer.cpp \
        ../project/Classes/CartItem.cpp \
        ../project/Classes/Wallet.cpp \
        ../project/Classes/ItemScrollAreaMain.cpp \
        testLoaderSaver.cpp \
        testMain.cpp \
        testWallet.cpp

HEADERS += \
        ../project/Classes/Product.h \
        ../project/Classes/Price.h \
        ../project/Abstracts/Buyable.h \
        ../project/Abstracts/MoneyPossesive.h \
        ../project/Classes/Clothing.h \
        ../project/Classes/Service.h \
        ../project/Classes/StoreSystem.h \
        ../project/Classes/Cart.h \
        ../project/Classes/Customer.h \
        ../project/Classes/CartItem.h \
        ../project/Classes/Wallet.h \
        ../project/Classes/ItemScrollAreaMain.h \
        ../project/Templates/ItemScrollArea.h \
        ../project/Enums/BuyableDisplayedType.h \
        ../project/Enums/BuyableSortedBy.h \
        ../project/Enums/BuyableSortedBy.h \
        ../project/Enums/Color.h \
        ../project/Enums/ServiceType.h \
        testLoaderSaver.h \
        testWallet.h




INCLUDEPATH += $$PWD/../project \
               $$PWD/../project/ExternalLibs/libsodium/include

LIBS += -L$$PWD/../project/ExternalLibs/libsodium/lib -lsodium

CONFIG(debug, debug|release) {
    DLL_DEST = \"$$OUT_PWD\\debug\\libsodium-23.dll\"
} else {
    DLL_DEST = \"$$OUT_PWD\\release\\libsodium-23.dll\"
}

copy_dll.target = copy_dll
copy_dll.commands = cmd /C copy /Y \"$$PWD\\..\\project\\ExternalLibs\\libsodium\\bin\\libsodium-23.dll\" $$DLL_DEST
QMAKE_EXTRA_TARGETS += copy_dll
POST_TARGETDEPS += copy_dll
