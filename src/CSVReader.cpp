#include<iostream>
#include<fstream>
#include "CSVReader.h"

CSVReader::CSVReader() {

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName) {
	std::vector<OrderBookEntry> entries;

	std::ifstream csvFile(csvFileName);
	std::string line;

	if (csvFile.is_open()) {
		std::cout << "File open" << std::endl;

		while (std::getline(csvFile, line)) {
			try {
				OrderBookEntry obe = stringToOBE(tokenise(line, ','));
				entries.push_back(obe);
			}
			catch (const std::exception& e) {
				std::cout << "CSVReader::readCSV bad data" << std::endl;
			}
		}
	}

	std::cout << "CSVReader::readCSV read " << entries.size() << " entries" << std::endl;
	return entries;
}


std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator) {
	std::vector<std::string> tokens;
	signed int start, end;
	std::string token;

	start = csvLine.find_first_not_of(separator, 0);

	do {
		end = csvLine.find_first_of(separator, start);
		if (start == csvLine.length() || start == end) break;
		if (end >= 0) token = csvLine.substr(start, end - start);
		else token = csvLine.substr(start, csvLine.length() - start);
		tokens.push_back(token);
		start = end + 1;
	} while (end != std::string::npos);

	return tokens;

}


OrderBookEntry CSVReader::stringToOBE(std::vector<std::string> tokens) {

	std::string timestamp;
	std::string product;
	OrderBookType ordertype;
	double price;
	double amount;

	if (tokens.size() != 5) {
		std::cout << "Bad line" << std::endl;
		throw std::exception();
	}
	try {
		timestamp = tokens[0];
		product = tokens[1];
		ordertype = OrderBookEntry::stringToBookType(tokens[2]);
		price = std::stod(tokens[3]);
		amount = std::stod(tokens[4]);

		/*std::cout << "timestamp: " << timestamp << std::endl;
		std::cout << "product: " << product << std::endl;
		std::cout << "ordertype: " << tokens[2] << std::endl;
		std::cout << "price: " << price << std::endl;
		std::cout << "amount: " << amount << std::endl;*/

	}
	catch (const std::exception& e) {
		std::cout << "Bad data! " << std::endl;
		throw e;
	}

	OrderBookEntry obe{ price,amount,timestamp,product,ordertype };

	return obe;
}

OrderBookEntry CSVReader::stringToOBE(std::string _price, std::string _amount, std::string _timestamp, std::string _product, OrderBookType _ordertype) {
	double price, amount;
	try {
		price = std::stod(_price);
		amount = std::stod(_amount);
	}
	catch (const std::exception& e) {
		std::cout << "CSVReader::stringToOBE: Bad data! " << std::endl;
		throw e;
	}

	OrderBookEntry obe{ price,amount,_timestamp,_product,_ordertype };

	return obe;

}