#pragma once

#include<vector>
#include<string>
#include "OrderBookEntry.h"

class CSVReader{

public:
	CSVReader();

	static std::vector<OrderBookEntry> readCSV(std::string csvFile);
	static std::vector<std::string> tokenise(std::string csvLine, char separator);
	static OrderBookEntry stringToOBE(std::string price, std::string amount, std::string timestamp, std::string product, OrderBookType ordertype);


private:
	static OrderBookEntry stringToOBE(std::vector<std::string> strings);
};
