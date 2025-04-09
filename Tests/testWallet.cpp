#include <testWallet.h>

void TestWallet::subtractPriceFromWalletNormal()
{
    Price pr(2, 30);
    Wallet wl(3, 40);
    wl.subtractMain(pr.getMainUnit());
    wl.subtractSub(pr.getSubUnit());
    QCOMPARE(wl.getMainUnit(), 1);
    QCOMPARE(wl.getSubUnit(), 10);
}
void TestWallet::subtractPriceFromWalletSubCarry()
{
    Price pr(2, 50);
    Wallet wl(3, 40);
    wl.subtractMain(pr.getMainUnit());
    wl.subtractSub(pr.getSubUnit());
    QCOMPARE(wl.getMainUnit(), 0);
    QCOMPARE(wl.getSubUnit(), 90);
}

void TestWallet::subtractPriceHigherThanWalletNormal()
{
    Price pr(4, 50);
    Wallet wl(3, 40);
    wl.subtractMain(pr.getMainUnit());
    wl.subtractSub(pr.getSubUnit());
    QCOMPARE(wl.getMainUnit(), 0);
    QCOMPARE(wl.getSubUnit(), 0);
}
void TestWallet::subtractPriceHigherThanWalletSubLess()
{
    Price pr(4, 30);
    Wallet wl(3, 40);
    wl.subtractMain(pr.getMainUnit());
    wl.subtractSub(pr.getSubUnit());
    QCOMPARE(wl.getMainUnit(), 0);
    QCOMPARE(wl.getSubUnit(), 0);
}
void TestWallet::priceWalletGTECompareNormal()
{
    Price pr(2, 50);
    Wallet wl(3, 40);
    QVERIFY(wl >= pr);
}
void TestWallet::priceWalletGTECompareMainEq()
{
    Price pr(3, 30);
    Wallet wl(3, 40);
    QVERIFY(wl >= pr);
}

void TestWallet::priceWalletLTCompareNormal()
{
    Price pr(2, 50);
    Wallet wl(3, 40);
    QVERIFY(pr < wl);
}
void TestWallet::priceWalletLTCompareMainEq()
{
    Price pr(3, 30);
    Wallet wl(3, 40);
    QVERIFY(pr < wl);
}
