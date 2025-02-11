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
    ${CMAKE_SOURCE_DIR}/data
)

# Copy the data folder to the build directory
add_custom_command(
    TARGET trade_market POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            ${CMAKE_BINARY_DIR}/data
)

# Copy the bin folder to the root folder
add_custom_command(
    TARGET trade_market POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_BINARY_DIR}/bin
            ${CMAKE_SOURCE_DIR}/bin
)
