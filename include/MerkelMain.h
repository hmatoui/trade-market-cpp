#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"


class MerkelMain{
    
public:
    MerkelMain();
    void init();

private:
    //void loadOrderBook();
    void printMenu();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void goToNextTimeFrame();
    void printWarning();
    void processUserOption(int userOption);

    std::string currentTime;
    OrderBook orderBook{"20200317.csv"};
    Wallet wallet;
};