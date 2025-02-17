# ATM Controller with Bank API

## Overview:
An ATM simulator that connects to dummy bank API to do user authentication, account management, and basic transactions.

## Key Components:
- Account: Represents a bank account with operations.
- BankAPI: Validates user authentication, account search, and process transactions.
- ATM: A central interface that manages user interactions, including inserting card, entering PIN, selecting an account, checking balance, and withdrawing funds.

## Features:
- Card insertion
- PIN authentication
- Check account balance
- Make deposit
- Make withdrawal

## INSTALLATION INSTRUCTIONS
### Prerequisistes:
- C++ compiler (GCC, Clang)
- CMake
- GoogleTest for unit testing

### How to Clone:
```
  git clone git@github.com:William0614/ATM-controller.git
  cd ATM-controller
```

### BUILD INSTRUCTIONS:
```
  mkdir build
  cd builld
  cmake ..
  make
```

###To RUN:
1. Run the compiled executable: ```./ATM```
2. Insert card and verify PIN
3. Select an account.
4. Perform transactions
5. Eject the card when done.

###Testing:
Run unit tests:
```./runTests```
