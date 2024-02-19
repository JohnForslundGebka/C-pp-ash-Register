// ==============================================================================
// main.cpp
// Entry point for the Inventory Management System application.
//
// This application provides a console-based interface for managing a store's
// inventory, including books, clothing, and laptops. It demonstrates usage of
// object-oriented programming principles, database integration with SQLiteCpp,
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================

// Local project headers
#include "menu.h"
#include "menuFunction.h"

int main()
{
    // Creating menus and submenu objects. Class is located in menu.h
    Menu mainMenu;
    Menu manageProducts;
    Menu sale;
    Menu transactions;

    //Adding pointers to menu objects
    mainMenu.addSubMenu("Manage Products", &manageProducts);
    mainMenu.addSubMenu("Make A Sale", &sale);
    mainMenu.addSubMenu("Transaction History",&transactions);

    //Different functions that exists as menu options, make a sale for example
    //can be found in menuFunction.h
    manageProducts.addMenuFunction("See Article Info",MenuFunction::printArticleInfo);
    sale.addMenuFunction("Make a sale",MenuFunction::sale);
    transactions.addMenuFunction("Transaction History",MenuFunction::manageTransactions);

    //Call the run function in the menu object
    mainMenu.run();

}