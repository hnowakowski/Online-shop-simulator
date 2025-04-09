#include <QCoreApplication>
#include <QTest>

#include "testLoaderSaver.h"
#include "testWallet.h"

int main(int argc, char* argv[])
{
    int status = 0;
    QCoreApplication app(argc, argv);

    {
        TestWallet testWallet;
        status |= QTest::qExec(&testWallet, argc, argv);
    }

    {
        TestLoaderSaver testLoaderSaver;
        status |= QTest::qExec(&testLoaderSaver, argc, argv);
    }

    return status;
}
