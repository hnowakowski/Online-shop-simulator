#include <QTest>
#include <../project/Classes/Product.h>
#include <testTest.h>

void TestTest::testTest()
{
    int32_t a = 1;
    a += 1;
    QCOMPARE(a, 2);
}

void TestTest::productTest()
{
    std::shared_ptr<Price> price = std::make_shared<Price>(3, 3);
    Product p("P0", "testprod", "testprod", "", "100/10", 300, price);
    QCOMPARE(p.getName(), "testprod");
}

QTEST_MAIN(TestTest)
