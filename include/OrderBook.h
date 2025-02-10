#pragma once

#include <string>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook {

public:
	/** Construct, reading a csv data file*/
	OrderBook(std::string filename);
	/** return a vector of all known products in the dataset*/
	std::vector<std::string> getKnownProducts();
	/** return vector of Orders according to the sent filters*/
	std::vector<OrderBookEntry> getOrders(OrderBookType type,
										std::string product,
										std::string timestamp);

	/** returns the earliest time in the orderbook*/
	std::string getEarliestTime();
	/** return the next time after the sent time in the orderbook
	 *If there is no next timestap, wraps around to the start*/
	std::string getNextTime(std::string timestamp);

	void insertOrder(OrderBookEntry& order);

	std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

	// Metrics used
	static double getLowPrice(std::vector<OrderBookEntry>& orders);
	static double getHighPrice(std::vector<OrderBookEntry>& orders);
	static double getAveragePrice(std::vector<OrderBookEntry>& orders);
	static double getPriceSpread(std::vector<OrderBookEntry>& orders);


private:
	std::vector<OrderBookEntry> orders;
};