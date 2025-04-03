#ifndef TESTTEST_H
#define TESTTEST_H

#include <QTest>

class TestTest : public QObject
{
    Q_OBJECT

private slots:
    void testTest();
    void productTest();
};

#endif // TESTTEST_H
