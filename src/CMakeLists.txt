# Create a library or executable
add_executable(trade_market
    main.cpp
    CSVReader.cpp
    MerkelMain.cpp
    OrderBook.cpp
    OrderBookEntry.cpp
    Wallet.cpp
)

# Public headers (exposed to users of the library)
target_include_directories(trade_market
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)