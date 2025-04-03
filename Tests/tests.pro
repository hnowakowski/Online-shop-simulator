QT += testlib gui widgets
CONFIG += qt warn_on testcase console

TEMPLATE = app

SOURCES += testTest.cpp \
        ../project/Classes/Product.cpp \
        ../project/Classes/Price.cpp \
        ../project/Abstracts/Buyable.cpp \
        ../project/Abstracts/MoneyPossesive.cpp \
        ../project/Classes/Clothing.cpp \
        ../project/Classes/Service.cpp \

HEADERS += testTest.h \
        ../project/Classes/Product.h \
        ../project/Classes/Price.h \
        ../project/Abstracts/Buyable.h \
        ../project/Abstracts/MoneyPossesive.h \
        ../project/Classes/Clothing.h \
        ../project/Classes/Service.h \


INCLUDEPATH += $$PWD/../project
