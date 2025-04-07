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
        testFiles.cpp \
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
        testFiles.h \
        testWallet.h

INCLUDEPATH += $$PWD/../project

# test wallet <-> price conversion
# test subtracting price from wallet
# test some edgecases
# file read/write (same thing as on startup)
