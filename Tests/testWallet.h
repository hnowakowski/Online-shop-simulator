#ifndef TESTWALLET_H
#define TESTWALLET_H

#include <QTest>
#include "../project/Abstracts/MoneyPossesive.h"
#include "../project/Classes/Price.h"
#include "../project/Classes/Wallet.h"

class TestWallet : public QObject
{
    Q_OBJECT

private slots:
    void subtractPriceFromWalletNormal();
    void subtractPriceFromWalletSubCarry();
    void subtractPriceHigherThanWalletNormal();
    void subtractPriceHigherThanWalletSubLess();
    void priceWalletGTECompareNormal();
    void priceWalletGTECompareMainEq();
    void priceWalletLTCompareNormal();
    void priceWalletLTCompareMainEq();
};

#endif // TESTWALLET_H
