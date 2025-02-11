# Trade Market Simulator

This repository contains the implementation of a **Trade Market Simulator**, a project developed as part of the University of London's [Object-Oriented Programming Specialization](https://www.coursera.org/specializations/object-oriented-programming-s12n) on Coursera. The simulator demonstrates key object-oriented programming concepts and provides a practical application for trading market simulations.

## Features

- **CSV Reader**: Reads and processes market data from CSV files.
- **Order Book**: Manages buy and sell orders, allowing users to view market trends and trade efficiently.
- **Wallet**: Tracks the user's balance and handles transactions.
- **Interactive Command Interface**: Allows users to interact with the market by entering commands.

## File Structure

- `src/`: Contains the C++ source files.
- `include/`: Contains the header files.
- `scripts/`: Contains utility scripts, including a `.bat` file for building the project.
- `data/`: Includes sample CSV files for testing.

## Requirements

- A C++ compiler supporting C++14 or later.
- CMake version 3.16.1 or higher.
- Windows environment for running the provided `.bat` file.

## Build and Run Instructions

1. Clone the repository:
   
   ```bash
   git clone https://github.com/hmatoui/trade-market-cpp.git
   cd trade-market-cpp
   ```

2. Navigate to the `scripts` folder:
   
   ```bash
   cd scripts
   ```

3. Run the build script:
   
   ```bash
   build_win_x86_64.bat
   ```
   
   This script will:
   
   - Create a `build/` and `bin/` directory in the project root.
   - Configure and generate build files using CMake.
   - Compile the project into the `bin/Release` folder.

4. Run the executable:
   Navigate to the `bin/Release` directory and run `trade_market.exe`:
   
   ```cmd
   cd ../bin/Release
   trade_market.exe
   ```

## Running the Executable

After successfully building the project, you can run the `trade_market.exe` executable. Upon running, you will see the following menu:

```plaintext
1: Print help
2: Print exchange stats
3: Place an ask
4: Place a bid
5: Print wallet
6: Continue
=====================
Current time is: 2020/03/17 17:01:24.884492
Type in 1-6
```

### Menu Options Summary

1. **Print Help**: Instructions on using the app.
2. **Print Exchange Stats**: Displays market data (prices, trends, volumes).
3. **Place an Ask**: Create a sell order with a specified price and product.
4. **Place a Bid**: Create a buy order with a specified price and product.
5. **Print Wallet**: Shows your asset balances and updates from trades.
6. **Continue**: Advances the simulation, processes orders, and updates stats.
