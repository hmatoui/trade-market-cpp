#include <iostream>
#include "MerkelMain.h"
#include "CSVReader.h"

MerkelMain::MerkelMain() {}

void MerkelMain::init() {
	int userOption;
	//loadOrderBook();
	currentTime = orderBook.getEarliestTime();

	wallet.insertCurrency("BTC", 10);

	while (true) {
		printMenu();
		userOption = getUserOption();
		processUserOption(userOption);
	}
}

//void MerkelMain::loadOrderBook(){
//    // Construct orders
//    orders = CSVReader::readCSV("20200317.cv");
//}

void MerkelMain::printMenu() {
	std::cout << "1: Print help" << std::endl;

	std::cout << "2: Print exchange stats" << std::endl;

	std::cout << "3: Place an ask" << std::endl;

	std::cout << "4: Place a bid" << std::endl;

	std::cout << "5: Print wallet" << std::endl;

	std::cout << "6: Continue" << std::endl;

	std::cout << "=====================" << std::endl;

	std::cout << "Current time is: " << currentTime << std::endl;
}

int MerkelMain::getUserOption() {

	std::cout << "Type in 1-6" << std::endl;
	int userOption=0;
	std::string line;
	std::getline(std::cin,line);
	try {
		userOption = stoi(line);
	}
	catch (const std::exception& e) {
		//
	}
	std::cout << "You chose: " << userOption << std::endl;

	return userOption;
}

void MerkelMain::printHelp() {
	std::cout << "Help - choose options from the menu" << std::endl;
	std::cout << "and follow the on screen instructions." << std::endl;
}
void MerkelMain::printMarketStats() {

	for (std::string const& p : orderBook.getKnownProducts()) {
		std::cout << "Product: " << p << std::endl;
		std::vector<OrderBookEntry> ask_entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
		std::cout << "Asks seen: " << ask_entries.size() << std::endl;
		std::cout << "Max ask: " << OrderBook::getHighPrice(ask_entries) << std::endl;
		std::cout << "Min ask: " << OrderBook::getLowPrice(ask_entries) << std::endl;
		std::cout << "Average ask: " << OrderBook::getAveragePrice(ask_entries) << std::endl;
		std::cout << "Price spread ask: " << OrderBook::getPriceSpread(ask_entries) << std::endl;

		std::vector<OrderBookEntry> bid_entries = orderBook.getOrders(OrderBookType::bid, p, currentTime);
		std::cout << "Bids seen: " << bid_entries.size() << std::endl;
		std::cout << "Max bid: " << OrderBook::getHighPrice(bid_entries) << std::endl;
		std::cout << "Min bid: " << OrderBook::getLowPrice(bid_entries) << std::endl;
		std::cout << "Average bid: " << OrderBook::getAveragePrice(bid_entries) << std::endl;
		std::cout << "Price spread bid: " << OrderBook::getPriceSpread(bid_entries) << std::endl;

	}
	/*std::cout << "The order contains: " << orders.size() << " entries" << std::endl;
	unsigned int bids = 0;
	unsigned int asks = 0;
	for (OrderBookEntry& e : orders) {
		if (e.ordertype == OrderBookType::ask) {
			asks++;
		}
		if (e.ordertype == OrderBookType::bid) {
			bids++;
		}
	}
	std::cout << "OrderBook asks: " << asks << ", bids: " << bids << std::endl;*/
}
void MerkelMain::enterAsk() {
	std::cout << "Mark an offer - enter data as: product,price,amount. eg: ETH/BTC,200,0.5" << std::endl;
	std::string input;
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);

	std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
	if (tokens.size() != 3) {
		std::cout << "MerkelMain::enterAsk: Bad input! " << input << std::endl;
	}
	else {
		try {
			OrderBookEntry obe = CSVReader::stringToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
			obe.username = "simuser";
			if (wallet.canFulfillOrder(obe)) {
				std::cout << "Wallet looks good. " << std::endl;
				orderBook.insertOrder(obe);
			}
			else {
				std::cout << "Wallet has insufficient funds. " << std::endl;
			}
		}catch(const std::exception& e){
			std::cout << "MerkelMain::enterAsk: Bad input! " << input << std::endl;
		}
	}

	std::cout << "You typed: " << input << std::endl;
}
void MerkelMain::enterBid() {
	std::cout << "Make a bid - enter data as: product,price,amount. eg: ETH/BTC,200,0.5" << std::endl;
	std::string input;
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);

	std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
	if (tokens.size() != 3) {
		std::cout << "MerkelMain::enterBid: Bad input! " << input << std::endl;
	}
	else {
		try {
			OrderBookEntry obe = CSVReader::stringToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
			obe.username = "simuser";
			if (wallet.canFulfillOrder(obe)) {
				std::cout << "Wallet looks good. " << std::endl;
				orderBook.insertOrder(obe);
			}
			else {
				std::cout << "Wallet has insufficient funds. " << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cout << "MerkelMain::enterBid: Bad input! " << input << std::endl;
		}
	}

	std::cout << "You typed: " << input << std::endl;
}
void MerkelMain::printWallet() {
	std::cout << wallet << std::endl;
}
void MerkelMain::goToNextTimeFrame() {
	std::cout << "Going to the next time frame." << std::endl;
	std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
	std::cout << "Sales: " << sales.size() << std::endl;
	for (OrderBookEntry& sale : sales) {
		std::cout << "Sale price: " << sale.price << ", amount: " << sale.amount << std::endl;
		if (sale.username == "simuser") { // update the wallet
			wallet.processSale(sale);
		}
	}
	currentTime = orderBook.getNextTime(currentTime);
}
void MerkelMain::printWarning() {
	std::cout << "Invalid input choice" << std::endl;
}

void MerkelMain::processUserOption(int userOption) {
	if (userOption == 1) {
		printHelp();
	}
	if (userOption == 2) {
		printMarketStats();
	}
	if (userOption == 3) {
		enterAsk();
	}
	if (userOption == 4) {
		enterBid();
	}
	if (userOption == 5) {
		printWallet();
	}
	if (userOption == 6) {
		goToNextTimeFrame();
	}
	if (userOption < 1 || userOption > 6) {
		printWarning();
	}
}