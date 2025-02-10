#include <iostream>
#include <vector>
#include <string>
#include "MerkelMain.h"
#include "CSVReader.h"


int main()
{
    MerkelMain app;
    app.init();
}



//CSVReader::CSVReader();
//Wallet wallet;
    /*std::cout << "Insert currency BTC of amount 10" << std::endl;*/
    /*wallet.insertCurrency("BTC", 10);
    std::cout << wallet.toString() << std::endl;*/
    /*std::cout << "Insert currency USDT of amount 10000" << std::endl;
    wallet.insertCurrency("USDT", 10000);
    std::cout << wallet.toString() << std::endl;
    std::cout << "Insert currency BTC of amount 90" << std::endl;
    wallet.insertCurrency("BTC", 90);
    std::cout << wallet.toString() << std::endl;
    std::cout << "Insert currency USDT of amount -10" << std::endl;
    wallet.insertCurrency("USDT", -10);
    std::cout << wallet.toString() << std::endl;*/

    /*std::cout << "Remove currency USDT of amount 10" << std::endl;
    std::cout << "Function returns: " << wallet.removeCurrency("USDT", 10) << std::endl;
    std::cout << wallet.toString() << std::endl;
    std::cout << "Remove currency BTC of amount 5" << std::endl;
    std::cout << "Function returns: " << wallet.removeCurrency("BTC", 5) << std::endl;
    std::cout << wallet.toString() << std::endl;
    std::cout << "Remove currency BTC of amount -10" << std::endl;
    std::cout << "Function returns: " << wallet.removeCurrency("BTC", -10) << std::endl;
    std::cout << wallet.toString() << std::endl;*/

    /*std::cout << "Remove currency BTC of amount 81" << std::endl;
    std::cout << "Function returns: " << wallet.containsCurrency("BTC", 81) << std::endl;
    std::cout << wallet.toString() << std::endl;
    std::cout << "Remove currency BTC of amount 101" << std::endl;
    std::cout << "Function returns: " << wallet.containsCurrency("BTC", 101) << std::endl;
    std::cout << wallet.toString() << std::endl;*/


    //wallet.removeCurrency("USDT", 1000);
    //std::cout << wallet.toString() << std::endl;
    //// Then we can access the data for printing:
    //for (OrderBookEntry& e : entries){
    //    std::cout << e.price << std::endl;
    //}
    //
    //// Print the average price
    //double av_price = computeAveragePrice(entries);
    //std::cout << "The average price is: " << av_price << std::endl;

    //// Print lowest average price
    //double low_price = computeLowPrice(entries);
    //std::cout << "The lowest price is: " << low_price << std::endl;

    //// Print highest average price
    //double high_price = computeHighPrice(entries);
    //std::cout << "The highest price is: " << high_price << std::endl;

    //// Print spread average price
    //double price_spread = computePriceSpread(entries);
    //std::cout << "The price-spread is: " << price_spread << std::endl;